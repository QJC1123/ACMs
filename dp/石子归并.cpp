/*ʯ�ӹ鲢 ����dp 
4 1 2 3 4 
����С�ϲ�����
[l,r]������ 
�ܵĺϲ�����=[l][k]�ϲ��Ĵ���+[k+1][r]�ϲ��Ĵ���+[l,r]ʯ������ 
״̬ dp[i][j] ��i�ѵ���j�ѵ�ʯ�Ӻϲ���С����
״̬���� ���һ�εĲ���  
״̬ת�Ʒ��� dp[i][j]=min(dp[i][k]+dp[i+1][k])+sum[i,j]; 
�߽���� ���䳤��Ϊ1 i=j f[i][j]=0 
Ԥ���� dp[i][j] Ԥ����Ϊ�ϴ����->����С 
״̬ת�Ʒ��� ���䳤��С->��
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=120;
const ll INF=0x3f3f3f3f;
int n;
int a[N],s[N];
int f[N][N]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i]; //ǰ׺�� ������һ��������ʯ������ s[l]-s[r-1]=sum(l,r) 
	}
	for(int len=2;len<=n;len++) //���䳤��ö�� �ϲ�����2�� ��������Ϊ2 
	{
		for(int i=1;i+len-1<=n;i++) //ö����˵� 
		{
			int j=i+len-1; //�����䳤���µ��Ҷ˵� 
			f[i][j]=INF; //Ԥ���������Ϊ���ֵ  
			for(int k=i;k<j;k++) //k�ָ�ȥ���� 
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]); //���һ�κϲ����� ->z״̬����->״̬�ƶ�����  
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
} 
 

