#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int a[210],n,flag[210]; 
void bfs(int s,int t)
{
	int v;
	queue<int>q;
	q.push(s);
	flag[s]=1;
	while(!q.empty()) 
	{
		v=q.front();
		q.pop();
		if(v==t)
		  break;
		if(v+a[v]<=n&&flag[v+a[v]]==0)
		{
			q.push(v+a[v]);
			flag[v+a[v]]=flag[v]+1;
		}
		if(v-a[v]>=1&&flag[v-a[v]]==0)
		{
			q.push(v-a[v]);
			flag[v-a[v]]=flag[v]+1;
		}
	}
	if(v!=t)
	{
		flag[t]=0;
	}
	
}

int main()
{
	int i,s,t;
	while(scanf("%d %d %d",&n,&s,&t),n!=0)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(flag,0,sizeof(flag));
		bfs(s,t);
		printf("%d\n",flag[t]-1);
	}
	return 0;
} 




#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring> 
using namespace std;
int n; //n��¥ �ӵ�a�㵽��b�� 
int k[500];//��k��¥ �ƶ��Ĳ��� 
int flag[500]; //���ʹ��� ��0 ��1  //����ť�Ĵ��� û���ʹ� ����0���� ���ʹ� ���ʵ���ʱ��¼�����˼���  

void bfs(int a,int b)
{
	int now; //���� 
	queue <int> q;//����q 
	q.push(a); //��ʼ�������
	flag[a]=1;//��ʼ�������ʹ�
	while(!q.empty())//q����ʱѭ�� 
	{
		now=q.front();//��ǰ�Ƕ���Ԫ�� 
		q.pop();//�Ƴ���ǰԪ�� ������  ֱ������Ϊ�� 
		if(now==b) //��ǰ����¥��b 
			break;  //�˳�ѭ�� 
			
		if(now+k[now]<=n&&flag[now+k[now]]==0) //�����ƶ��󲻳���¥���� �Ҹ�¥��δ�����ʹ� 
		{
			q.push(now+k[now]);//�����ƶ��󵽴��¥��
			flag[now+k[now]]=flag[now]+1; //��ǰ¥�� �ƶ��󵽴�¥��  ��ť������+1 
		}
		if(now-k[now]>=1&&flag[now-k[now]==0]) //�����ƶ�  
		{
			q.push(now-k[now]); //�ƶ����¥��δ�����ʹ���������� 
			flag[now-k[now]]=flag[now]+1; //��ť�������Լ�1 
		} 	
	}
    if(now!=b) //ѭ������ �������еĶ�û�е���¥��b 
		flag[b]=0;//�򵽴�¥��b�İ�ť��������0-1 �����������flag-1 
} 



int main()
{
	int a,b;
	while(scanf("%d%d%d",&n,&a,&b),n!=0)
	{
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);     //����k��¥��Ӧ���ƶ����� //û�е�0�� 
		}
		memset(flag,0,sizeof(flag)); //ͷ�ļ� cstring 
		bfs(a,b);
		printf("%d\n",flag[b]-1);//������ʼ�ڵ� ��������Ϊ0 (flag-1) 
	}
	return 0;
}
