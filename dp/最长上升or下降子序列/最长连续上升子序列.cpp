//��������������� 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
const int N=1e5;
int n;
int a[N],f[N]; 
int main()
{
	int res=1; //������������������������г��� 
	int id; //��������� 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //��iΪ���������г��� 
	}
	for(int i=1;i<=n;i++) //����������Ϊ��β 
	{
		for(int j=i+1;j<=n;j++) 
		{
			if(a[j-1]<a[j]) //����>ǰ��  
			f[i]++; //ÿ��һ�� ����+1
			else //�����ֲ���������  
			break; //�˳�ѭ�� (����) 
		} 
		/*if(f[i]>res)
		{
	       res=f[i];
	       id=i;
	    }*/
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]>res)
		{
			res=f[i];
			id=i;
		}
	} 
	for(int i=id;i<id+res-1;i++)
	{
		cout<<a[i]<<" ";
	} 
	cout<<endl<<res<<endl;
	return 0;
 } 
