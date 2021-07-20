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
int n,m; //��ʾ�����Ϳ�n m
int k; //��ʱ�������α߳�k
int q; //��q������ 
int result; //��ʾ���ڼ����� 
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
		a[s[i].x][s[i].y]=1; //�����𻵵�������Ϊ1 
	}
	   
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{                                                         //ǰ׺��Ԥ���� 
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]; //����������� 
		}
	}
	
	for(int i=k;i<=n;i++)  //�Ƚ�Ŀ������� �� ��������� 
	{
		for(int j=k;j<=m;j++)
		{
			if(k*k==sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k]) //�����ڲ�� 1->k  ??? 
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
		sort(s+1,s+q+1,cmp); //�����ذ�ʱ���Ⱥ�˳�� ��С��������
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
