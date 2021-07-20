/*记忆化搜索
用dp[][][]存起来以往的值 
*/ 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
int dp[30][30][30];

int dfs(int a,int b,int c)
{
	if(a<=0 || b<=0|| c<=0)
    return 1;
    if(a>20 || b>20|| c>20)
    return dfs(20,20,20);
    if(dp[a][b][c])  //避免重复计算 
    return dp[a][b][c]; 
    if(a<b && b<c)
    dp[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    else
    dp[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
    return dp[a][b][c];
}



int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==-1 && b==-1 && c==-1)
		  break;
		cout<<dfs(a,b,c)<<endl; 
	}
	return 0;
} 
