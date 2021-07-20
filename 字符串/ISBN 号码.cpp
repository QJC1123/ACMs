//×Ö·û´® 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	char str[15];
	scanf("%s",str);
	int t=0;
	int ans=0;
	for(int i=0;i<11;i++)
	{
		if(str[i]!='-')
		{
			t++;
			ans=(int)(str[i])*t;
		}
	}
	if(ans%11==(int)(str[12]))
	cout<<"Right"<<endl;
	else
	str[12]=(char)(ans%11);
	printf("%s",str);
	return 0;
}
