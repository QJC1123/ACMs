//�������� 01���� 
//f[i][c]=max(f[i-1][c],f[i-1][c-w[i]]+v[i]) 
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
	for(int i=1;i<=n;i++) //��i����Ʒ 
	{
		for(int j=0;j<=m;j++) //�������� ������ 
		{
			if(j>=w[i]) //�������ش��ڵ�i����Ʒ������  ������ 
			f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]); //ѡ��ֵ���� 
			else
			f[i][j]=f[i-1][j];
		} 
	} 
	/*�Ż� 
	for(int i=1;i<=n;i++) 
	{
	   for(int j=m;j>=0;j--) //���� 
	   {
	      if(j>w[i])
	      f[j]=max(f[j],f[j-w[i])+v[i]; //��֤f[j]û�б���i����Ʒ���¹� ����i-1���״̬  
       }
   } 
   ��һ�������Ż� 
	int bound=0;
	int sumw=0;
	for(int i=1;i<=n;i++) 
	{
		sumw+=w[i];
		bound=max(m-sumw,w[i]); //����ʣ����� �� ��ǰ��Ʒ���� �Ƚ� 
		for(int j=m;j>=bound;j--)
		{
			if(j>w[i])
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	*/
	cout<<f[n][m]<<endl; 
	return 0;
} 
 
