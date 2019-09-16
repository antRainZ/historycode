#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
int d[maxn];
typedef long long ll;
int main(){
    int n,m;
    scanf("%d",&n);
    ll sum = 0;
    for(int i=1;i<=n;++i){
        int a,b;
        scanf("%d%d",&m,&a);
        for(int i=1;i<m;++i){
            scanf("%d",&b);
            if(b<0)a+=b;
            if(b>0&&b<a){
                a = b;
                d[a]=1;
            }
        }
        sum+=a;
    }
    int ans=0,bns=0;
    for(int i=1;i<=n;++i){
        if(d[i])ans++;
        if(i==1&&d[i]&&d[i+1]&&d[n])bns++;
        else if(i==n&&d[i]&&d[i-1]&&d[1])bns++;
        else if(i>1&&i<n&&d[i]&&d[i-1]&&d[i+1])bns++;
    }
    printf("%lld %d %d\n",sum,ans,bns);
}
