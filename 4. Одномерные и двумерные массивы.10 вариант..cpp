#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define n 10
 
using namespace std;
struct kor
{
 int x;
 int y;
};
 
int area(kor a, kor b, kor c)
{
  return abs((a.x - c.x)*(b.y - c.y) + (b.x-c.x)*(c.y-a.y));
}
 
int main()
{
 
  kor a[n];
  int i,j,k,r;
  int i1,j1,k1;
  int raz, razmin;
  srand(time(NULL));
  for (i = 0; i < n; i++)
  {
   a[i].x = rand()%10+1;
   a[i].y = rand()%10+1;
  }
  for (i = 0; i < n; i++)
  {
   printf("%5d  %5d\n", a[i].x, a[i].y);
  }
 
  i1 = 0;
  j1 = 0;
  k1 = 0;
  raz = 0;
  razmin = n;
  int c = 0, c1 = 0;
  for (i = 0; i < n- 2; i++)
  for (j = i + 1;  j < n - 1; j++)
  for (k = j + 1;  k < n; k++)
  {
  raz = 0;
  for (r = 0;  r < n; r++)
  {
   if (r!=i && r!=j && r!=k)
    if (area(a[i], a[j], a[k]))
   {
      if (area(a[i], a[j], a[k]) == area(a[i], a[j], a[r]) + area(a[i], a[r], a[k]) + area(a[j], a[r], a[k]))
           c++;
      else
          c1++;
   }
  }
  raz = c1-c;
  if (raz<0)  raz = -raz;
  if (raz < razmin)
  {
      razmin = raz;
      i1 = i;
      j1 = j;
      k1 = k;
  }
  };
 
  if (i1 >= 0)
  {
    cout << a[i1].x << " " << a[j1].x << " " << a[k1].x << "\n";
     cout << a[i1].y << " "<< a[j1].y << " " << a[k1].y << "\n";
     cout << razmin;
  }
  else
   cout << " неприемлемое ";
  getch();
  return 0;
}