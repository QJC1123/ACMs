//��ǰ��Сѭ�������ַ����ĸ����������Բ��ַ�����
//�ַ���ǰ׺�Ƿ�Ϊ���ڴ� ���� ��ѭ���ڳ��Ⱥ�ѭ������ 
//����һ�ַ������ҳ���2����2��������ͬ�����ַ�����ɵ�ǰ׺�����ǰ׺���ȼ�����ͬ�����ַ�������
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std; 
const ll N=1e6+10;
char str[N];
int len;
ll nextt[N];
int ans;
int t;

void pre()
{
	nextt[0]=-1;
	int k=-1,j=0;
	while(j<len)
	{
		if((k==-1)||(str[k]==str[j]))
			nextt[++j]=++k;
		else
		    k=nextt[k];
	}
 
}

int main()
{
	int Case=1;
	while(cin>>len)
	{
		if(len==0)
		break;
		scanf("%s",str);
		pre();
		cout<<"Test case #"<<Case<<endl;
		Case++;
		for(int i=1;i<=len;i++)
		{
			int L=i-nextt[i];
			if(i%L==0&&i!=L)
			{
				ans=i/L;
				cout<<i<<" "<<ans<<endl;
			}
		}
		cout<<endl;
	}
} 
