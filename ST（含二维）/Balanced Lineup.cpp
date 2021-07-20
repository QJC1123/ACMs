#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<time.h>
using namespace std;
const int maxn=50010;
int n,q;
int stmax[maxn][20],stmin[maxn][20];
int a, b,ans;

void init_st()
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);  
			stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
		}
	} 
}


int enqury_st(int l,int r)
{
	int k=int(log((double)(r-l+1))/log(2.0));
	int getmax=max(stmax[l][k],stmax[r-(1<<k)+1][k]);
	int getmin=min(stmin[l][k],stmin[r-(1<<k)+1][k]);
	return getmax-getmin;
}

int main()
{
	//clock_t start, finish;
	//start = clock();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>stmin[i][0];
		stmax[i][0]=stmin[i][0];
	}
	init_st(); 
	while(q--)
	{
		cin>>a>>b;
		cout<<enqury_st(a,b)<<endl;
	}
	//finish = clock();//clock()函数返回此时CPU时钟计时单元数
    //cout << "the time cost is " <<(double)(finish - start)/CLK_TCK;
	return 0;
}
