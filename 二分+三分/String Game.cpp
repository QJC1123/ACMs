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

bool check(int mid) //检查能否有字串 
{
	memset(visit,false,sizeof(visit));
	for(int i=mid+1;i<len1;i++) //一列数字中 后面未进行的操作  
	{
		visit[a[i]]=true; //未删去的字母序号 =true 
	} 
	int cnt=0;
	for(int i=0;i<len1;i++) //遍历字符串 
	{
		if(visit[i]) //第i个字母 不准备被删去 
			term[cnt++]=p[i]; //将这第i个字母 存入term数组中  按照原来字符串的先后顺序 
	}
	if(cnt<len2) //不准备删除的字母个数cnt <len  最后留存的字符串长度<目标字符串长度 
	    return false; //不成立
	int loc=0;
	for(int i=0;i<cnt;i++) //最终保存下的字符串 与 目标字符串 比较 
	{
		if(term[i]==t[loc])
		{
			loc++;
			if(loc==len2) //比较结束  之前的两串字符都相等 
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
			if(check(mid)) //删到mid处 成立 
			{
				result=mid;
				l=mid+1; //删的更多 
			}
			else
			    r=mid-1; 
		}
		cout<<result+1<<endl;
	}
	return 0;
} 
