#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=1010;
int m,xx,yy,x,y;
char s;
int c[maxn][maxn],f[maxn][maxn];

int lowbit(int t)  
{
	return t&(-t);
}

void update(int a,int b,int v)
{
	for(int i=a;i<=maxn;i+=lowbit(i))
	{
		for(int j=b;j<=maxn;j+=lowbit(j))
		{
			c[i][j]+=v;
		}
	}
}

int getsum(int a,int b)
{
	int sum=0;
	for(int i=a;i>0;i-=lowbit(i))
	{
		for(int j=b;j>0;j-=lowbit(j))
		{
			sum+=c[i][j];
		}
	}
	return sum;
}

int main()
{
	while(cin>>m)
	{
		while(m--)
		{
			cin>>s;
			if(s=='B') //���� 
			{
				cin>>x>>y;
				x++;           //xy��0��ʼ +1���� ��Ϊ����x>0,y>0���ԣ�0,0����һ���Ѿ�û�У���������֪���˵��ѱ�ɣ�1,1��Ŀ���Ǻü���
				y++;
				if(f[x][y]==1) //���ظ� 
			      continue;
			    update(x,y,1);
			    f[x][y]=1;
			}
			else if(s=='D') //Ϩ�� 
			{
				cin>>x>>y;
				x++;
				y++;
				if(f[x][y]==0) //���ظ� 
				  continue;
				update(x,y,-1);
				f[x][y]=0;
			}
			else
			{
				cin>>x>>xx>>y>>yy;
				x++;
				y++;
				xx++;
				yy++;
				if(x>xx)
				  swap(x,xx);
				if(y>yy)
				  swap(y,yy);
				int ans=getsum(xx,yy)-getsum(xx,y-1)-getsum(x-1,yy)+getsum(x-1,y-1); //��άǰ׺�� 
				cout<<ans<<endl;
			}
			
		}
		
	}
	
	return 0;
}
