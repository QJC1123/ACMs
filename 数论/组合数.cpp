#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std; 
const ll M=1e9+7;
const ll N=1e5;
ll n,m;
ll c[N][N];

void init()
{
	for(int i=0;i<=N;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
		} 
	}
}

int main()
{
	int t;
	cin>>t;
	init();
	while(t--)
	{
		cin>>n>>m;
		cout<<c[n][m]<<endl;
	} 
	return 0;
}
