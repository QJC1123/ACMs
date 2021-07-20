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
int n,m; //n���� m���� 
int a,b;
vector<int>edge[M];

int dfn[M],low[M];
int index;
stack<int>s;
bool vis[M];
int num;

void tarjan(int u)
{
	dfn[u]=low[u]=++index; //��¼ʱ���
	s.push(u); //��ջ
	vis[u]=true; //�õ���ʹ�
	
	//���� ����u�ĳ��� 
	int size=edge[u].size(); //ָ�򼸸��� 
	for(int i=0;i<size;i++)
	{
		int v=edge[u][i]; //�յ�
		
		if(!dfn[v]) //v�ǵ�һ�α����� 
		{
			tarjan(v); //���� low���ܱ仯 
			low[u]=min(low[u],low[v]); //������� lowֵ 
		}
		else if(vis[v]) //֮ǰ������  V��ջ��  
		{
			low[u]=min(low[u],dfn[v]); 
		} 
		//ʣ��һ������Ƕ���V�Ѿ�����Ϊĳ��ǿ��ͨ�����еĶ������ 
	} 
	
	if(low[u]==dfn[u])  //ǿ��ͨ�����ĸ� 
	{
		int v;
		do{
			v=s.top();//���� 
			s.pop(); //��ջ
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

