#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 16000 + 5;
int f[105][N];
struct nd{
    int l,p,s;
}pp[105];
bool cmp( nd a, nd b ){ return a.s < b.s; }
int n,k;
int q[N];
int main(){
    scanf("%d%d", &n, &k);
    for( int i = 1; i <= k; i++ ) scanf("%d%d%d", &pp[i].l, &pp[i].p, &pp[i].s );
    std::sort( pp+1, pp+k+1, cmp );
    for( int i = 1; i <= k; i++ ){
        int head = 0,tail = 0;
        q[0] = max( pp[i].s - pp[i].l, 0 );
        for( int j = 1; j <= n; j++ ){
            f[i][j] = max( f[i-1][j], f[i][j-1] );
            if( j >= pp[i].l + pp[i].s ) continue;
            while( head <= tail && q[head] + pp[i].l < j ) head++;
            if( j < pp[i].s ){
                while( head <= tail && f[i-1][q[tail]] - q[tail]*pp[i].p < f[i-1][j] - j*pp[i].p) tail--;
                q[++tail] = j;
                continue;
            }
            f[i][j] = max( f[i][j], f[i-1][q[head]] + pp[i].p*(j-q[head]));

        }
    }
    printf("%d", f[k][n]);
    return 0;
}

/* 
n块板子 k个工人
8       4

工人   最多画的板子数    画一个板子的钱     坐下固定的板子序号 
 i         li               pi                   si
 1          3                2                    2
 2          3                2                    3
 3          3                3                    5
 4          1                1                    7
 

 1  2  3  4  5  6  7  8  板子 j
    1  2     3     4     工人 i
	3  3     3     1
   1-3 1-3  3-5    7 
   2-4 2-4  4-6 
       3-5  5-7 
    2   2    3      1
   1-2   3-4   5-7 


前i个人 涂到j块板 收入最大值   
f[i][j]	 
f[i][j]=max(f[i-1][j],f[i][j-1])
f[i][j]=max(f[i][j],f[i-1][k]+(j-k)*p[i])
f[i-1][k]+p[i]*(j-k)=(f[i-1][k]-p[i]*k)+p[i]*j
 
	   
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
const int maxk=100;
const int maxn=16000+10;


