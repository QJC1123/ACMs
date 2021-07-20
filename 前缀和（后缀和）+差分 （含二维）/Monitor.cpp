#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;//n行m列
int p; //安装的监视器数量 
int q; //小偷的数量 
int **b=new int*[n+2];

void accumulation()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		//动态二维数组 
		//n+1行 
		for(int i=0;i<=n+1;i++)
		{
			b[i]=new int[m+2];//m+1列 
		}
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=m+1;j++)
			{
				b[i][j]=0; //初始化为0 
			}
		} 
		//原来的土地所有区域 0 
		scanf("%d",&p);
		while(p--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			b[x1][y1]++;
			b[x2+1][y1]--;
			b[x1][y2+1]--;
			b[x2+1][y2+1]++;
		} 
		//对差分数组进行更改 //装上监控后可看到的区域改变 使装监控的区域内 1 
		accumulation();
		//求前缀和二维数组 装上监控的区域由于可能重复 使得监控区域值>1 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j])
				{
					b[i][j]=1;
				}
			}
		} 
		//前缀和二维数组 监控区域>1的改为=1   标记为装监控区域 1 无监控 0 
		accumulation();
		//接下来求面积 进行预处理  得到原先包含元素（0/1）的和 
		scanf("%d",&q); 
		while(q--)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ll area;  //求出 此范围内有监控覆盖 的面积 （监控1） 
			area=b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1];  
			if(area==(ll)(x2-x1+1)*(y2-y1+1)) //小偷区域面积   
			{
				printf("YES\n"); //相等 则能监控到小偷 
			}
			else  
			{
				printf("NO\n");
			}	
		} 
	}
}
