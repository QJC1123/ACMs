/*��������
�����߶���ݼ� 
һ��ϵͳ������ص������� �� ����������г��� 
�������е�������ϵͳ���� �� �������������ٻ�����=��������г��� 
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
const int N=1e4;
int n;
int a[N],f[N],g[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=1; //��iΪ��β����������г��� 
		g[i]=1; //��iΪ��β��������г��� 
	}
	int res=1;//����������г��� 
	int ans=1;//��������г��� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>=a[i])
			f[i]=max(f[i],f[j]+1); 
			if(a[j]<a[i])
			g[i]=max(g[i],g[j]+1);
		}
		res=max(res,f[i]);
		ans=max(ans,g[i]);
	} 
	cout<<res<<endl<<ans<<endl;
	return 0; 
} 
