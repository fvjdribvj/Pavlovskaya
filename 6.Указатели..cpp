#include <iostream>
#include <vector>

using namespace std;

struct MARSH
{
    string start;
    string finish;
    int number;
};

int main()
{
    vector<MARSH> mrsh;
    while (true) {
        MARSH tmp;
        cout << "Start  ";
        cin >> tmp.start;
        cout << "Finish ";
        cin >> tmp.finish;
        cout << "Number ";
        cin >> tmp.number;
        mrsh.push_back(tmp);
        cout<<"Print 0 to close adding, 1 to add more: ";
        int ret;
        cin>>ret;
        if(!ret)
            break;
    }
    int item;
    cout << "Serch num: " << endl;
    cin >> item;
    bool onse=false;
    for (int i = 0; i < mrsh.size(); i++)
    {
        if(item == mrsh[i].number)
        {
            cout << mrsh[i].start << endl;
            cout << mrsh[i].finish << endl;
            cout << mrsh[i].number << endl;
            onse=true;
        }
    }
    if(!onse)
        cout<<"No marshruts winth your number"<<endl;
    return 0;
}