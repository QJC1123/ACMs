#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=110;
int n,a[N];
int minn,maxx;
int mincnt,maxcnt;
int sum;
int main()
{
	minn=120;
	maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=minn)
		{
			minn=a[i];
			mincnt=i;
		}
		else if(a[i]>maxx)
		{
			maxx=a[i];
			maxcnt=i;
		}
	}
	if(maxcnt<mincnt)
	sum=maxcnt-1+n-mincnt;
	else
	sum=maxcnt-1+n-mincnt-1;
	cout<<sum<<endl; 
	return 0;
}

#include<stdio.h>
#include<string.h>
 
int main()
{
	int n;
	int temp,max,min,locate_max,locate_min;
	while(~scanf("%d",&n))
	{
		max=-500;
		min=500;
		locate_max=1; //≥ı ºªØ 
		locate_min=n;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			if(temp>max)
			{
				max=temp;
				locate_max=i;
			}
			if(temp<=min)
			{
				min=temp;
				locate_min=i;
			}
		}
		if(locate_max < locate_min)
			cnt+=locate_max-1+n-locate_min;
		else
		    cnt+=(n-locate_min)+(locate_max-1)-1;
		printf("%d\n",cnt);
	}
	return 0;
}

