#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=120;
int t;
int n,a,b;
char s[N];
int l;
int ans;
int cnt0,cnt1;
int flag0,flag1;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		scanf("%s",s);
		cnt0=cnt1=0;
		flag0=0;
		flag1=0;
		if(b>=0)
		{
			cout<<a*n+b*n<<endl;
		}
		else // 00011001011100
		{
			for(int i=0;i<=n;i++)
			{
				if(s[i]=='0')
				{
					if(flag0==0)
					{
						cnt0++;
						flag0=1;
						flag1=0;
					}
				}
				else if(s[i]=='1')
				{
					if(flag1==0)
					{
						cnt1++;
						flag0=0;
						flag1=1;
					}
				}
			}
			cout<<a*n+(min(cnt0,cnt1)+1)*b<<endl;
		}
	}
	return 0;
}
