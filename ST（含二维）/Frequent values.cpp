#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,q;
int a[maxn],b[maxn],stmax[maxn][20]; 
int l;
int r;
int id;
int ans;

void init_st()
{
	for(int i=1;i<=n;i++)
	  stmax[i][0]=b[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
		}
	}
}

int getmax(int l,int r)
{
	if(l>r)
	return 0;
	int k=log((double)(r-l+1))/log(2.0); //2.0 double *1.0 注意 
	return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
}

int main()
{
	while(cin>>n && n)
	{
		cin>>q;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(stmax,0,sizeof(stmax));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i==1)
			b[i]=1;
		    else if(a[i-1]==a[i])
		    b[i]=b[i-1]+1;
		    else
		    b[i]=1;
		}
		init_st();
		while(q--)
		{
			scanf("%d %d",&l,&r);
			id=upper_bound(a+1,a+1+n,a[l])-a; //从1开始 找到大于a[l]的第一个元素下标
			ans=getmax(id,r);
			ans=max(ans,min(r-l+1,id-l)); // 考虑id大于等于r 
			printf("%d\n",ans);
		}
	}
	return 0;
} 
/*

1   2 3 4 5 6 7 8  9  10
-1 -1 1 1 1 1 3 10 10 10 
1   2 1 2 3 4 1 1  2  3

l r
2 3
1 10
5 10

5 10
id=7 getmax=3 2  


3 5
id=7 getmax=0 3 4
*/
/*
id=upper_bound(a+1，a+1+n,a[l])-a;
可写成
int t=l;//从区间左端开始
while(t<=r && b[t]==b[t-1]) t++;//求第一个元素的个数
getmax(t,r);//再求区间t到r最大值 
*/
