/* 5
a0 a1 a2 a3 a4 a5
1  3  5  6   3  2
至少h次 >=h  i>=h
至少h篇文章 ai>=h 

sum0 sum1 sum2 sum3 sum4 sum5  被引用至少i次 
 20    19   16   11   5    2   被引用至少i次 的文章数 sumi  sum[i]=sum[i+1]+a[i]
 
sum[i]>=i 从后往前第一个 符合条件 的 i 即h */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long 
const ll maxn=2e5+10;
ll a[maxn]; 
ll sum[maxn];
int n;

int main()
{
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		for(int i=0;i<=n;i++)
		{
			cin>>a[i]; //被引用i次的文章数  
		}
		for(int i=n;i>=0;i--)
		{
			sum[i]=sum[i+1]+a[i]; //后缀和  被引用至少i次 的文章数 
			if(sum[i]>=i)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
