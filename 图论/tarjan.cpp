//tarjan �õ�ǿ��ͨ���� 

int dfn[maxn],low[maxn],scc[maxn],stk[maxn];
int index=0,sccnum=0,top=0;

void tarjan(int root)
{
	if(dfn[root]) //��¼���޷��ʵ� 
	return ; 
	dfn[root]=low[root]=++index; //��ʼ�� ���ʵ������ 
	stk[++top]=root; //��ջ��ά��  �������ջ �����֮�����������Щһ�𹹳�ǿ��ͨ������
	for(int i=head[root];~i;i=e[i].ne) //�����õ�ָ��ȥ�ı� 
	{
		int v=e[i].to; //�����ָ��ȥ�Ķ�Ӧ�ĵ�
		if(!dfn[v]) //��v��δ�����ʹ� 
		{
			tarjan(v);
			low[root]=min(low[root],low[v]); //����low���� 
		} 
		else if(!scc[v]) //������ջ�� 
		{
			low[root]=min(low[root],dfn[v]);
		}
	}
	if(low[root]==dfn[root])//��������ҵ���ǳ�ĵ�  ǿ��ͨ���� 
	{
		sccnum++;  //����ǿ��ͨ���� 
		for(;;)
		{
			int x=stk[top--];
			scc[x]=sccnum; //��¼��������������ĸ�ǿ��ͨ����
			if(x==root)
			break; 
		}
	}
}

//���� �ؽ�ͼ �����޻�ͼ
/*
һ������ͼ N���� 
�����ټ����� ����ʹ����Щ����� �������ж��� -->����� �������Ϊ0 �ĵ� 
�����ټӼ����� ����ʹ����һ������� �������ж���-->�����  �����γɻ� 
max(���Ϊ0�ĵ��� ����Ϊ0�ĵ��� �� ����Ϊ0 �������Ϊ0 �γɻ�  
����sccֻ��һ�� ��Ϊ0 ֻ���Լ�һ��ǿ��ͨ���� ������ 
*/

//��� ��
/*
�и�㲻һ������ ����һ�����ڸ��
��һ���Ǹ�������ı� 
*/ 

//˫��ͨ���� ������ͼ��
/*
��˫��ͨ  �������� 
��˫��ͨ  �����ڸ�� 
*/ 

//tarjan ���˫��ͨ����
void tarjan(int root)
{
	dfn[root]=low[root]=++index;//��ʼ�� 
	st[++top]=root;//�����ջ
	gson(i,root) //����rootָ��ȥ�ı� 
	{
		int v=edge[i].v;
		if(ef[i]) continue;
		ef[i]=ef[i^1]=1;//����߹��ı� 
		if(!dfn[v])
		{
			tarjan(v);
			low[root]=min(low[root],low[v]);
			/*if (dfn[root]<low[v]
			{
			    //����root ��v�ı����� ע���ж�ʱ�ķ��� 
			}*/ 
		}
		else //����Ҫ�ж�v�Ƿ���ջ�� 
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


//tarjan ���˫��ͨ����
//���Ի�ʱ�����Ի��ı�
//���·����ö��E[]�����д洢��·��������˫���
void tarjan(int root,int fa)
{
	dfn[root]=low[root]=++index;//�µ��ʼ�� 
	int child=0; //��ʼ�ڵ���Ҫ�������Ϻ��� ��dfn[root]<low[v]���Ǹ�� 
	gson(i,root)
	{
		int v=edge[i].v;
		if(ef[i])
		continue;
		ef[i]=ef[i^1]=1;
		st[++top]=i;//����ջ
		if(!dfn[v]) 
		{
			child++;
			tarjan(v,root);
			low[root]=min(low[root],low[v]);
			if(dfn[root]<=low[v]) //�˴�ʱ��� ��ע���ʼ��������������� 
			{
				N++; //���������ٿ������� 
				for(;;)
            	{
		            int j=st[top--];
		             //bj[]����������ǽ��������bcc ����ı� ������
		             //E[]����ͼ�ı� esum�������� tarjan��������˫��� 
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
	//�����ʼ������������ϵĶ��� ������� 
  //isCut[i]=1;��ʾ�õ��Ǹ�� 
} 















