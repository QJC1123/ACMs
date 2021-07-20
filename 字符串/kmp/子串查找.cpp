//�Ӵ���ĸ���г����˼��Σ��������ظ��ģ�
//kmp ���Ͷ�

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
		if((k==-1) || (str2[k]==str2[j])) //ƥ����ͬ ���ַ�ͬ��ǰ�� 
		{
			k++;
			j++;
			nextt[j]=k; //��ǰλ��ǰ��һ���ַ������� ǰ��׺�����󳤶� Ϊƥ��ɹ����±� 
		}
		else 
		{
			k=nextt[k]; //ƥ�䲻ͬ ���� ǰ��׺�����󳤶� ��Ӧ��λ�� 
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
		j=nextt[j]; //���� ֱ���Ƚ��ַ���ͬ 
		if(str1[i+1]==str2[j+1]) //��ƥ��  ͬ��ǰ�� 
		{
			i++;
			j++;
		}
		else //��ƥ��  str1ǰ�� 
		{
			i++;
		}
		if(j==len2-1) //�Ӵ�ƥ��ɹ� �ҵ��� 
		{
			ans++; 
			j=nextt[j]; //���� ����һ�� 
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
