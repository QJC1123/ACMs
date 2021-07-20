#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int t;//���������ĸ��� 
int m,n;//�Թ�������������
char map[100][100];//�Թ���ͼ�ַ� 
int visit[100][100];//����Ƿ��߹�ĳ�� 
int flag;//�ж��ܷ��յ� 
struct NODE{
	int x;
	int y;
	int k;
}now,next,temp;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//�ƶ��ĸ����� 
int x1,x2,y1,y2;//����յ� 
int k;//�������� 

int check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='.')
	    return 1;
	return 0;
}

void bfs()
{
	queue<NODE>q;
	now.x=x1;
	now.y=y1;
	now.k=-1;
	visit[x1][y1]=1;
	q.push(now);
	while(!q.empty())//while(q.size())
	{
		now=q.front();  
		q.pop(); 
		if(now.x==x2&&now.y==y2&&now.k<=k) //Ŀ��״̬�� 
		{
			flag=1;
			return ;//���������� 
		}
		for(int i=0;i<4;i++) //�ĸ����� 
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			while(check(next.x,next.y))//����һ�ص����ϰ� ������  
			{
				if(!visit[next.x][next.y]) //����һ�ص�û�б����ʹ� 
				{
					next.k=now.k+1;//����+1 ������ 
				    visit[next.x][next.y]=1;//��Ƿ��� 
			    	q.push(next);//�¸��ص���� 
				}
				temp.x=next.x+dir[i][0];  //��ͬһ�������� 
				temp.y=next.y+dir[i][1];
				next=temp;
			}
		} 
	} 
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>map[i][j];
			}
		}
		memset(visit,0,sizeof(visit));
		cin >> k >> y1 >> x1 >> y2 >> x2;
		x1--;
		x2--;
		y1--;
		y2--;
		//ԭ����1��ʼ ��һ ��Ϊ��0��ʼ 
		flag=0;
		bfs();
		if(flag)
		{
			cout<<"yes"<<endl; 
		} 
		else
		{
			cout<<"no"<<endl;
		}
	} 
	return 0;
} 
