#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=2e5+10;
char p[maxn];
char t[maxn];
int l,r,mid,result;
int len1,len2;
bool visit[maxn];
char term[maxn];
int a[maxn];

bool check(int mid) //����ܷ����ִ� 
{
	memset(visit,false,sizeof(visit));
	for(int i=mid+1;i<len1;i++) //һ�������� ����δ���еĲ���  
	{
		visit[a[i]]=true; //δɾȥ����ĸ��� =true 
	} 
	int cnt=0;
	for(int i=0;i<len1;i++) //�����ַ��� 
	{
		if(visit[i]) //��i����ĸ ��׼����ɾȥ 
			term[cnt++]=p[i]; //�����i����ĸ ����term������  ����ԭ���ַ������Ⱥ�˳�� 
	}
	if(cnt<len2) //��׼��ɾ������ĸ����cnt <len  ���������ַ�������<Ŀ���ַ������� 
	    return false; //������
	int loc=0;
	for(int i=0;i<cnt;i++) //���ձ����µ��ַ��� �� Ŀ���ַ��� �Ƚ� 
	{
		if(term[i]==t[loc])
		{
			loc++;
			if(loc==len2) //�ȽϽ���  ֮ǰ�������ַ������ 
			    break; 
		}
	} 
	if(loc==len2)
	  return true; 
	else
	  return false;
}

int main()
{
	while(~scanf("%s",p))
	{
		scanf("%s",t);
		len1=strlen(p);
		len2=strlen(t);
		for(int i=0;i<len1;i++)
		{
			cin>>a[i];
			a[i]--;
		}
		l=0;
		r=len1-1;
		result=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid)) //ɾ��mid�� ���� 
			{
				result=mid;
				l=mid+1; //ɾ�ĸ��� 
			}
			else
			    r=mid-1; 
		}
		cout<<result+1<<endl;
	}
	return 0;
} 
