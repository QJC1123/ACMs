//��β������� һ��Ҫ��ʼ��0 �� ���
//memset-ve ve->����    v.clear() 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath> 
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
const int maxn=1e5+10;
const ll INF=0x3f3f3f3f; 
int n; //n��ѡ�� 
int a,b; //Ͷ������ �ı������Ʊ�� 
vector<int>ve[maxn],v;
int mx; //mxΪ��ѡ�� 
int l,r,mid,midd;
ll result;

ll third(int t)
{
	int ans=0; //�ܵĻ�¸��� 
	int need=t-ve[0].size(); //��Ҫ�õ���Ʊ��-����Ʊ��=��ҪƱ��
	v.clear();
	for(int i=1;i<=mx;i++) //��iλ��ѡ�� 
	{
		for(int j=0;j<ve[i].size();j++) //��iλ��ѡ�� ��Ʊ�� 
		{
			if(ve[i].size()-j>=t) //��iλ��ѡ�� �ܵ�Ʊ��-��j��ѡ��Ʊ=ʣ�µ�Ʊ��>��Ҫ�õ���Ʊ�� 
			{
				ans+=ve[i][j]; //  ��iλ��ѡ��  ��j����¸���  ��С�����¸��� 
				need--; //����Ҫ��Ʊ�� 
			} 
			else //����i��ѡ�� ��Ʊ�� < ��Ҫ�õ���Ʊ��  
			    v.push_back(ve[i][j]); //��i����ѡ�� ��j����¸��� ���� v �� 
		}
	} 
	//�ó�ҪӮ��������ѡ�� �� ������ѡ�˶�Ӧ ��¸���  
	sort(v.begin(),v.end()); //��������¸�����С�������� 
	for(int i=0;i<need;i++) //��Ҫneed��Ʊ 
	{
		ans+=v[i]; //�ܵĻ�¸��� 
	}
	return ans; 
}

int main()
{
	while(~scanf("%d",&n))
	{
		v.clear();
		memset(ve,0,sizeof(ve));
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			ve[a].push_back(b); 
			mx=max(mx,a); //�ó���λ��ѡ�� 
		}
		for(int i=1;i<=mx;i++)
		{
			sort(ve[i].begin(),ve[i].end());//Ͷ����iΪ��ѡ�� �� ��¸����� ��С�������� 
		}
		l=0;
		r=n;
		while(l+2<r) //����ע��Ҫ���������У���Ϊ����lr��Ϊ������ڵ�ԭ�򣬻�©��֮��
		{
			mid=(l+r)/2;
			midd=(mid+r)/2;
			if(third(mid)>third(midd))
			l=mid;
			else
			r=midd;
		}
		result=INF;
		for(int i=l;i<=r;i++)
		{
			result=min(result,third(i));
		}
		cout<<result<<endl;
	}
	return 0;
}
