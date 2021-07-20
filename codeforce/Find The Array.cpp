#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5200;
int t,s;
int a[N];
int n,sum;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		sum=0;
		n=0;
		int i=1;
		while(i<=N)
		{
			sum+=i;
			n++;
			i+=2; //1 3 5 7 ...
			if(sum>=s) //11 12 n也是一样的 长度 
			{
				cout<<n<<endl;
				break;
			}
		}
	}
	return 0;
}
