#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int t;//测试组数的个数 
int m,n;//迷宫的行数和列数
char map[100][100];//迷宫地图字符 
int visit[100][100];//标记是否走过某点 
int flag;//判断能否到终点 
struct NODE{
	int x;
	int y;
	int k;
}now,next,temp;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//移动四个方向 
int x1,x2,y1,y2;//起点终点 
int k;//最大拐弯数 

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
		if(now.x==x2&&now.y==y2&&now.k<=k) //目标状态下 
		{
			flag=1;
			return ;//返回主函数 
		}
		for(int i=0;i<4;i++) //四个方向 
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			while(check(next.x,next.y))//若下一地点无障碍 不出界  
			{
				if(!visit[next.x][next.y]) //若下一地点没有被访问过 
				{
					next.k=now.k+1;//拐弯+1 ？？？ 
				    visit[next.x][next.y]=1;//标记访问 
			    	q.push(next);//下个地点入队 
				}
				temp.x=next.x+dir[i][0];  //往同一个方向走 
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
		//原本从1开始 减一 改为从0开始 
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
