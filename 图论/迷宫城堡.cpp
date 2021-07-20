#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int M=1e5+10;
int n,m; //n个点 m条边 
int a,b;
vector<int>edge[M];

int dfn[M],low[M];
int index;
stack<int>s;
bool vis[M];
int num;

void tarjan(int u)
{
	dfn[u]=low[u]=++index; //记录时间戳
	s.push(u); //入栈
	vis[u]=true; //该点访问过
	
	//访问 顶点u的出边 
	int size=edge[u].size(); //指向几个点 
	for(int i=0;i<size;i++)
	{
		int v=edge[u][i]; //终点
		
		if(!dfn[v]) //v是第一次被搜索 
		{
			tarjan(v); //搜索 low可能变化 
			low[u]=min(low[u],low[v]); //更新起点 low值 
		}
		else if(vis[v]) //之前搜索过  V在栈中  
		{
			low[u]=min(low[u],dfn[v]); 
		} 
		//剩余一种情况是顶点V已经被作为某个强连通分量中的顶点输出 
	} 
	
	if(low[u]==dfn[u])  //强连通分量的根 
	{
		int v;
		do{
			v=s.top();//顶点 
			s.pop(); //出栈
			num++; 
		}while(u!=v);
	}
}

int main()
{
	while(cin>>n>>m)
	{
		index=0;
		num=0;
		memset(vis,0,sizeof(0));
		for(int i=1;i<=n;i++)
		    edge[i].clear(); 
		
		if(n==0&&m==0)
		break;
		
		for(int i=0;i<m;i++)
		{
			cin>>a>>b; 
			edge[a].push_back(b);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i])
			   tarjan(i); 
		}
		
		if(num==n)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
} 

