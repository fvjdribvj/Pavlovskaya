#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("input.dat");
    vector<string> file;
    while(!fin.eof())
    {
        string tempSlovo;
        fin >> tempSlovo;
        cout << tempSlovo << ' ';
        file.push_back(tempSlovo);
    }
    int kolvoSlov=0, kolvoPredl=0;
    cout << endl;
    for(unsigned int i=0; i<file.size(); i++)
    {
        kolvoSlov++;
        string tmp = file[i];
        if(tmp.back()=='.')
        {
            kolvoPredl++;
            cout << "V " << kolvoPredl << " slov " <<kolvoSlov << endl;
            kolvoSlov=0;
        }
    }
    cout << "Vsevo " << kolvoPredl << " Predlozenii " << endl;
    string tmp;
    cin >> tmp;
    kolvoPredl=0;
    kolvoSlov=0;
    for(unsigned int i=0; i<file.size(); i++)
    {
        string tmp = file[i];
        if(tmp.back()=='.')
         {
            kolvoPredl++;
            cout << "Predlozenie " << kolvoPredl << endl;
            for(unsigned int iter = kolvoSlov; iter<i+1;iter++)
            {
                cout << file[iter] << ' ';
            }
            cout << endl << "Poslovno: " << endl;
            for(unsigned int iter = kolvoSlov; iter<i+1;iter++)
            {
                cout << iter-kolvoSlov+1 << ')' << file[iter] << endl;
            }
            kolvoSlov=i+1;
        }
    }
    fin.close();
    file.clear();
    return 0;
}