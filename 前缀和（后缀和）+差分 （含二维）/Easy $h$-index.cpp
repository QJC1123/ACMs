/* 5
a0 a1 a2 a3 a4 a5
1  3  5  6   3  2
����h�� >=h  i>=h
����hƪ���� ai>=h 

sum0 sum1 sum2 sum3 sum4 sum5  ����������i�� 
 20    19   16   11   5    2   ����������i�� �������� sumi  sum[i]=sum[i+1]+a[i]
 
sum[i]>=i �Ӻ���ǰ��һ�� �������� �� i ��h */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long 
const ll maxn=2e5+10;
ll a[maxn]; 
ll sum[maxn];
int n;

int main()
{
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		for(int i=0;i<=n;i++)
		{
			cin>>a[i]; //������i�ε�������  
		}
		for(int i=n;i>=0;i--)
		{
			sum[i]=sum[i+1]+a[i]; //��׺��  ����������i�� �������� 
			if(sum[i]>=i)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
