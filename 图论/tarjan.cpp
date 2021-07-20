//tarjan 得到强连通分量 

int dfn[maxn],low[maxn],scc[maxn],stk[maxn];
int index=0,sccnum=0,top=0;

void tarjan(int root)
{
	if(dfn[root]) //记录有无访问到 
	return ; 
	dfn[root]=low[root]=++index; //初始化 访问到的序号 
	stk[++top]=root; //用栈来维护  这个点入栈 这个点之后的子树是哪些一起构成强连通分量的
	for(int i=head[root];~i;i=e[i].ne) //遍历该点指出去的边 
	{
		int v=e[i].to; //这个点指出去的对应的点
		if(!dfn[v]) //若v点未被访问过 
		{
			tarjan(v);
			low[root]=min(low[root],low[v]); //更新low数组 
		} 
		else if(!scc[v]) //若还在栈内 
		{
			low[root]=min(low[root],dfn[v]);
		}
	}
	if(low[root]==dfn[root])//后代不能找到更浅的点  强连通分量 
	{
		sccnum++;  //几个强连通分量 
		for(;;)
		{
			int x=stk[top--];
			scc[x]=sccnum; //记录的是这个点属于哪个强连通分量
			if(x==root)
			break; 
		}
	}
}

//缩点 重建图 有向无环图
/*
一个有向图 N个点 
①至少几个点 才能使从这些点出发 到达所有顶点 -->缩点后 几个入度为0 的点 
②至少加几条边 才能使从任一顶点出发 到达所有顶点-->缩点后  怎样形成环 
max(入度为0的点数 出度为0的点数 ） 出度为0 连向入度为0 形成环  
特判scc只有一个 则为0 只有自己一个强连通分量 不连边 
*/

//割点 桥
/*
有割点不一定有桥 有桥一定存在割点
桥一定是割点依附的边 
*/ 

//双连通分量 （无向图）
/*
边双连通  不存在桥 
点双连通  不存在割点 
*/ 

//tarjan 求边双连通分量
void tarjan(int root)
{
	dfn[root]=low[root]=++index;//初始化 
	st[++top]=root;//结点入栈
	gson(i,root) //遍历root指出去的边 
	{
		int v=edge[i].v;
		if(ef[i]) continue;
		ef[i]=ef[i^1]=1;//标记走过的边 
		if(!dfn[v])
		{
			tarjan(v);
			low[root]=min(low[root],low[v]);
			/*if (dfn[root]<low[v]
			{
			    //连接root 与v的边是桥 注意判断时的符号 
			}*/ 
		}
		else //不需要判断v是否在栈内 
		low[root]=min(low[root].dfn[v]); 
	} 
	if(low[root]==dfn[root])
	{
		bccnum++;
		for(;;)
		{
			int x=st[top--];
			bcc[x]=bccnum;
			if(x==root) break;
		}
	}
}


//tarjan 求点双连通分量
//有自环时不加自环的边
//清空路径，枚举E[]数组中存储的路径，建立双向边
void tarjan(int root,int fa)
{
	dfn[root]=low[root]=++index;//新点初始化 
	int child=0; //初始节点需要两个以上孩子 且dfn[root]<low[v]才是割点 
	gson(i,root)
	{
		int v=edge[i].v;
		if(ef[i])
		continue;
		ef[i]=ef[i^1]=1;
		st[++top]=i;//边入栈
		if(!dfn[v]) 
		{
			child++;
			tarjan(v,root);
			low[root]=min(low[root],low[v]);
			if(dfn[root]<=low[v]) //此处时割点 需注意初始结点至少两个儿子 
			{
				N++; //建数组至少开两倍大 
				for(;;)
            	{
		            int j=st[top--];
		             //bj[]数组用来标记结点所属的bcc 割点会改变 无意义
		             //E[]存新图的边 esum是其数量 tarjan结束后建立双向边 
		            if(bj[edge[j].v]!=N)
		            {
		            	bj[edge[j].v]=N;
			            E[++esum]=make_pair(edge[j].v,N);
		            }
		            if(bj[edge[j^1].v]!=N)
		            {
		              	bj[edge[j^1].v]=N;
		               	E[++esum]=make_pair(edge[j^1].v,N);
		            }
	               	belong[(j>>1)+1]=N;
	             	if(i==j)
	             	break;
	           } 
			}	
		}
		else
		low[root]=min(low[root],dfn[v]);
	}
	if(root==fa&&child<2)isCut[root]=0;
	//如果初始结点无两个以上的儿子 标记清零 
  //isCut[i]=1;表示该点是割点 
} 















