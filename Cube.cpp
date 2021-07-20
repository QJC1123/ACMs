#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=100;
int n,m; //n������߳� m�в��� 
int X; //����1/0 
int xx,yy,zz;
int x,y,z;
ll c[maxn][maxn][maxn];
int ans;
int lowbit(int t)
{
	return t&(-t);
}

void update(int x,int y,int z)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		for(int j=y;j<=n;j+=lowbit(j))
		{
			for(int k=z;k<=n;k+=lowbit(k))
			{
				c[i][j][k]++; //������������ 
			}
		}
	}
}

int getsum(int x,int y,int z)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		for(int j=y;j>0;j-=lowbit(j))
		{
			for(int k=z;k>0;k-=lowbit(k))
			{
				sum+=c[i][j][k]; //ͨ������������˿ռ��ڲ����仯����
			}
		}
	} 
	return sum;
}

int main()
{
	while(cin>>n)
	{
		memset(c,0,sizeof(c));
		cin>>m;
		while(m--)
		{
			cin>>X;
			if(X==1)
			{
				cin>>x>>y>>z>>xx>>yy>>zz;
				update(x,y,z);          //�ݳⶨ������ 
				update(xx+1,y,z);
				update(x,yy+1,z);
				update(x,y,zz+1);
				update(xx+1,yy+1,z);
				update(xx+1,y,zz+1);
				update(x,yy+1,zz+1);
				update(xx+1,yy+1,zz+1);
			}
			else 
			{
				cin>>x>>y>>z;
				ans=getsum(x+1,y+1,z+1)%2;//�ı��ܴ���������1 ż��0 
				cout<<ans<<endl; 
			}
		}
    } 
	return 0;
} 
