//最长上升子序列的个数

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
const int N=1e5;
int n;
int a[N],f[N],cnt[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //以i为结尾的最长上升子序列长度 
		cnt[i]=1; //以i为结尾的最长上升子序列的个数 
	} 
	int res=1; //整个序列中最长上升子序列的长度 至少为1 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])
			{
				if(f[j]+1>f[i]) //以j为结尾的最长上升序列+1 > 以i为结尾的最长上升序列 
				{
					f[i]=f[j]+1; 
					cnt[i]=cnt[j]; //以i为结尾的最长上升子序列个数 延续以j为结尾的  
				}
				else if(f[j]+1==f[i]) //有重复的一组 长度也为最长的 
				{
					cnt[i]+=cnt[j]; //有重复的 则以i为结尾的 再加上新的以j为结尾的 子序列个数 
				}
			}
		} 
		res=max(res,f[i]); //各个点为结尾 最长上升子序列长度 找出最大的 
	}
	int ans=0; //最长上升子序列的个数 
	for(int i=1;i<=n;i++)
	{
		if(f[i]==res) //有多个最长长度的子序列 
		ans+=cnt[i]; //个数 累加 各个i点为结尾的子序列个数= 
	} 
	cout<<ans<<endl;
    return 0;	
} 
