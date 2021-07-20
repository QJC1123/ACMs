//多次测试数据 一定要初始化0 或 清空
//memset-ve ve->数组    v.clear() 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath> 
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
const int maxn=1e5+10;
const ll INF=0x3f3f3f3f; 
int n; //n个选民 
int a,b; //投给的人 改变主意的票数 
vector<int>ve[maxn],v;
int mx; //mx为候选人 
int l,r,mid,midd;
ll result;

ll third(int t)
{
	int ans=0; //总的贿赂金额 
	int need=t-ve[0].size(); //我要拿到的票数-现在票数=需要票数
	v.clear();
	for(int i=1;i<=mx;i++) //第i位候选人 
	{
		for(int j=0;j<ve[i].size();j++) //第i位候选人 的票数 
		{
			if(ve[i].size()-j>=t) //第i位候选人 总的票数-第j个选民票=剩下的票数>我要拿到得票数 
			{
				ans+=ve[i][j]; //  第i位候选人  第j个贿赂金额  从小到大贿赂金额 
				need--; //所需要的票数 
			} 
			else //其他i个选民 的票数 < 我要拿到的票数  
			    v.push_back(ve[i][j]); //第i个候选人 第j个贿赂金额 存入 v 中 
		}
	} 
	//得出要赢过其他候选人 的 各个候选人对应 贿赂金额  
	sort(v.begin(),v.end()); //将各个贿赂金额由小到大排序 
	for(int i=0;i<need;i++) //需要need个票 
	{
		ans+=v[i]; //总的贿赂金额 
	}
	return ans; 
}

int main()
{
	while(~scanf("%d",&n))
	{
		v.clear();
		memset(ve,0,sizeof(ve));
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			ve[a].push_back(b); 
			mx=max(mx,a); //得出几位候选人 
		}
		for(int i=1;i<=mx;i++)
		{
			sort(ve[i].begin(),ve[i].end());//投给第i为候选人 的 贿赂金额数 由小到大排序 
		}
		l=0;
		r=n;
		while(l+2<r) //这里注意要留常数特判，因为可能lr因为下面等于的原因，会漏掉之类
		{
			mid=(l+r)/2;
			midd=(mid+r)/2;
			if(third(mid)>third(midd))
			l=mid;
			else
			r=midd;
		}
		result=INF;
		for(int i=l;i<=r;i++)
		{
			result=min(result,third(i));
		}
		cout<<result<<endl;
	}
	return 0;
}
