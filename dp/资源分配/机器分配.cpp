//资源分配dp 机器分配 
//f[i][j]=max(f[i-1][j-k]+a[i][k]) 前i-1家公司 分配j-k个机器 + 第i家公司分配k个机器 =前i家公司分配j个机器 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=20;
int n,m; 
int a[N][N],f[N][N];//前i个公司分配j台机器最大利润 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j]; //第i个公司分配j台机器的利润 
		}
		f[i][0]=0; //边界 
	}
	for(int i=1;i<=n;i++) //前i家公司 
	{
		for(int j=1;j<=m;j++) //j个机器 
		{
			for(int k=0;k<=j;k++) //第i家公司分配k个机器 0-j 可能前i-1家0台机器或第i家0台机器 
			{
				f[i][j]=max(f[i][j],f[i-1][j-k]+a[i][k]); 
			} 
		} 
	} 
	cout<<f[n][m]<<endl; //前n家公司分配m台机器 
	return 0;
} 
