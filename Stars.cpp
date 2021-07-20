#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=1010;
int m,xx,yy,x,y;
char s;
int c[maxn][maxn],f[maxn][maxn];

int lowbit(int t)  
{
	return t&(-t);
}

void update(int a,int b,int v)
{
	for(int i=a;i<=maxn;i+=lowbit(i))
	{
		for(int j=b;j<=maxn;j+=lowbit(j))
		{
			c[i][j]+=v;
		}
	}
}

int getsum(int a,int b)
{
	int sum=0;
	for(int i=a;i>0;i-=lowbit(i))
	{
		for(int j=b;j>0;j-=lowbit(j))
		{
			sum+=c[i][j];
		}
	}
	return sum;
}

int main()
{
	while(cin>>m)
	{
		while(m--)
		{
			cin>>s;
			if(s=='B') //点亮 
			{
				cin>>x>>y;
				x++;           //xy从0开始 +1后移 因为这里x>0,y>0所以（0,0）这一点已经没有，经下面推知，此点已变成（1,1）目的是好计算
				y++;
				if(f[x][y]==1) //不重复 
			      continue;
			    update(x,y,1);
			    f[x][y]=1;
			}
			else if(s=='D') //熄灭 
			{
				cin>>x>>y;
				x++;
				y++;
				if(f[x][y]==0) //不重复 
				  continue;
				update(x,y,-1);
				f[x][y]=0;
			}
			else
			{
				cin>>x>>xx>>y>>yy;
				x++;
				y++;
				xx++;
				yy++;
				if(x>xx)
				  swap(x,xx);
				if(y>yy)
				  swap(y,yy);
				int ans=getsum(xx,yy)-getsum(xx,y-1)-getsum(x-1,yy)+getsum(x-1,y-1); //二维前缀和 
				cout<<ans<<endl;
			}
			
		}
		
	}
	
	return 0;
}
