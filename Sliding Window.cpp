#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
const ll maxn=1e6;
ll n,k; //n������ k�����ڳ��� 
ll a[maxn],dl[maxn],id[maxn];  
int l,r; //��˵���� �Ҷ˵��β  

int main()
{
	while(cin>>n>>k)
	{
		memset(a,0,sizeof(a));
		memset(dl,0,sizeof(dl));
		memset(id,0,sizeof(id));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];   //n������ 
		}
		r=0;
		l=1;
		for(int i=1;i<=n;i++)  ///������Сֵ  ������������ 
		{
			while(l<=r && a[i]<=dl[r]) //����<��β ���� ������ <= ��β ɾ����β 
		      r--;  //r-˵���ص���һ�� �൱��ɾȥԭ����r 
			r++; //�����ִ��ڶ�β r++ ��һ����ʼ ���� 
			dl[r]=a[i]; //������һ��Ԫ���� ������ 
			id[r]=i; //��Ӧ������ �� ������ ��� 
			if(i-id[l]+1>k) // ��β����-��������+1 =���䳤�� > ���ڳ��� 
			  l++; //�������� ֱ�� ����=���ڳ��� 
			if(i>=k) //��β>=���ڳ��� ��i<k �������ڳ��� ���γɴ��ڣ� 
			  cout<<dl[l]<<" "; //��� ���� ��Сֵ 
		}
		cout<<endl;
		memset(dl,0,sizeof(dl)); //��ʼ������ 
		memset(id,0,sizeof(id));
		r=0;
		l=1;
		for(int i=1;i<=n;i++) // �����ֵ 
		{
			while( l<=r && a[i]>=dl[r] ) 
			  r--;
			r++;
			dl[r]=a[i];
			id[r]=i;
			if(i-id[l]+1>k) //id[l]+k<=i 
			  l++;
			if(i>=k)
			  cout<<dl[l]<<" ";
		}
		cout<<endl;
	}
} 
