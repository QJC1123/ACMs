#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1010;
int c[N];
int n;
int lowbit(int x)
{
	return (x&(-x)); //只剩最后一位的1  二进制代表的数 
}

void update(int x,int v)  //对a[i]->c[i] i+lowbit(i) 的变化 
{
	while(x<=N)
	{
		c[x]+=v;         //a[i] 的变化 +t   ->c[i]的变化 +t 
		x+=lowbit(x);   // a[i]的变化 影响到  c[i]的变化:i+lowbit(i) （对末尾1 +1操作 得到右端) 
	}
}

int getsum(int x) //求区间和 
{
	int sum=0;
	while(x)
	{
		sum+=c[x];      //c[i]右端  求左端到c[i]的区间和 
		x-=lowbit(x);  // （对末尾1 -1操作 得到左端 ） 
	}
	return sum;
}

int main()
{
	while(scanf("%d",&n)!=EOF) //n个数字 
	{
		int ans=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a); 
			update(a,1);      //a[n]表示数字n是否出现 1/0  更新c 
			ans+=i-getsum(a); //getsum(a) 求出 <=a 的数的个数  i-getsum(a) 则是>a的数的个数 
		}
		printf("%d\n",ans);  //ans 逆序数个数 
	}
	return 0;
}


