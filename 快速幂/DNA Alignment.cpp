//compile error
// 加上maxn string s 变为 char s[maxn] 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath> 
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
const ll mod=1e9+7;//定义const常量 用于取模 
const ll maxn=1e5+10;
const string t="ATCG";
int n;
char s[maxn];
map<char,ll>a;//映射 char->ll 
ll maxx;
ll cnt;//出现次数最多的字母 个数 
ll result;

int main()
{
	
	maxx=-1;
	result=1;
	cnt=0;
	cin>>n;//长度n 字符串s 
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		a[s[i]]++;
	}
	for(int i=0;i<4;i++) //ATCG中找出 s中出现次数最多的字母 
	{
		if(a[t[i]]>maxx) //若有出现次数更大的字母出现  
		{
			maxx=a[t[i]]; //更新最大出现次数 
			cnt=1; //出现次数最大的字母数为1个 
		}
		else if(a[t[i]]==maxx) //若又有其他出现次数最大的字母 
		{
			cnt++; //出现次数最大的字母个数++ 
		}
	} 
	//找出出现次数最大的字母个数有几个
	//快速幂 base=num power=n; 再对M取模 
	while(n)
	{
		if(n&1)//if(n%2==1) 奇数
		{
			result=result*cnt%mod;
		} 
		n=n/2;// n>>=1; //指数减半 
		cnt=cnt*cnt%mod;//底数两个互乘 
	}
	cout<<result<<endl;
	return 0;
}
