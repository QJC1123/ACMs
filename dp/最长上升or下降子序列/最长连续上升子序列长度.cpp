/*序列的不上升子序列最少划分数等于序列的最长上升子序列长度
  序列的不下降子序列最少划分数等于序列的最长下降子序列长度
*/
//最长连续递增序列 

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
int a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<int>f(n,1); //以i为结尾的最长连续递增子序列长度 
	int res=1; //整个序列最长连续递增子序列长度 至少为1 
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) //后面>前面 
		  f[i]=f[i-1]+1;  //以i为结尾的子序列长度+1 
		if(f[i]>res) //有更长的子序列 
		  res=f[i];  //更新res 
		
	}
	cout<<res<<endl; //输出 
	return 0;
}
 

 
