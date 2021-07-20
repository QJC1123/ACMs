//time limit
//加了一行 if(ans==1) break; 
//不太理解  while循环里的意思 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ll long long
const int maxn=1e5+10;
ll a[maxn],s[maxn];
map<ll,ll>m;
int n,k; //n种化学物质 k-底数 
ll ans;//k的非负数次幂 
ll cut;//有效片段数 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//n个化学物质的情感值 
		s[i]=s[i-1]+a[i]; //前缀和预处理 
	} 
	ans=1;
	cut=0;
	while(abs(ans)<=1e14)
	{
		m.clear();
		m[0]=1; 
		for(int i=1;i<=n;i++) //片段区间右端点i 
		{
			//有效片段 区间和 s[r]-s[l-1]=ans（k的幂） 变为 s[l-1]=s[r]-ans  对应的左端l 
			cut+=m[s[i]-ans];//m记录每一个满足右端r(i) 前缀和 个数  //i相同时 前缀中有多少种方式组成满足s[i]-ans 就有多少个片段  有多少个合法的左端点 就有多少个片段 
			m[s[i]]++; //z作为左l 
		}
		ans*=k; //下一个幂 
		if(ans==1)
		  break;
	} 
	cout<<cut<<endl; 
} 
