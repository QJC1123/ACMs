//需要再补几个字符能构成一个类似手链那样循环相同的
//最小循环节
//在串头或尾添加字符,使该串至少有2个循环节
//求最少需要加几个字符

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
		{
			k++;
			j++;
			nextt[j]=k;
		}
		else
		    k=nextt[k];
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%s",str);
		len=strlen(str);
		pre();
		int L=len-nextt[len];
		if(len%L==0&&len!=L) //abcde len=5 L=5 
		cout<<"0"<<endl;
		else 
		{
			ans=L-len%L;
			cout<<ans<<endl;
		}
	}
	return 0;
}
