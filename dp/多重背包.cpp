//多重背包

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
int w[N],v[N],s[N];
int f[N][M];  //前i个物品 放入承重为j的背包中的 最大价值 
int main()
{
	cin>>n>>m; //n个物品 m承重极限 
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i]>>s[i];  //每种物品的重量 价值 数量 
	} 
	for(int i=1;i<=n;i++) //遍历每种物品 
	{
		for(int j=0;j<=m;j++) //背包承重从小到大 遍历每一种组合方式 
		{
			for(int k=0;k<=s[i];k++) //每个物品数量 
			{
				if(j>=k*w[i])  //大于等于 
				f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
		} 
	}
	cout<<f[n][m]<<endl; 
	return 0;
} 
	/*
	二进制优化法 
	cin>>n>>m; //n个物品 m承重极限 
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w>>v>>s;  //每种物品的重量 价值 数量 
		int k=1;
		while(k<=s)
		{
			cnt++;
			w[cnt]=w*k;
			v[cnt]=v*k;
			s-=k;
			k*=2;
		}
		if(s>0)
		{
			cnt++;
			w[cnt]=w*s;
			v[cnt]=v*s;
		}	
	}
	int num=cnt;
	for(int i=1;i<=num;i++)
	{
		for(int j=m;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[m]<<endl;
	*/
	/*
	
	*/
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i]>>s[i];
	} 
	for(int i=1;i<=n;i++)
	{
		if(w[i]*s[i]>m)
		{
			for(int j=w[i];j<=m;j++)
			{
				f[j]=max(f[j],f[j-w[i]]+f[])
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
