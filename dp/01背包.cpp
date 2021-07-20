//背包问题 01背包 
//f[i][c]=max(f[i-1][c],f[i-1][c-w[i]]+v[i]) 
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
	for(int i=1;i<=n;i++) //第i个物品 
	{
		for(int j=0;j<=m;j++) //背包承重 ？？？ 
		{
			if(j>=w[i]) //背包承重大于第i个物品的质量  ？？？ 
			f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]); //选价值最大的 
			else
			f[i][j]=f[i-1][j];
		} 
	} 
	/*优化 
	for(int i=1;i<=n;i++) 
	{
	   for(int j=m;j>=0;j--) //逆序 
	   {
	      if(j>w[i])
	      f[j]=max(f[j],f[j-w[i])+v[i]; //保证f[j]没有被第i个物品更新过 还是i-1层的状态  
       }
   } 
   进一步常数优化 
	int bound=0;
	int sumw=0;
	for(int i=1;i<=n;i++) 
	{
		sumw+=w[i];
		bound=max(m-sumw,w[i]); //背包剩余承重 与 当前物品重量 比较 
		for(int j=m;j>=bound;j--)
		{
			if(j>w[i])
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	*/
	cout<<f[n][m]<<endl; 
	return 0;
} 
 
