//����������еĸ���

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
int a[N],f[N],cnt[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //��iΪ��β������������г��� 
		cnt[i]=1; //��iΪ��β������������еĸ��� 
	} 
	int res=1; //��������������������еĳ��� ����Ϊ1 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i])
			{
				if(f[j]+1>f[i]) //��jΪ��β�����������+1 > ��iΪ��β����������� 
				{
					f[i]=f[j]+1; 
					cnt[i]=cnt[j]; //��iΪ��β������������и��� ������jΪ��β��  
				}
				else if(f[j]+1==f[i]) //���ظ���һ�� ����ҲΪ��� 
				{
					cnt[i]+=cnt[j]; //���ظ��� ����iΪ��β�� �ټ����µ���jΪ��β�� �����и��� 
				}
			}
		} 
		res=max(res,f[i]); //������Ϊ��β ����������г��� �ҳ����� 
	}
	int ans=0; //����������еĸ��� 
	for(int i=1;i<=n;i++)
	{
		if(f[i]==res) //�ж������ȵ������� 
		ans+=cnt[i]; //���� �ۼ� ����i��Ϊ��β�������и���= 
	} 
	cout<<ans<<endl;
    return 0;	
} 
