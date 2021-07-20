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
int n; //n层楼 从第a层到第b层 
int k[500];//第k层楼 移动的层数 
int flag[500]; //访问过无 无0 有1  //按按钮的次数 没访问过 按动0次数 访问过 访问到此时记录按动了几次  

void bfs(int a,int b)
{
	int now; //现在 
	queue <int> q;//队列q 
	q.push(a); //起始层数入队
	flag[a]=1;//起始层数访问过
	while(!q.empty())//q不空时循环 
	{
		now=q.front();//当前是队首元素 
		q.pop();//移出当前元素 即队首  直到队列为空 
		if(now==b) //当前到达楼层b 
			break;  //退出循环 
			
		if(now+k[now]<=n&&flag[now+k[now]]==0) //向上移动后不超过楼层数 且该楼层未被访问过 
		{
			q.push(now+k[now]);//移入移动后到达的楼层
			flag[now+k[now]]=flag[now]+1; //当前楼层 移动后到达楼层  按钮按动数+1 
		}
		if(now-k[now]>=1&&flag[now-k[now]==0]) //向下移动  
		{
			q.push(now-k[now]); //移动后的楼层未被访问过，加入队列 
			flag[now-k[now]]=flag[now]+1; //按钮按动数仍加1 
		} 	
	}
    if(now!=b) //循环结束 找完所有的都没有到达楼层b 
		flag[b]=0;//则到达楼层b的按钮按动数是0-1 下面最后结果是flag-1 
} 



int main()
{
	int a,b;
	while(scanf("%d%d%d",&n,&a,&b),n!=0)
	{
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);     //输入k层楼对应的移动层数 //没有第0层 
		}
		memset(flag,0,sizeof(flag)); //头文件 cstring 
		bfs(a,b);
		printf("%d\n",flag[b]-1);//访问起始节点 按动次数为0 (flag-1) 
	}
	return 0;
}
