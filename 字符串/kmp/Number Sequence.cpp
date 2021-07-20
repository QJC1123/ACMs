//ƥ���ַ��Ӵ���ĸ���еڼ���λ�ÿ�ʼ���� 

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
	int i=-1; //ǰһ�� 
	int j=0; //��һ�� 
	nextt[0]=-1;  
	while(j<len2) //����B�� 
	{
		if((i==-1)||(B[i]==B[j])) //ƥ��ɹ� 
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
		int j=F[i-1]; //ǰһ��λ�Ӷ�Ӧ�Ĳ���ƥ��ֵ 
		while(j>=0 && (b[j+1]!=b[i])) 
		j=F[j]; //��Ӧƥ��ֵ ��Ӧ�µ��±� 
		if(b[j+1]==b[i]) //ƥ��ɹ� 
		F[i]=j+1; // ��Ӧƥ��ֵΪǰһ���Ķ�Ӧƥ��ֵ+1 F[i]=F[i-1]+1 ��ͬǰ׺��׺�������+1 
		else //ƥ�䲻�ɹ� 
		F[i]=-1; //��Ӧƥ��ֵΪ-1 
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
	while(a<len1) //����a�� 
	{
		if(A[a]=B[b]) //a���е�i���ַ���b���е�j���ַ�ƥ�� 
		{
			a++;//i���� 
			b++;//j���� 
			if(j==len2) //b����a�����Ӵ�ƥ����� 
			{
				cout<<i-len2+1<<endl; //���ƥ����ʼ�� i��a���յ� len2��ƥ�䳤�� i-len2����ʼ���±꣨��0��ʼ��Ҫ+1 
			    j=F[j-1]+1;  //ƥ��ɹ� ��Ӧ�Ĳ���ƥ��ֵ+1 
			} 
		}
		else //a.b��ƥ�� 
		{
			if(j==0) //b����һ���Ͳ�ƥ�� 
			i++; //�Ƚ�a���е���һ����b�� 
			else //����b���ĵ�һ�� 
			j=F[i-1]+1; //b����ƥ��λ�ø�Ϊj��ǰһ��ƥ��λ�ö�Ӧ�Ĳ���ƥ��ֵ+1�� 
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

