#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#define ll long long 
using namespace std;
const ll N=1e5+10;
char str1[N],str2[N];
int cnt2[N],cntw,cnt1[N];
int main()
{
	scanf("%s %s",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len2;i++)
	{
		cnt2[str2[i]-'a']++; //p���и�����ĸ���ִ��� 
	}
	for(int i=0;i<len2;i++) //s���� ǰstrlen(p)���ַ� �и����ַ��ĳ��ִ��� 
	{
		if(str1[i]=='?')
		cntw++;  //s���� ǰlen2���ַ� �� �ʺŵĸ��� 
		else
		cnt1[str1[i]-'a']++; //s���� ǰlen2���ַ� �� ������ĸ�ĸ��� 
	}
	int t=0; 
	for(int j=0;j<26;j++) //������ĸ 
	{
		t+=abs(cnt2[j]-cnt1[j]); //��ͬһ�γ����� ����֮��������ĸ���� 
	}                           //��ͬ��ĸ �п���p�г��ִ������� 
	int ans=0;
	if(t<=cntw) //�ʺŶ��� ��ĸ������ 
	{
		ans++; 
	}
	for(int i=1;i<=len1-len2;i++) 
	{
		if(str1[i-1]=='?')
		cntw--;
		else
		cnt1[str1[i-1]-'a']--;
		if(str1[i+len2-1]=='?')
		cntw++;
		cnt1[str1[i+len2-1]-'a']++;
		t=0;
		for(int j=0;j<26;j++) //���㵱ǰ�������ĸ�� 
		{
			t+=abs(cnt1[j]-cnt2[j]);
		}
		if(t<=cntw) //��������
		{
			ans++; 
		}
	}
	cout<<ans<<endl;
    return 0;
}
