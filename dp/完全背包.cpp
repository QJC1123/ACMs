//��ȫ����
//f[i][c]=max(f[i-1][c-k*w[i]]+k*v[i]) 0=<k*w[i]<=m

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
int w[N],v[N];
int f[N][M];  //ǰi����Ʒ �������Ϊj�ı����е� ����ֵ 
int main()
{
	cin>>n>>m; //n����Ʒ m���ؼ��� 
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];  //ÿ����Ʒ�������ͼ�ֵ 
	} 
	for(int i=1;i<=n;i++) //����ÿһ����Ʒ 
	{
		for(int j=0;j<=m;j++) //�������ش�С���� ����ÿһ����Ϸ�ʽ 
		{
			for(int k=0;k*w[i]<=j;k++)
			{
				f[i][j]=max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
		} 
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++) //˳�� ��01���������� 
		{
			if(j>w[i])
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		 } 
	} 
	*/ 
	cout<<f[n][m]<<endl; 
	return 0;
}
