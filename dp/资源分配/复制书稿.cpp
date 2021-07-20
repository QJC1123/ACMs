//资源分配 复制书稿
//一本书只给一个抄写员 抄写员分到的书的编号连续 使每个抄写员抄写页数最大值尽可能小 
//最长时间为抄写页数最多的人的时间  再从中选最小值 
//f[i][j]= min(max(f[i-1][k],f[i][j-k]))  前i个人抄写前j本书时间 最短 =  最小（前i-1个人抄写k本书，第i个人抄写j-k本书 ，总共所需时间为两者中的最大时间） 
//f[i][j-k]=sum[j]-sum[k+1] （一个人抄写j-k本书 所需时间 为 第k+1本书到第j本书的总页数 ） 
//每个人至少抄1本书 k>=i-1 j-k>=1 k<=j-1 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=510;
int m,k; 
int p[N],f[N][N],sum[N]; 

void prin(int i,int j) //i个人 j本书 
{
	if(i==0) //没有人 
	{
		return ; //递归终止 
	}
	else if(i==1) //剩下1个人 
	{
		cout<<"1"<<" "<<j<<endl; //抄写从第一本书 到 第j本书  剩下所有书一个人抄 
	} 
	else
	{
		int a=j; //t代表起始书的编号 从终止书第j书开始往前推算 
		int s=p[j]; //始书到终止书的页数sum 初始化为最后一本书页数 从终止书开始往前推
		while(s+p[j-1]<=f[k][m] && a>1) //起始书的编号大于1 起始书到终止书的页数sum+前一本书 若不到最小时间 进入循环 
	    {
	    	a--; //起始书的编号=前一本书 
	    	s+=p[a]; //起始书到终止书的页数=原来的+前一本书页数 
	    }
	    cout<<a<<" "<<j<<endl; //结束循环 找到起始书编号为t 终止书编号j 
	    prin(i-1,a-1); //递归 前i-1个人 剩下t-1本书 终止书编号为t-1 
	} 
} 

int main()
{
	sum[0]=0;
	memset(f,100,sizeof(f)); //*初始化最大 后面求最小 
	cin>>m>>k; //m本书 k个抄写员 
	for(int i=1;i<=m;i++) 
	{
		cin>>p[i]; //第i本书的页数 
		sum[i]=sum[i-1]+p[i]; //前i本书的总页数 
		f[1][i]=sum[i];
	} 
	for(int i=2;i<=k;i++) //i个抄写员 
	{
		for(int j=i;j<=m;j++) //抄写j本书 每个至少1本书 j至少i  
		{
			for(int t=i-1;t<j;t++) 
			{
				f[i][j]=min(f[i][j],max(f[i-1][t],sum[j]-sum[t])); //i个人抄前j本书所需的最长时间的最小值
			}
		}
	}
	cout<<f[k][m]<<endl;  //k个人抄前m本书所需时间的最小值
	prin(k,m); //m本书 k个人 
	return 0; 
} 
