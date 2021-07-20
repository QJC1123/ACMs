#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a,y;
double x;
int k;
int t;
int main()
{
	while(scanf("%d%lf%d",&a,&x,&y))
	{
		if(y%a==0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			k=y/a;
			if(k==0) 
			{
				if(a*0.5-fabs(x)>1e-3)
				   cout<<"1"<<endl;
				else
				   cout<<"-1"<<endl;
			}
			else if (k%2==1)
			{
				t=1+k/2*3+1;
				if(a*0.5-fabs(x)>1e-3)
				  cout<<t<<endl;
				else
				  cout<<-1<<endl;
			} 
			else
			{
				t=1+k/2*3; 
				if(x<0&&a*1.0-fabs(x)>1e-3)
				  cout<<t-1<<endl;
				else if(x>0&&a*1.0-fabs(x)>1e-3)
				  cout<<t<<endl;
				else 
				  cout<<"-1"<<endl; 
			} 
		}
	}
	return 0;
}

