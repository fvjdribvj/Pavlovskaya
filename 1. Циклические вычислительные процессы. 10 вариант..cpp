#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	double F, a, b, c, x_n, x_c, x_h;
	cin >> a >> b >> c >> x_n >> x_c >> x_h;
        for(x_n; x_n < x_c; x_n = x_n + x_h)
        {
	if (x_n < 3 && b != 0)
	{
		F = a*(x_n*x_n) - b*x_n + c;
	}
	else if (x_n > 3 && b == 0)
	{
		F = (x_n - a) / (x_n - c);
	}
	else {
		F = x_n / c;
	}
    
        int ac = a, bc = b, cc = c;
	if ((!(ac || bc) &&(ac ^ cc)) != 0) 
        {
		F = (int)F;
	}
	cout << x_n <<" :  F = " << F << endl;
        }
		return 0;
}