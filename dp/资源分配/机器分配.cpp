//��Դ����dp �������� 
//f[i][j]=max(f[i-1][j-k]+a[i][k]) ǰi-1�ҹ�˾ ����j-k������ + ��i�ҹ�˾����k������ =ǰi�ҹ�˾����j������ 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=20;
int n,m; 
int a[N][N],f[N][N];//ǰi����˾����j̨����������� 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j]; //��i����˾����j̨���������� 
		}
		f[i][0]=0; //�߽� 
	}
	for(int i=1;i<=n;i++) //ǰi�ҹ�˾ 
	{
		for(int j=1;j<=m;j++) //j������ 
		{
			for(int k=0;k<=j;k++) //��i�ҹ�˾����k������ 0-j ����ǰi-1��0̨�������i��0̨���� 
			{
				f[i][j]=max(f[i][j],f[i-1][j-k]+a[i][k]); 
			} 
		} 
	} 
	cout<<f[n][m]<<endl; //ǰn�ҹ�˾����m̨���� 
	return 0;
} 
