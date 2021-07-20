#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int dx[4]={1,0,-1,0}; 
const int dy[4]={0,1,0,-1};
const int N=110;
int m[N][N],f[N][N];
int r,c;
int dfs(int x,int y)
{
	int maxm=1; //·���������� 1 
	if(f[x][y]!=0) //��֮ǰ��� �򷵻� 
	return f[x][y];
	for(int i=0;i<4;i++) //�����ĸ����� 
	{
		int nx=x+dx[i]; //�¸������ 
		int ny=y+dy[i]; 
		if(nx>0&&ny>0&&nx<=r&&ny<=c&&m[nx][ny]>m[x][y]) //�������߽����������� 
		{
			maxm=max(maxm,dfs(nx,ny)+1); //��� ����һ�������������·������+1����ǰ����Ĳ����� maxm��ǰ��������·������ �Ƚϴ�С ��maxm���򻻷��� 
		} 
	}
	f[x][y]=maxm; //���仯 
	return maxm;
} 
int main()
{
	int ans=0;
	cin>>r>>c; 
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>m[i][j]; 
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			f[i][j]=dfs(i,j); //������ӵ�i,j�������·������ 
			ans=max(ans,f[i][j]); //�Ƚϸ����������·�� �ó��·������ 
		}
	}
	cout<<ans<<endl;
	return 0;
}

