//金明的预算方案  依赖背包 
//分组背包
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=35000;
int n,m;//总钱数n 物品个数m
int v[N],p[N],q[N],a[N]; //价格 重要度 主件/附件 
int f[N][N];
int num[5];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>p[i]>>q[i];
		p[i]*=v[i]; // 求重要度和价格乘积总和最大 
	}
	for(int i=1;i<=m;i++)
	{
		if(q[i]==0) //主件
		{
			for(int j=1;j<v[i];j++)
		    {
		    	a[j]=0;
			}
		} 
	}
	
	return 0;
} 
