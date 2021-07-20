//最大公约数 差分 
//gcd(a,b)=gcd(a,b-a); gcd(a,b,c)=gcd(a,b-a,c-b); gcd(a1,a2,a3,a4,a5…an)=gcd(a1,a2-a1,a3-a2,a4-a3,…an-an-1);

///???? no ac
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std; 
int t;
int a[3];
int b[3];
int ans;
int gcd(int x,int y)
{
	int temp=x%y;
	while(temp>0)
	{
		x=y;
		y=temp;
		temp=x%y;
	}
	return y;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		maxgcd=gcd(a[0],gcd(a[1],a[2]));
		
		
		
		
		
		b[0]=a[1]-a[0];
		b[1]=a[2]-a[1];
		sort(b,b+2);
		ans=gcd(a[0],gcd(b[0],b[1]));
		cout<<ans<<endl;
	}
	return 0;
} 
