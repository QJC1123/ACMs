#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long 
const ll maxn=1e5+10;
ll a[maxn];
int n;
ll sum; 
ll l,r,mid;
ll result;

bool check(ll mid)
{
	ll temp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mid) //玩的回合不到 玩家要求 
		  return false;
		temp+=mid-a[i]; //总局数-当玩家的局数最小=当裁判局数最大 求所有玩家当裁判的局数 
	}
	if(temp>=mid) //玩家当裁判的局数最大值之和 多于 当前局数 满足条件 
	  return true;
	else
	  return false;
}


int main()
{
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	l=1;
	r=sum;
	result=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))//满足条件  
		{
			result=mid; //结果为当前局数 
			r=mid-1; //左移 尝试找更小的局数 
		}
		else
		{
			l=mid+1; //右移 局数不满足条件 找更大值 
		}
	}
	cout<<result<<endl;
} 

