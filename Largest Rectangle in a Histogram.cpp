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
int n; //n������ 
ll h[maxn],l[maxn],r[maxn]; //���и߶� ��߽� �ұ߽� 
stack<int>s;
ll area;

int main()
{
	while((cin>>n) && n) //nΪ0ʱ���� 
	{
		area=0;
		for(int i=i;i<=n;i++)
		{
			cin>>h[i]; //����������θ߶� 
		}
		while(!s.empty()) //sջ��Ϊ��ʱ��ջ ���ջ 
		{
			s.pop();  
		}
		for(int i=1;i<=n;i++)
		{
			while(!s.empty() && h[s.top()]>h[i]) //����߿�ʼ�����ݼ�ջ 
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
		while(!s.empty()) //sջ��Ϊ��ʱ��ջ ���ջ 
		{
			s.pop();  
		}
		for(int i=n;i>=1;i--)
		{
			while(!s.empty() && h[s.top()]>h[i]) //���ұ߿�ʼ�����ݼ� 
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
