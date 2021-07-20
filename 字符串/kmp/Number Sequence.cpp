//匹配字符子串在母串中第几个位置开始出现 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std; 
const int N=1e6+10;
int t;
int len1,len2;
int A[N],B[N],nextt[N];
int a,b;

void getnext()
{
	int i=-1; //前一个 
	int j=0; //后一个 
	nextt[0]=-1;  
	while(j<len2) //遍历B串 
	{
		if((i==-1)||(B[i]==B[j])) //匹配成功 
		{
			i++; 
			j++;
			nextt[j]=i;
		}
		else
		{
			i=nextt[i];
		} 
	}
	/*
	for(int i=1;i<len2;i++)
	{
		int j=F[i-1]; //前一个位子对应的部分匹配值 
		while(j>=0 && (b[j+1]!=b[i])) 
		j=F[j]; //对应匹配值 对应新的下标 
		if(b[j+1]==b[i]) //匹配成功 
		F[i]=j+1; // 对应匹配值为前一个的对应匹配值+1 F[i]=F[i-1]+1 相同前缀后缀的最长长度+1 
		else //匹配不成功 
		F[i]=-1; //对应匹配值为-1 
	}
	*/
}

void kmp()
{
	getnext();
	a=0;
	b=0;
	while((a<len1)&&(b<len2))
	{
		if((b==-1)||A[a]==B[b])
		{
			a++;
			b++;
		}
		else
		{
			b=nextt[b];
		}
	}
	if(b==len2)
	{
		cout<<a-b+1<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
	/*
	while(a<len1) //遍历a串 
	{
		if(A[a]=B[b]) //a串中第i个字符与b串中第j个字符匹配 
		{
			a++;//i后移 
			b++;//j后移 
			if(j==len2) //b串与a串中子串匹配完毕 
			{
				cout<<i-len2+1<<endl; //输出匹配起始点 i是a串终点 len2是匹配长度 i-len2是起始点下标（从0开始）要+1 
			    j=F[j-1]+1;  //匹配成功 对应的部分匹配值+1 
			} 
		}
		else //a.b不匹配 
		{
			if(j==0) //b串第一个就不匹配 
			i++; //比较a串中的下一个与b串 
			else //不是b串的第一个 
			j=F[i-1]+1; //b串的匹配位置改为j（前一个匹配位置对应的部分匹配值+1） 
		}
	} 
	*/
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>len1>>len2;
		for(int i=0;i<len1;i++)
		cin>>A[i];
		for(int i=0;i<len2;i++)
		cin>>B[i];
		kmp();
	}
	return 0;
}

