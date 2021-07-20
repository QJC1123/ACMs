#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
string str1,str2,str;
bool flag;
int vis[250][250];

void dfs(int s1,int s2,int s)
{
	if(s1==str1.length() && s2==str2.length()) //结束条件 
	{
		flag=true;
		return ;
	}
	
	if(str1[s1]!=str[s] && str2[s2]!=str[s]) //越界 
	return ;
	
	if(vis[s1][s2]) //访问过的  str1中第s1个和str2中第s2个 
	return ; //返回 已经用过的 只能用一次 
	
	if(str1[s1]==str[s]) //进行搜索 
	dfs(s1+1,s2,s+1);
	if(str2[s2]==str[s])
	dfs(s1,s2+1,s+1);
	vis[s1][s2]=1; //记忆化 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str1>>str2>>str;
		flag=false;
		memset(vis,0,sizeof(vis));
		dfs(0,0,0); 
		if(flag)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}
