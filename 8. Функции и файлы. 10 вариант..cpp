#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct NOTEBOOK{
    char model[21];
    struct size{
        float x;
        float y;
        float z;
    };
    float w;
    int price;
    size sizenb;
    int chastota;
    int maxOzu;
    float diagonal;
    int razreshenieX;
    int razreshenieY;
    int videopam;
    int fps;
    float hdd;
};

void LoadFromfile(vector<NOTEBOOK> &forLoad)
   {
    ifstream fin("note.txt");
    while(!fin.eof()){
        NOTEBOOK tmp;
        for(int i = 0; i<=21; i++)
            fin>>tmp.model[i];
        fin>>tmp.price;
        fin>>tmp.w;
        string tmpsize;
        fin>>tmpsize;
        string tx,ty,tz;
        for(int i=0; i<=13;i++)
        {
            if(i<34)
                tx+=tmpsize[i];
            if(i>34 && i<39)
                ty+=tmpsize[i];
            if(i>39)
                tz+=tmpsize[i];
        }
        tmp.sizenb.x=atof(tx.c_str());
        tmp.sizenb.y=atof(ty.c_str());
        tmp.sizenb.z=atof(tz.c_str());
        fin>>tmp.chastota;
        fin>>tmp.maxOzu;
        fin>>tmp.diagonal;
        fin>>tmp.videopam;

        fin>>tmpsize;
        for(int i=0; i<=8; i++)
        {
            if(i<4)
                tx+=tmpsize[i];
            if(i>4)
                ty+=tmpsize[i];
        }
        tmp.razreshenieX = atoi(tx.c_str());
        tmp.razreshenieY = atoi(ty.c_str());
        fin>>tmp.fps;
        fin>>tmp.hdd;
        fin.close();
        forLoad.push_back(tmp);
    }
}

void upTobin(vector<NOTEBOOK> &toWrite)
{
    ofstream out("note.bin", ios::binary);
    char yz=(char)toWrite.size();
    out.write((char*)&yz, 2);
    for(int i=0;i<toWrite.size(); i++)
        out.write((char*)&toWrite[i], sizeof(NOTEBOOK));
    out.close();
}

void upTobin150(vector<NOTEBOOK> &toWrite)
    {
    ofstream out("note.bin", ios::binary);
    char yz=(char)toWrite.size();
    out.write((char*)&yz, 2);
    for(int i=0;i<toWrite.size(); i++)
      {
        if(toWrite[i].chastota>150)
            out.write((char*)&toWrite[i], sizeof(NOTEBOOK));
    }
    out.close();
}

struct compare
{
    bool operator()(const NOTEBOOK& nb1, const NOTEBOOK& nb2)
    {
        return nb1.price > nb2.price;
    }
};

int main()
{
    vector<NOTEBOOK> nbAll;
    LoadFromfile(nbAll);
    upTobin(nbAll);
    sort(nbAll.begin(),nbAll.end(),compare());
    upTobin150(nbAll);
    nbAll.clear();
    return 0;
}