//��Դ���� �������
//һ����ֻ��һ����дԱ ��дԱ�ֵ�����ı������ ʹÿ����дԱ��дҳ�����ֵ������С 
//�ʱ��Ϊ��дҳ�������˵�ʱ��  �ٴ���ѡ��Сֵ 
//f[i][j]= min(max(f[i-1][k],f[i][j-k]))  ǰi���˳�дǰj����ʱ�� ��� =  ��С��ǰi-1���˳�дk���飬��i���˳�дj-k���� ���ܹ�����ʱ��Ϊ�����е����ʱ�䣩 
//f[i][j-k]=sum[j]-sum[k+1] ��һ���˳�дj-k���� ����ʱ�� Ϊ ��k+1���鵽��j�������ҳ�� �� 
//ÿ�������ٳ�1���� k>=i-1 j-k>=1 k<=j-1 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=510;
int m,k; 
int p[N],f[N][N],sum[N]; 

void prin(int i,int j) //i���� j���� 
{
	if(i==0) //û���� 
	{
		return ; //�ݹ���ֹ 
	}
	else if(i==1) //ʣ��1���� 
	{
		cout<<"1"<<" "<<j<<endl; //��д�ӵ�һ���� �� ��j����  ʣ��������һ���˳� 
	} 
	else
	{
		int a=j; //t������ʼ��ı�� ����ֹ���j�鿪ʼ��ǰ���� 
		int s=p[j]; //ʼ�鵽��ֹ���ҳ��sum ��ʼ��Ϊ���һ����ҳ�� ����ֹ�鿪ʼ��ǰ��
		while(s+p[j-1]<=f[k][m] && a>1) //��ʼ��ı�Ŵ���1 ��ʼ�鵽��ֹ���ҳ��sum+ǰһ���� ��������Сʱ�� ����ѭ�� 
	    {
	    	a--; //��ʼ��ı��=ǰһ���� 
	    	s+=p[a]; //��ʼ�鵽��ֹ���ҳ��=ԭ����+ǰһ����ҳ�� 
	    }
	    cout<<a<<" "<<j<<endl; //����ѭ�� �ҵ���ʼ����Ϊt ��ֹ����j 
	    prin(i-1,a-1); //�ݹ� ǰi-1���� ʣ��t-1���� ��ֹ����Ϊt-1 
	} 
} 

int main()
{
	sum[0]=0;
	memset(f,100,sizeof(f)); //*��ʼ����� ��������С 
	cin>>m>>k; //m���� k����дԱ 
	for(int i=1;i<=m;i++) 
	{
		cin>>p[i]; //��i�����ҳ�� 
		sum[i]=sum[i-1]+p[i]; //ǰi�������ҳ�� 
		f[1][i]=sum[i];
	} 
	for(int i=2;i<=k;i++) //i����дԱ 
	{
		for(int j=i;j<=m;j++) //��дj���� ÿ������1���� j����i  
		{
			for(int t=i-1;t<j;t++) 
			{
				f[i][j]=min(f[i][j],max(f[i-1][t],sum[j]-sum[t])); //i���˳�ǰj����������ʱ�����Сֵ
			}
		}
	}
	cout<<f[k][m]<<endl;  //k���˳�ǰm��������ʱ�����Сֵ
	prin(k,m); //m���� k���� 
	return 0; 
} 
