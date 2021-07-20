//在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
//输入含有多组测试数据。
//每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
//当为-1 -1时表示输入结束。
//随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
//对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）
//Sample Input
//2 1
//#.
//.#
//4 4
//...#
//..#.
//.#..
//#...
//-1 -1
//Sample Output
//2
//1



#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;
char s[100][100];
int method;//方案 
int flag[100];//标记每列是否有棋子 
int num;//棋盘上棋子个数 看是否放满 

void dfs(int cur)
{
	//边界
	if(num==k)
	{
		method++;//成功 方案数+1 
		return ;//返回上一级 
	}
	if(cur>=n)//搜出棋盘外 
	{
		return ;//返回上一级 
	} 
	
	for(int j=0;j<n;j++)
	{
		if(!flag[j]&&s[cur][j]=='#')//此位置是棋盘且无棋子 
		{
			flag[j]=1;//标记已放棋子
			num++;//放置棋子数加一
			dfs(cur+1);//下一级搜索  同一行下一列的 
			flag[j]=0;//清除标记 回溯 
		    num--;//回溯棋子数减一 再搜索下一个 
		}
	} 
	dfs(cur+1); //下一行搜索 
}

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		method=0;
		num=0; 
		memset(flag,0,sizeof(flag));
		if(n==-1 &&k ==-1)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			gets(s[i]);//输入第i行的棋盘规定 
		}
		dfs(0);
		printf("%d\n",method);
	}
	return 0;
} 
