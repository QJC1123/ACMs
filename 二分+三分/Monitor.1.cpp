#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int x;
	int y;
	int t;
}s[500000];
int n,m; //显示器长和宽n m
int k; //损坏时的正方形边长k
int q; //损坏q个像素 
int result; //显示器第几秒损坏 
int l,r,mid; 
int a[510][510];
int sum[510][510];

int cmp(node a,node b)
{
	return a.t<b.t;
}

bool check(int mid)
{
	memset(a,0,sizeof(a));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=mid;i++)
	{
		a[s[i].x][s[i].y]=1; //像素损坏的区域标记为1 
	}
	   
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{                                                         //前缀和预处理 
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]; //求像素损坏面积 
		}
	}
	
	for(int i=k;i<=n;i++)  //比较目标损坏面积 与 现有损坏面积 
	{
		for(int j=k;j<=m;j++)
		{
			if(k*k==sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k]) //类似于差分 1->k  ??? 
			    return true;
		}
	} 
	return false;
}

int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&k,&q)) 
	{
		for(int i=1;i<=q;i++)
		  scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].t);
		sort(s+1,s+q+1,cmp); //将像素按时间先后顺序 由小到大排列
		result=-1;
		l=1;
		r=q; 
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid)) 
			{
				result=s[mid].t;
				r=mid-1; 
			}
			else
			    l=mid+1;
		}
		cout<<result<<endl;
	}
	return 0;
}
