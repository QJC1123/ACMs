/*导弹拦截
导弹高度需递减 
一个系统最多拦截导弹个数 ： 最长不上升序列长度 
拦截所有导弹最少系统个数 ： 不上升序列最少划分数=最长上升序列长度 
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
const int N=1e4;
int n;
int a[N],f[N],g[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //以i为结尾最长不上升序列长度 
		g[i]=1; //以i为结尾最长上升序列长度 
	}
	int res=1;//最长不上升序列长度 
	int ans=1;//最长上升序列长度 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>=a[i])
			f[i]=max(f[i],f[j]+1); 
			if(a[j]<a[i])
			g[i]=max(g[i],g[j]+1);
		}
		res=max(res,f[i]);
		ans=max(ans,g[i]);
	} 
	cout<<res<<endl<<ans<<endl;
	return 0; 
} 
