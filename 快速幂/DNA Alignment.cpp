//compile error
// ����maxn string s ��Ϊ char s[maxn] 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath> 
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
const ll mod=1e9+7;//����const���� ����ȡģ 
const ll maxn=1e5+10;
const string t="ATCG";
int n;
char s[maxn];
map<char,ll>a;//ӳ�� char->ll 
ll maxx;
ll cnt;//���ִ���������ĸ ���� 
ll result;

int main()
{
	
	maxx=-1;
	result=1;
	cnt=0;
	cin>>n;//����n �ַ���s 
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		a[s[i]]++;
	}
	for(int i=0;i<4;i++) //ATCG���ҳ� s�г��ִ���������ĸ 
	{
		if(a[t[i]]>maxx) //���г��ִ����������ĸ����  
		{
			maxx=a[t[i]]; //���������ִ��� 
			cnt=1; //���ִ���������ĸ��Ϊ1�� 
		}
		else if(a[t[i]]==maxx) //�������������ִ���������ĸ 
		{
			cnt++; //���ִ���������ĸ����++ 
		}
	} 
	//�ҳ����ִ���������ĸ�����м���
	//������ base=num power=n; �ٶ�Mȡģ 
	while(n)
	{
		if(n&1)//if(n%2==1) ����
		{
			result=result*cnt%mod;
		} 
		n=n/2;// n>>=1; //ָ������ 
		cnt=cnt*cnt%mod;//������������ 
	}
	cout<<result<<endl;
	return 0;
}
