//̰�� 
//17m/s 60m/s -10�� 4��/s ԭ��  
//�ֱ𱣴����ֺͱ���ǰt�����ߵľ���a.b������ǰt��ʱ�������ߵľ���a>�������ߵľ���b����bȡ�ϴ��ֵa
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
