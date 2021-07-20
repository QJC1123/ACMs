//数据相乘之积末尾0的个数

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const ll N=1e5+10;
ll n;
ll a[N];
ll cnt2,cnt5;
ll ans;

int main()
{
	cin>>n;
	cnt2=0;
	cnt5=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]!=0)
		{
			if(a[i]%2==0)
			{
				cnt2++; 
				a[i]/=2;
			}
			else if (a[i]%5==0)
			{
				cnt5++;
				a[i]/=5;
			}
			else
			break;
		}
	}
	ans=min(cnt2,cnt5);
	cout<<ans<<endl;
}
