#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;//n��m��
int p; //��װ�ļ��������� 
int q; //С͵������ 
int **b=new int*[n+2];

void accumulation()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		//��̬��ά���� 
		//n+1�� 
		for(int i=0;i<=n+1;i++)
		{
			b[i]=new int[m+2];//m+1�� 
		}
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=m+1;j++)
			{
				b[i][j]=0; //��ʼ��Ϊ0 
			}
		} 
		//ԭ���������������� 0 
		scanf("%d",&p);
		while(p--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			b[x1][y1]++;
			b[x2+1][y1]--;
			b[x1][y2+1]--;
			b[x2+1][y2+1]++;
		} 
		//�Բ��������и��� //װ�ϼ�غ�ɿ���������ı� ʹװ��ص������� 1 
		accumulation();
		//��ǰ׺�Ͷ�ά���� װ�ϼ�ص��������ڿ����ظ� ʹ�ü������ֵ>1 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j])
				{
					b[i][j]=1;
				}
			}
		} 
		//ǰ׺�Ͷ�ά���� �������>1�ĸ�Ϊ=1   ���Ϊװ������� 1 �޼�� 0 
		accumulation();
		//����������� ����Ԥ����  �õ�ԭ�Ȱ���Ԫ�أ�0/1���ĺ� 
		scanf("%d",&q); 
		while(q--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ll area;  //��� �˷�Χ���м�ظ��� ����� �����1�� 
			area=b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1];  
			if(area==(ll)(x2-x1+1)*(y2-y1+1)) //С͵�������   
			{
				printf("YES\n"); //��� ���ܼ�ص�С͵ 
			}
			else  
			{
				printf("NO\n");
			}	
		} 
	}
}
