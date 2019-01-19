#define n 10
#include<iostream>
#include<cmath>
using namespace std;
int main()
{   
 float arr[n]= {0}; 
 for ( int i=0; i<n; i++) 
 cin>>arr[i];
 float min = abs(arr[0]);
 for ( int i=0; i<n; i++) 
 if ( min > abs(arr[i]) )
 min = abs(arr[i]);
 float sum = 0;
 for ( int i = 0; i < n; i++)
 if ( arr[i] == 0 )
{
 for ( int j = i; j < n; j++)
 sum = sum + abs(arr[j]);
 break;
}
 float tmpArr[n]; 
 for ( int i = 0, j = 0; i < n; i = i + 2, j++ ) 
 tmpArr[j] = arr[i];
 for ( int i = 1, j = n / 2; i < n; i = i + 2, j++ ) 
 tmpArr[j] = arr[i];
 cout << endl;
 for ( int i = 0; i < n; i++) 
{
 arr[i] = tmpArr[i];
 cout<<arr[i];
}
    cout << "min = " << min << endl;
    cout << "sum = " << sum << endl;
    system("pause");
    return 0;
}