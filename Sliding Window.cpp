#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
const ll maxn=1e6;
ll n,k; //n个数字 k个窗口长度 
ll a[maxn],dl[maxn],id[maxn];  
int l,r; //左端点队首 右端点队尾  

int main()
{
	while(cin>>n>>k)
	{
		memset(a,0,sizeof(a));
		memset(dl,0,sizeof(dl));
		memset(id,0,sizeof(id));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];   //n个数字 
		}
		r=0;
		l=1;
		for(int i=1;i<=n;i++)  ///队首最小值  递增单调队列 
		{
			while(l<=r && a[i]<=dl[r]) //队首<队尾 并且 新数字 <= 队尾 删除队尾 
		      r--;  //r-说明回到上一个 相当于删去原来的r 
			r++; //新数字大于队尾 r++ 下一个开始 递增 
			dl[r]=a[i]; //队列下一个元素是 新数字 
			id[r]=i; //对应的坐标 是 新数字 序号 
			if(i-id[l]+1>k) // 队尾坐标-队首坐标+1 =区间长度 > 窗口长度 
			  l++; //队首左移 直到 长度=窗口长度 
			if(i>=k) //队尾>=窗口长度 （i<k 不到窗口长度 不形成窗口） 
			  cout<<dl[l]<<" "; //输出 队首 最小值 
		}
		cout<<endl;
		memset(dl,0,sizeof(dl)); //初始化队列 
		memset(id,0,sizeof(id));
		r=0;
		l=1;
		for(int i=1;i<=n;i++) // 找最大值 
		{
			while( l<=r && a[i]>=dl[r] ) 
			  r--;
			r++;
			dl[r]=a[i];
			id[r]=i;
			if(i-id[l]+1>k) //id[l]+k<=i 
			  l++;
			if(i>=k)
			  cout<<dl[l]<<" ";
		}
		cout<<endl;
	}
} 
