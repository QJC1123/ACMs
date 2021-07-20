#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=120;
int n;
int a[N][N],b[N][N];

int dfs(int x,int y)
{
	if(b[x][y])
	return b[x][y];
	if(x==n)
	return a[n][y];
	int temp1=dfs(x+1,y);
	int temp2=dfs(x+1,y+1);
	b[x][y]=max(temp1,temp2)+a[x][y];
	return b[x][y];
}

int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin>>a[i][j];
			}
		}
		cout<<dfs(1,1)<<endl;
	}
} 
