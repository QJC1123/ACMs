#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int dx[4]={1,0,-1,0}; 
const int dy[4]={0,1,0,-1};
const int N=110;
int m[N][N],f[N][N];
int r,c;
int dfs(int x,int y)
{
	int maxm=1; //路径长度至少 1 
	if(f[x][y]!=0) //若之前求过 则返回 
	return f[x][y];
	for(int i=0;i<4;i++) //搜索四个方向 
	{
		int nx=x+dx[i]; //下个坐标点 
		int ny=y+dy[i]; 
		if(nx>0&&ny>0&&nx<=r&&ny<=c&&m[nx][ny]>m[x][y]) //不超过边界且满足条件 
		{
			maxm=max(maxm,dfs(nx,ny)+1); //最大 从下一个坐标点出发的最长路径长度+1（当前坐标的步长） maxm当前坐标出发最长路径长度 比较大小 若maxm大则换方向 
		} 
	}
	f[x][y]=maxm; //记忆化 
	return maxm;
} 
int main()
{
	int ans=0;
	cin>>r>>c; 
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>m[i][j]; 
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			f[i][j]=dfs(i,j); //深搜求从点i,j出发的最长路径长度 
			ans=max(ans,f[i][j]); //比较各个点出发的路径 得出最长路径长度 
		}
	}
	cout<<ans<<endl;
	return 0;
}

