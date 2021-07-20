#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=1e3+10;
int n,x[N],y[N],r[N];
int cnt,ans;
bool dis(int xx,int yy ,int rr,int ii,int jj)
{
	if((xx-ii)*(xx-ii)+(yy-ii)*(yy-ii)<=rr*rr)
	return true;
	else 
	return false;
}
int main()
{
	int xa,xb,ya,yb;
	cin>>xa>>ya>>xb>>yb;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>r[i];
	}
	int minx=min(xa,xb);
	int maxx=max(xa,xb);
	int miny=min(ya,yb);
	int maxy=max(ya,yb);
	cnt=0;
	ans=0;
	for(int i=minx;i<=maxx;i++)
	{
		for(int j=miny;j<=maxy;j++)
		{
			if(i>minx && i<maxx && j>miny && j<maxy)
			    continue;
			cnt++;
			for(int k=1;k<=n;k++)
			{
				if(dis(x[k],y[k],r[k],i,j))
				{
					ans++;
					break;
				}
			}
		}
	}
	cout<<cnt-ans<<endl;
	return 0;
}


#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1005
using namespace std;
 
struct Node
{
    int x,y,r;
} node[maxn];
 
bool dis(int a,int b,int c,int d,int r)//判断点是否在范围内
{
    int l=(a-c)*(a-c)+(b-d)*(b-d);
    if(l<=r*r) return true;
    else return false;
}
int main()
{
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int xmin=min(x1,x2),xmax=max(x1,x2);
    int ymin=min(y1,y2),ymax=max(y1,y2);
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=0; i<n; i++)
        scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].r);
    int cnt=0,c=0;
    for(i=xmin; i<=xmax; i++)
        for(j=ymin; j<=ymax; j++)
        {
            if(i>xmin&&i<xmax&&j>ymin&&j<ymax) continue;//由于是桌子，只有边上有将军
            c++;//计算将军的总数
            for(k=0; k<n; k++)
                if(dis(i,j,node[k].x,node[k].y,node[k].r))
                {
                    cnt++;//计算在散热器范围内将军数量
                    break;
                }
        }
    printf("%d\n",c-cnt);
    return 0;
}

