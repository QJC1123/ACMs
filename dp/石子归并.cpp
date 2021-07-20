/*石子归并 区间dp 
4 1 2 3 4 
求最小合并代价
[l,r]区间中 
总的合并代价=[l][k]合并的代价+[k+1][r]合并的代价+[l,r]石子总数 
状态 dp[i][j] 第i堆到第j堆的石子合并最小代价
状态划分 最后一次的操作  
状态转移方程 dp[i][j]=min(dp[i][k]+dp[i+1][k])+sum[i,j]; 
边界情况 区间长度为1 i=j f[i][j]=0 
预处理 dp[i][j] 预处理为较大的数->求最小 
状态转移方向 区间长度小->大
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=120;
const ll INF=0x3f3f3f3f;
int n;
int a[N],s[N];
int f[N][N]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i]; //前缀和 用于求一段区间内石子总数 s[l]-s[r-1]=sum(l,r) 
	}
	for(int len=2;len<=n;len++) //区间长度枚举 合并至少2堆 长度至少为2 
	{
		for(int i=1;i+len-1<=n;i++) //枚举左端点 
		{
			int j=i+len-1; //该区间长度下的右端点 
			f[i][j]=INF; //预处理该区间为最大值  
			for(int k=i;k<j;k++) //k分割去区间 
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]); //最后一次合并操作 ->z状态划分->状态移动方程  
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
} 
 

