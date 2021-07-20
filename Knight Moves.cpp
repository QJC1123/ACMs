#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
char a[10],b[10];//定义从a点 到b点
//八个方向跳跃 
int xx[]={-1,1,-1,1,-2,2,-2,2};
int yy[]={2,2,-2,-2,1,1,-1,-1};
int vis[10][10];
struct NODE{
	int x; //位置 
	int y;
	int step; //走过的步数 
}node,next,t;

int bfs()
{
	queue<NODE>q;
	int X,Y;
	node.x=a[0]-'a'+1;//起点x 
	node.y=a[1]-'0';//起点y 
	node.step=0;//起点步长0 
	X=b[0]-'a'+1;//终点x 
	Y=b[1]-'0';//终点y 
	q.push(node);//node 起点入队 
	while(!q.empty()) //队不空的时候 
	{
		t=q.front(); //当前 取队首 
		q.pop(); //队首出队列 
		if(t.x==X&&t.y==Y) //当前 =终点时 
		{
			return t.step; //返回步长 
		}
		for(int i=0;i<8;i++) //八个方向 
		{
			next.x=t.x+xx[i]; //下一步位置 
			next.y=t.y+yy[i]; //下一步位置 
			if((next.x>=1&&next.x<=8)&&(next.y>=1&&next.y<=8)&&(!vis[next.x][next.y]))
			{
				vis[next.x][next.y]=1; //符合条件 下一步位置 
				next.step=t.step++; //下一步位置 步长+1 
				q.push(next); //下一步位置入队 
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

