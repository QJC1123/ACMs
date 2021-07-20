//母串中最多有几个子串 (不能重复） 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std; 
const int N=1e3+10;
char str1[N],str2[N];
int nextt[N];
int len1,len2;
int ans;

void pre()
{
    nextt[0]=-1;
	int k=-1;
	int j=0;
	while(j<len2)
	{
		if((k==-1)||(str2[k]==str2[j]))
		{
			k++;
			j++;
			nextt[j]=k;
		}
		else
		{
			k=nextt[k];
		}
	}
}

void kmp()
{
	pre();
	int i=0,j=0;
	while(i<len1)
	{
		while(j>0&&str1[i]!=str2[j])
		j=nextt[j-1]; //回溯 直到比较字符相同 
		if(str1[i]==str2[j]) //若匹配  同步前进 
		{
			i++;
			j++;
		}
		else
		i++;
		if(j==len2) //子串匹配成功 找到答案 
		{
			ans++; 
			j=0; 
		}
	}
} 

int main()
{
	while(~scanf("%s",str1))
	{
		ans=0;
		
		if(str1[0]=='#')
		break;
		
		scanf("%s",str2);
		
		len1=strlen(str1);
		len2=strlen(str2);
		
		kmp();
		
		printf("%d\n",ans);
	}
	return 0;
} 
