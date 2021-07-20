#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=100;
int n,m; //n立方体边长 m行操作 
int X; //操作1/0 
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
				c[i][j][k]++; //构造树形数组 
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
				sum+=c[i][j][k]; //通过树形数组求此空间内操作变化次数
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
				update(x,y,z);          //容斥定理？？？ 
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
				ans=getsum(x+1,y+1,z+1)%2;//改变总次数：奇数1 偶数0 
				cout<<ans<<endl; 
			}
		}
    } 
	return 0;
} 
