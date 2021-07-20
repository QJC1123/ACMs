#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
#define ll long long
const ll maxn=1e5+10;
int n; //n个矩形 
ll h[maxn],l[maxn],r[maxn]; //所有高度 左边界 右边界 
stack<int>s;
ll area;

int main()
{
	while((cin>>n) && n) //n为0时结束 
	{
		area=0;
		for(int i=i;i<=n;i++)
		{
			cin>>h[i]; //输入各个矩形高度 
		}
		while(!s.empty()) //s栈不为空时出栈 清空栈 
		{
			s.pop();  
		}
		for(int i=1;i<=n;i++)
		{
			while(!s.empty() && h[s.top()]>h[i]) //从左边开始单调递减栈 
			{
				s.pop();
			} 
			if(s.empty())
			{
				l[i]=0; 
			} 
			else
			{
				l[i]=s.top();
			}
			s.push(i);
		} 
		while(!s.empty()) //s栈不为空时出栈 清空栈 
		{
			s.pop();  
		}
		for(int i=n;i>=1;i--)
		{
			while(!s.empty() && h[s.top()]>h[i]) //从右边开始单调递减 
			{
				s.pop();
			}
			if(s.empty()) 
			{
				r[i]=n;
			}
			else
			{
				r[i]=s.top()-1;
			}
			s.push(i);
		}
		for(int i=1;i<=n;i++)
		{
			area=max((ll)(r[i]-l[i])*h[i],area);
		}
		cout<<area<<endl;
	}
	return 0;
} 
