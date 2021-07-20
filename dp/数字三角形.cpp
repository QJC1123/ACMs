//µÝÍÆ·¨ 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=120;
int n;
int a[N][N],sum[N][N]; 
int main()
{
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=i;j++)
			{
				sum[i][j]=max(sum[i+1][j],sum[i+1][j+1])+a[i][j];
			}
		}
		//ÄæÍÆ 
		cout<<sum[1][1]<<endl;
	}

}

