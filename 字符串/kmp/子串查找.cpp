//子串在母串中出现了几次（可以有重复的）
//kmp 类型二

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std; 
const ll N=1e6+10;
char str1[N],str2[N];
int len1,len2;
ll nextt[N];
int ans;
void pre()
{
	nextt[0]=-1;
	nextt[1]=0;
	int k=-1,j=0;
	while(j<len2-1)
	{
		if((k==-1) || (str2[k]==str2[j])) //匹配相同 两字符同步前进 
		{
			k++;
			j++;
			nextt[j]=k; //当前位置前的一段字符区间里 前后缀相等最大长度 为匹配成功的下标 
		}
		else 
		{
			k=nextt[k]; //匹配不同 返回 前后缀相等最大长度 对应的位置 
		}
	}
}

void kmp()
{
	pre();
	int i=-1,j=-1;
	while(i<0||i<len1)
	{
		while(j>=0&&str1[i+1]!=str2[j+1])
		j=nextt[j]; //回溯 直到比较字符相同 
		if(str1[i+1]==str2[j+1]) //若匹配  同步前进 
		{
			i++;
			j++;
		}
		else //不匹配  str1前进 
		{
			i++;
		}
		if(j==len2-1) //子串匹配成功 找到答案 
		{
			ans++; 
			j=nextt[j]; //回溯 找下一个 
		}
	}
}

int main()
{
	ans=0;
	scanf("%s%s",str1,str2);
	len1=strlen(str1);
	len2=strlen(str2); 
	kmp();
	printf("%d\n",ans);
	return 0;
} 
