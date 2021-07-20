#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int r1,r2,c1,c2,d1,d2;
    int a,b,c,d;

int main()
{
	cin>>r1>>r2>>c1>>c2>>d1>>d2; 
	for(a=1;a<=9;a++)
	{
		b=r1-a;
		c=c1-a;
		d=d1-a;
		if(r2==c+d&&c2==b+d&&d2==b+c&&a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d&&b>=1&&b<=9&&c>=1&&c<=9&&d>=1&&d<=9)
		{
			cout<<a<<" "<<b<<endl<<c<<" "<<d<<endl;
			return 0;
	    }
	}
	cout<<"-1"<<endl;
	return 0;
}
