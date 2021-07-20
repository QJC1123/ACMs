//最长上升子序列长度 （可不连续）(子序列可能多种组合，只求长度）
// f[i]=max(f[j]+1) 以i为结尾的最长上升子序列长度=i前面某点j为结尾最长上升子序列长度+1 （1=<j<i,a[j]<a[i]) 
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
int a[N],f[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //以i为结尾的最长上升子序列长度 
	}
	int res=1; //整个序列中最长上升子序列长度 长度至少为1 
	for(int i=1;i<=n;i++) //遍历各个点为结尾 
	{
		for(int j=1;j<=i-1;j++) //i之前的元素 
		{
			if(a[i]>a[j]) //后面>前面 
			f[i]=max(f[i],f[j]+1); //取最大 i之前最长上升子序列长度+1(i) 
		}
		res=max(res,f[i]); //各个i为结尾的长度中 找出最大长度 
	}
	cout<<res<<endl; 
    return 0;	
}
