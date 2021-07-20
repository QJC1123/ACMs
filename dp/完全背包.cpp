//完全背包
//f[i][c]=max(f[i-1][c-k*w[i]]+k*v[i]) 0=<k*w[i]<=m

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=210;
const int M=510;
int n,m;
int w[N],v[N];
int f[N][M];  //前i个物品 放入承重为j的背包中的 最大价值 
int main()
{
	cin>>n>>m; //n个物品 m承重极限 
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];  //每个物品的重量和价值 
	} 
	for(int i=1;i<=n;i++) //遍历每一个物品 
	{
		for(int j=0;j<=m;j++) //背包承重从小到大 遍历每一种组合方式 
		{
			for(int k=0;k*w[i]<=j;k++)
			{
				f[i][j]=max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
		} 
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++) //顺序 （01背包是逆序） 
		{
			if(j>w[i])
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		 } 
	} 
	*/ 
	cout<<f[n][m]<<endl; 
	return 0;
}
