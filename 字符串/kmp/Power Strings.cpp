//最小循环节
//有几个最小循环节 
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
	
void pre()
{
	nextt[0]=-1;
	int k=-1;
	int j=0;
	while(j<len)
	{
		if((k==-1)||(str[j]==str[k]))
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



int main()
{
	while(~scanf("%s",str))
	{
		if(str[0]=='.')
		break;
		len=strlen(str);
		memset(nextt,0,sizeof(nextt));
		pre();
		int L=len-nextt[len];
		if(len%L==0)
		{
			ans=len/L;
			cout<<ans<<endl;
		} 
		else
		{
			cout<<"1"<<endl; 
		}
	}
	return 0;
}
