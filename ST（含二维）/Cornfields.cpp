#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=260;
const int inf=0x3f3f3f3f;
int n,b; //原n×n 查 b×b  
int a[maxn][maxn],stmax[maxn][maxn][20],stmin[maxn][maxn][20];
int l,r;

void init_st()
{
	for(int k=1;k<=n;k++)
	{
		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				stmax[k][i][j]=max(stmax[k][i][j-1],stmax[k][i+(1<<(j-1))][j-1]);
				stmin[k][i][j]=min(stmin[k][i][j-1],stmin[k][i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int query_st(int l,int r)
{
	int k=(log((double)b)/log(2.0));
	int getmax=0; //注意 
	int getmin=inf; //注意 
	for(int i=1;i<l+b;i++)
	{
		getmax=max(max(stmax[i][r][k],stmax[i][(r+b-1)-(1<<k)+1][k]),getmax);
		getmin=min(min(stmin[i][r][k],stmin[i][(r+b-1)-(1<<k)+1][k]),getmin);
	}
	return getmax-getmin;
}

int main()
{
	int k;
	
		cin>>n>>b>>k;
		memset(stmax,0,sizeof(stmax));
		memset(stmin,0,sizeof(stmin));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>stmax[i][j][0];
				stmin[i][j][0]=stmax[i][j][0];
			}
		} 
		init_st();
		while(k--)
		{
			cin>>l>>r;
			cout<<query_st(l,r)<<endl;
		}
	
	return 0;
}
