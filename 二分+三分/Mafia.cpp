#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long 
const ll maxn=1e5+10;
ll a[maxn];
int n;
ll sum; 
ll l,r,mid;
ll result;

bool check(ll mid)
{
	ll temp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mid) //��Ļغϲ��� ���Ҫ�� 
		  return false;
		temp+=mid-a[i]; //�ܾ���-����ҵľ�����С=�����о������ ��������ҵ����еľ��� 
	}
	if(temp>=mid) //��ҵ����еľ������ֵ֮�� ���� ��ǰ���� �������� 
	  return true;
	else
	  return false;
}


int main()
{
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	l=1;
	r=sum;
	result=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))//��������  
		{
			result=mid; //���Ϊ��ǰ���� 
			r=mid-1; //���� �����Ҹ�С�ľ��� 
		}
		else
		{
			l=mid+1; //���� �������������� �Ҹ���ֵ 
		}
	}
	cout<<result<<endl;
} 

