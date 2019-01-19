 #include <iostream>
 #include <cstdlib>
 #include <cmath>
 #define n 10
 int main(){
    int mas[n][n];
    int locMin = 0;
    int sum = 0;
    cout << "Matrix :"<<endl;
    for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
{
    mas[i][j] = rand() % 100 - 10;
    cout<<mas[i][j]<<"Minimum";       
}
    cout<<endl;
}
    cout<<"Minimum :"<<endl;
    for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
{
    if( (mas[i][j] < mas[i][j-1]) && (mas[i][j] < mas[i][j+1]) && (mas[i][j] < mas[i+1][j]) && (mas[i][j] < mas[i-1][j]))
{
    cout<<"String "<<i+1<<" column "<<j+1<<" min = "<<mas[i][j]<<endl;
    locMin++;
}
}
}
    cout <<"Found "<<locMin<<" minimum";
    for(int i = 0; i < n; i++)
{
    for(int j = i + 1; j < n; j++)
{
    sum += abs(mas[i][j]);
}
}
    cout<<endl<<"Sum of the elements above the main diagonal = "<<sum;
            
return 0;
}