//time limit
//����һ�� if(ans==1) break; 
//��̫���  whileѭ�������˼ 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ll long long
const int maxn=1e5+10;
ll a[maxn],s[maxn];
map<ll,ll>m;
int n,k; //n�ֻ�ѧ���� k-���� 
ll ans;//k�ķǸ������� 
ll cut;//��ЧƬ���� 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//n����ѧ���ʵ����ֵ 
		s[i]=s[i-1]+a[i]; //ǰ׺��Ԥ���� 
	} 
	ans=1;
	cut=0;
	while(abs(ans)<=1e14)
	{
		m.clear();
		m[0]=1; 
		for(int i=1;i<=n;i++) //Ƭ�������Ҷ˵�i 
		{
			//��ЧƬ�� ����� s[r]-s[l-1]=ans��k���ݣ� ��Ϊ s[l-1]=s[r]-ans  ��Ӧ�����l 
			cut+=m[s[i]-ans];//m��¼ÿһ�������Ҷ�r(i) ǰ׺�� ����  //i��ͬʱ ǰ׺���ж����ַ�ʽ�������s[i]-ans ���ж��ٸ�Ƭ��  �ж��ٸ��Ϸ�����˵� ���ж��ٸ�Ƭ�� 
			m[s[i]]++; //z��Ϊ��l 
		}
		ans*=k; //��һ���� 
		if(ans==1)
		  break;
	} 
	cout<<cut<<endl; 
} 
