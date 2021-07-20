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
		cnt2[str2[i]-'a']++; //p串中各个字母出现次数 
	}
	for(int i=0;i<len2;i++) //s串中 前strlen(p)个字符 中各个字符的出现次数 
	{
		if(str1[i]=='?')
		cntw++;  //s串中 前len2个字符 中 问号的个数 
		else
		cnt1[str1[i]-'a']++; //s串中 前len2个字符 中 各个字母的个数 
	}
	int t=0; 
	for(int j=0;j<26;j++) //各个字母 
	{
		t+=abs(cnt2[j]-cnt1[j]); //相同一段长度内 两串之间相差的字母个数 
	}                           //相同字母 有可能p中出现次数更多 
	int ans=0;
	if(t<=cntw) //问号多于 字母相差个数 
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
		for(int j=0;j<26;j++) //再算当前的相差字母数 
		{
			t+=abs(cnt1[j]-cnt2[j]);
		}
		if(t<=cntw) //符合条件
		{
			ans++; 
		}
	}
	cout<<ans<<endl;
    return 0;
}
