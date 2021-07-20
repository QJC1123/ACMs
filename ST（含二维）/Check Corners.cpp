#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int maxnm=310;
int m,n,q,r1,r2,c1,c2,ma; //m行 n列 q个询问 
int a[maxnm][maxnm],f[maxnm][maxnm][20][20];

void init_st()
{
	int maxr=log2(m);
	int maxc=log2(n);
	for(int i=0;i<=maxr;i++)
	{
		for(int j=0;j<=maxc;j++)
		{
			if(i==0 && j==0) continue;
			for(int x=1;x+(1<<i)-1<=m;x++)
			{
				for(int y=1;y+(1<<j)-1<=n;y++)
				{
					if(i==0)
					{
						f[x][y][i][j]=max(f[x][y][i][j-1],f[x][y+(1<<(j-1))][i][j-1]);
					}
					else
					{
						f[x][y][i][j]=max(f[x][y][i-1][j],f[x+(1<<(i-1))][y][i-1][j]);
					}
				}
			}
		}
	}
}

int enqury_st()
{
	int k1=log2(r2-r1+1);
	int k2=log2(c2-c1+1);
	int t1=f[r1][c2-(1<<k2)+1][k1][k2];
	int t2=f[r2-(1<<k1)+1][c2-(1<<k2)+1][k1][k2];
	int t3=f[r2-(1<<k1)+1][c1][k1][k2];
	int t4=f[r1][c1][k1][k2];
	return max(max(t1,t2),max(t3,t4));
}

int main()
{
	while(cin>>m>>n)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				f[i][j][0][0]=a[i][j];
			}
		}
		init_st();
		cin>>q;
		for(int i=1;i<=q;i++)
		{
			cin>>r1>>c1>>r2>>c2;
			ma=enqury_st();
			cout<<ma<<" ";
			if(a[r1][c1]==ma||a[r2][c1]==ma||a[r1][c2]==ma||a[r2][c2]==ma)
			cout<<"yes"<<endl;
			else
			cout<<"no"<<endl;
		}
	}
	return 0;
}
