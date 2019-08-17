#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;++i)
#define __for(i,a,b) for(int i=a;i<b;++i)
using namespace std;
const int maxn = 200;
int dp[maxn][maxn][maxn];
int sum[maxn];
int INF = 1<<28;
int main(){
    int N,L,R,d;
    while(~scanf("%d%d%d",&N,&L,&R)){
        _for(i,0,N) _for(j,0,N) _for(t,0,N) dp[i][j][t]=INF;
        _for(i,1,N)scanf("%d",&d),sum[i]=sum[i-1]+d,dp[i][i][1]=0;
        _for(len,2,N){
            _for(l,1,N-len+1){
                int r = len+l-1;
                _for(p,2,len){
                   __for(k,l,r)dp[l][r][p]=min(dp[l][r][p],dp[l][k][1]+dp[k+1][r][p-1]);
                }
                _for(k,0,N)if((k>=L&&k<=R)||(k==0&&len>=l&&len<=R))dp[l][r][1]=min(dp[l][r][1],dp[l][r][k]+sum[r]-sum[l-1]);
            }
        }
        if(dp[1][N][1]==INF)printf("0\n");
        else printf("%d\n",dp[1][N][1]);
    }
}
