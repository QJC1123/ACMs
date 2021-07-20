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
	return (x&(-x)); //ֻʣ���һλ��1  �����ƴ������ 
}

void update(int x,int v)  //��a[i]->c[i] i+lowbit(i) �ı仯 
{
	while(x<=N)
	{
		c[x]+=v;         //a[i] �ı仯 +t   ->c[i]�ı仯 +t 
		x+=lowbit(x);   // a[i]�ı仯 Ӱ�쵽  c[i]�ı仯:i+lowbit(i) ����ĩβ1 +1���� �õ��Ҷ�) 
	}
}

int getsum(int x) //������� 
{
	int sum=0;
	while(x)
	{
		sum+=c[x];      //c[i]�Ҷ�  ����˵�c[i]������� 
		x-=lowbit(x);  // ����ĩβ1 -1���� �õ���� �� 
	}
	return sum;
}

int main()
{
	while(scanf("%d",&n)!=EOF) //n������ 
	{
		int ans=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a); 
			update(a,1);      //a[n]��ʾ����n�Ƿ���� 1/0  ����c 
			ans+=i-getsum(a); //getsum(a) ��� <=a �����ĸ���  i-getsum(a) ����>a�����ĸ��� 
		}
		printf("%d\n",ans);  //ans ���������� 
	}
	return 0;
}


