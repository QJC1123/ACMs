//����������г��� ���ɲ�������(�����п��ܶ�����ϣ�ֻ�󳤶ȣ�
// f[i]=max(f[j]+1) ��iΪ��β������������г���=iǰ��ĳ��jΪ��β����������г���+1 ��1=<j<i,a[j]<a[i]) 
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //��iΪ��β������������г��� 
	}
	int res=1; //��������������������г��� ��������Ϊ1 
	for(int i=1;i<=n;i++) //����������Ϊ��β 
	{
		for(int j=1;j<=i-1;j++) //i֮ǰ��Ԫ�� 
		{
			if(a[i]>a[j]) //����>ǰ�� 
			f[i]=max(f[i],f[j]+1); //ȡ��� i֮ǰ����������г���+1(i) 
		}
		res=max(res,f[i]); //����iΪ��β�ĳ����� �ҳ���󳤶� 
	}
	cout<<res<<endl; 
    return 0;	
}
