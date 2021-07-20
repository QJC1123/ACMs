//最长连续递增子序列 
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
	int res=1; //整个序列中最长连续递增子序列长度 
	int id; //子序列起点 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //以i为起点的子序列长度 
	}
	for(int i=1;i<=n;i++) //遍历各个点为结尾 
	{
		for(int j=i+1;j<=n;j++) 
		{
			if(a[j-1]<a[j]) //后面>前面  
			f[i]++; //每大一个 长度+1
			else //若出现不符合条件  
			break; //退出循环 (连续) 
		} 
		/*if(f[i]>res)
		{
	       res=f[i];
	       id=i;
	    }*/
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]>res)
		{
			res=f[i];
			id=i;
		}
	} 
	for(int i=id;i<id+res-1;i++)
	{
		cout<<a[i]<<" ";
	} 
	cout<<endl<<res<<endl;
	return 0;
 } 
