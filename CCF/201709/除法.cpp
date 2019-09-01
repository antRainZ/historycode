#include<cstdio>
typedef long long ll;
const int maxn = 1e5+5;
ll a[maxn];
int num[maxn],n;
#define lowbit(i) i&(-i)
void update(int inx,int v){
    for(int i=inx;i<=n;i+=lowbit(i))a[i]+=v;
}

ll getsum(int inx){
    ll ans = 0;
    for(int i=inx;i>0;i-=lowbit(i))ans+=a[i];
    return ans;
}

int main(){
    int m,d,l,r,op;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);
        update(i,num[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%d",&d);
            if(d==1)continue;// 优化二
            for(int j=l;j<=r;++j){
                if(num[j]>=d&&num[j]%d==0){
                // num[j]%d==0&&num[j]>=d 会超时 优化
                    update(j,num[j]/d-num[j]);
                    num[j]/=d;
                }
            }
        }else{
            printf("%lld\n",getsum(r)-getsum(l-1));
        }
    }
}
