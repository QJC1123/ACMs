//���ر���

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=210;
const int M=510;
int n,m;
int w[N],v[N],s[N];
int f[N][M];  //ǰi����Ʒ �������Ϊj�ı����е� ����ֵ 
int main()
{
	cin>>n>>m; //n����Ʒ m���ؼ��� 
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i]>>s[i];  //ÿ����Ʒ������ ��ֵ ���� 
	} 
	for(int i=1;i<=n;i++) //����ÿ����Ʒ 
	{
		for(int j=0;j<=m;j++) //�������ش�С���� ����ÿһ����Ϸ�ʽ 
		{
			for(int k=0;k<=s[i];k++) //ÿ����Ʒ���� 
			{
				if(j>=k*w[i])  //���ڵ��� 
				f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
		} 
	}
	cout<<f[n][m]<<endl; 
	return 0;
} 
	/*
	�������Ż��� 
	cin>>n>>m; //n����Ʒ m���ؼ��� 
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w>>v>>s;  //ÿ����Ʒ������ ��ֵ ���� 
		int k=1;
		while(k<=s)
		{
			cnt++;
			w[cnt]=w*k;
			v[cnt]=v*k;
			s-=k;
			k*=2;
		}
		if(s>0)
		{
			cnt++;
			w[cnt]=w*s;
			v[cnt]=v*s;
		}	
	}
	int num=cnt;
	for(int i=1;i<=num;i++)
	{
		for(int j=m;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[m]<<endl;
	*/
	/*
	
	*/
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i]>>s[i];
	} 
	for(int i=1;i<=n;i++)
	{
		if(w[i]*s[i]>m)
		{
			for(int j=w[i];j<=m;j++)
			{
				f[j]=max(f[j],f[j-w[i]]+f[])
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
