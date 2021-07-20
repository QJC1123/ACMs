
#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <sstream>
#define maxn 1005
typedef long long ll;
using namespace std;
string a;
ll d[maxn][20],n,len;

ll Min(ll i,ll j)
{
    return a[i]<=a[j]?i:j;
}
void rmq()
{
    for(ll i=0;i<len;i++) d[i][0]=i;//注意这里是下标
    for(ll j=1;(1<<j)<=len;j++)//长度
    {
        for(ll i=0;i+(1<<j)-1<len;i++)
        {
            d[i][j]=Min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(ll l,ll r)
{
    ll k=(ll)(log(r-l+1)/log(2.0));
    return Min(d[l][k],d[r-(1<<k)+1][k]);
}
int main()
{
    //freopen("/Users/zhangkanqi/Desktop/11.txt","r",stdin);
    while(cin>>a)
    {
        bool flag=false;
        len=a.length();
        ll num=0,n;
        char ans[maxn];
        rmq();
        cin>>n;
        if(len<=n)
            printf("0\n");
        else
        {
            ll s=0,e=n,t=len-n;
            while(t--)//剩余t个数字
            {
                s=query(s,e);
                ans[num++]=a[s];
                s++;e++;
            }
            for(ll i=0;i<num;i++)
            {
                if(!flag && ans[i]=='0') continue;
                flag=true;
                printf("%c",ans[i]);
            }
            if(!flag) printf("0");
            printf("\n");
        }
 
    }
    return 0;
}
/*
178543 4
1000001 1
100001 2
12345 2
54321 2
 */
 

