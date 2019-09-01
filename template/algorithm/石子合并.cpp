#include<cstdio>
const int maxn = 1e3+3;
const int INF = 1<<28;
int dp[maxn][maxn];
int sum[maxn];
int pre[maxn][maxn];//利用平行四边形进行优化


int main(){
    int n,d;
    scanf("%d",&n);
    for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)dp[i][j]=INF;
    for(int i=1;i<=n;++i){
        scanf("%d",&d);
        sum[i]=sum[i-1]+d;
        dp[i][i]=0;
        pre[i][i]=i;
    }
    for(int len = 2;len<=n;++len){
        // len代表合并的步长
        for(int i=1;i+len<=n+1;++i){
            int j = i+len-1;
            for(int k=pre[i][j-1];k<=pre[i+1][j];++k){
                int ans = dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                if(dp[i][j]>ans){
                    dp[i][j]=ans;
                    pre[i][j]=k;//记录该区间的优化结果
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
}
