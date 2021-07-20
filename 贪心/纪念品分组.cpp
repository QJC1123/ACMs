//贪心 +快排 
//最贵的和最便宜的一组 达到最少分组 超出价格限制则最贵的为一组
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int w;
	cin>>w;
	int n;
	cin>>n;
	int a[32000];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1); //从小到大排序 
	int ans=0;
	int l=1;
	int r=n;
	while(l<=r)
	{
		if((a[l]+a[r])<=w&&l!=r)
		{
			ans++;
			l++;
			r--;
		}
		else
		{
			ans++;
			r--;
		}
	}
	cout<<ans<<endl;
	
	return 0;
} 
