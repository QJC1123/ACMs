#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
const int maxn=2e5+10; //字符串最大长度 
char str[maxn]; //输入的字符串 
int sx[maxn]; //移动后的坐标x
int sy[maxn]; 
int l,r,mid; //mid表示更改字段长度 
int result; 
int x,y;

bool check(int len)
{
	
	for(int i=1;i+len-1<=n;i++) //起点i 终点mid+i-1  mid不变 要更改的字段长度不变 
	{
		int tl=i; //左端起点i 
	    int tr=i+len-1; //右端终点mid+i-1 
	    int movex=sx[tr]-sx[tl-1]; //被替换区间 删去 造成 的偏移量 
		int movey=sy[tr]-sy[tl-1]; 
		int nowx=sx[n]-movex; //原本最终坐标 删去  被替换区间后 的现在坐标 
		int nowy=sy[n]-movey; 
		int dis=abs(x-nowx)+abs(y-nowy);// 现在坐标 到 目标坐标 所需的偏移量 即需要改变的操作个数
		if(dis <= len && (len-dis)%2==0)
		{
			return true;
		} 
		 // (mid-dis) % 2 == 0 是保证 在还有多余字符的情况下，保证 能够来回 以 最后到达终点
		//想要保证我们枚举的区间符合条件就需要保证我们替换上去的区间长度 len 奇偶性和终点的曼哈顿距离 dis 一致，并且保证len>=dis。 
	}
	return false;	
}


int main()
{
	while(~scanf("%d",&n))
	{
		memset(str,' ',sizeof(str));
		memset(sx,0,sizeof(sx));
		memset(sy,0,sizeof(sy));
		scanf("%s",str); //str+1 无& 
		scanf("%d%d",&x,&y); //目标位置 
		for(int i=1;i<=n;i++) //将字符串代表的操作反映为坐标变化  //前缀和求得走到了i步后的位置sx sy 
		{
			if(str[i-1]=='R')
			sx[i]=1;
			if(str[i-1]=='L') 
			sx[i]=-1;
			if(str[i-1]=='U')
			sy[i]=1;
			if(str[i-1]=='D')
			sy[i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			sx[i]=sx[i]+sx[i-1];
			sy[i]=sy[i]+sy[i-1];
		}
		l=0;
		r=n;
		result=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid))
			{
				result=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		} 
		cout<<result<<endl;
	}
	return 0;
}
