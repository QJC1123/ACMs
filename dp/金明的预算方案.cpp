//������Ԥ�㷽��  �������� 
//���鱳��
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=35000;
int n,m;//��Ǯ��n ��Ʒ����m
int v[N],p[N],q[N],a[N]; //�۸� ��Ҫ�� ����/���� 
int f[N][N];
int num[5];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>p[i]>>q[i];
		p[i]*=v[i]; // ����Ҫ�Ⱥͼ۸�˻��ܺ���� 
	}
	for(int i=1;i<=m;i++)
	{
		if(q[i]==0) //����
		{
			for(int j=1;j<v[i];j++)
		    {
		    	a[j]=0;
			}
		} 
	}
	
	return 0;
} 
