#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
char a[10],b[10];//�����a�� ��b��
//�˸�������Ծ 
int xx[]={-1,1,-1,1,-2,2,-2,2};
int yy[]={2,2,-2,-2,1,1,-1,-1};
int vis[10][10];
struct NODE{
	int x; //λ�� 
	int y;
	int step; //�߹��Ĳ��� 
}node,next,t;

int bfs()
{
	queue<NODE>q;
	int X,Y;
	node.x=a[0]-'a'+1;//���x 
	node.y=a[1]-'0';//���y 
	node.step=0;//��㲽��0 
	X=b[0]-'a'+1;//�յ�x 
	Y=b[1]-'0';//�յ�y 
	q.push(node);//node ������ 
	while(!q.empty()) //�Ӳ��յ�ʱ�� 
	{
		t=q.front(); //��ǰ ȡ���� 
		q.pop(); //���׳����� 
		if(t.x==X&&t.y==Y) //��ǰ =�յ�ʱ 
		{
			return t.step; //���ز��� 
		}
		for(int i=0;i<8;i++) //�˸����� 
		{
			next.x=t.x+xx[i]; //��һ��λ�� 
			next.y=t.y+yy[i]; //��һ��λ�� 
			if((next.x>=1&&next.x<=8)&&(next.y>=1&&next.y<=8)&&(!vis[next.x][next.y]))
			{
				vis[next.x][next.y]=1; //�������� ��һ��λ�� 
				next.step=t.step++; //��һ��λ�� ����+1 
				q.push(next); //��һ��λ����� 
			}
		}
		
	} 
}

int main()
{
	int minstep;
	while(scanf("%s %s",&a,&b)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		minstep=bfs();
		printf("To get from %s to %s takes %d knight moves.\n",a,b,minstep);
	}
} 

