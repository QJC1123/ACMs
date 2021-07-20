#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1<<20;
int belong[N];
LL flag[N],ans[N],ar[N];
int n,m,k;
int L=1,R=0;
LL Ans=0;
struct lp{
    int l,r,id; 
}cw[N];
bool cmp(const lp &a,const lp &b){
    if(belong[a.l]==belong[b.l]){
        return a.r<b.r;
    }
    return belong[a.l]<belong[b.l];
}
void add(int x){
    Ans+=flag[ar[x]^k];
    flag[ar[x]]++;
}
void del(int x){
    flag[ar[x]]--;
    Ans-=flag[ar[x]^k];
}
int main(int argc, char const *argv[])
{
    while(~scanf("%d%d%d",&n,&m,&k)){
        ar[0]=0,L=1,R=0,Ans=0;
        memset(flag,0,sizeof(flag));
        int sz=sqrt(n);
        for(int i=1;i<=n;++i){
            scanf("%lld",&ar[i]);
            ar[i]=ar[i]^ar[i-1];
            belong[i]=i/sz;
        }
        for(int i=0;i<m;++i){
            scanf("%d%d",&cw[i].l,&cw[i].r);
            cw[i].id=i;
        }
        sort(cw,cw+m,cmp);
        flag[0]=1;
        for(int i=0;i<m;++i){
            while(L<cw[i].l){
                del(L-1);
                L++;
            }
            while(L>cw[i].l){
                L--;
                add(L-1);
            }
            while(R<cw[i].r){
                add(++R);
            }
            while(R>cw[i].r){
                del(R--);
            }
            ans[cw[i].id]=Ans;
        }
        for(int i=0;i<m;++i){
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}
