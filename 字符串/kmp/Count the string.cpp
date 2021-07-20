//给你一个字符串，枚举其所有的前缀，输出其所有前缀出现的次数
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e5+10;
const int M=10007;
int t,n;
char str[N];
int nextt[N];
int ans;
int dp[N];

void pre()
{
	nextt[0]=-1;
	int k=-1,j=0;
	while(j<n)
	{
		if((k==-1)||(str[k]==str[j]))
		nextt[++j]=++k;
		else
		k=nextt[k];
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		memset(nextt,0,sizeof(nextt));
		ans=0;
		cin>>n;
		scanf("%s",str);
		pre();
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[nextt[i]]+1;
			dp[i]%=M;
			ans=(ans+dp[i])%M;
		}
		cout<<ans<<endl;
	}
} 

