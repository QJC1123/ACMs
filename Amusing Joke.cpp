#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	char str1[105],str2[105];
	int a[26];
	char letter[220];
	scanf("%s",str1);
	scanf("%s",str2);
	scanf("%s",letter);
	for(int i=0;i<26;i++)
	{
		a[i]=0;
	}
	for(int i=0;str1[i]!='\0';i++)
	{
		a[str1[i]-'A']++;
	}
	for(int i=0;str2[i]!='\0';i++)
	{
		a[str2[i]-'A']++;
	}
	for(int i=0;letter[i]!='\0';i++)
	{
		a[letter[i]-'A']--;
	}
	int i;
	for(i=0;i<26;i++)
	{
		if(a[i]!=0)
		{
			break;
		}
	}
	if(i==26)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}

