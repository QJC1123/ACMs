//贪心 
//17m/s 60m/s -10点 4点/s 原地  
//分别保存闪现和奔跑前t秒所走的距离a.b，若在前t秒时闪现所走的距离a>奔跑所走的距离b，则b取较大的值a
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int m,s,t;
	cin>>m>>s>>t;
	int v1=17,v2=60,m1=10,m2=4;
	int a=0,b=0;
	for(int i=1;i<=t;i++)
	{
		b+=v1;
		if(m>=m1)
		{
			a+=v2;
			m-=m1;
		}
		else
		{
			m+=m2;
		}
		b=max(b,a);
		if(b>=s)
		{
			a=-1;
			b=i;
			break;
		}
	} 
	if(a==-1)
	cout<<"Yes"<<endl<<b<<endl;
	else
	cout<<"No"<<endl<<b<<endl;
	return 0;
} 
