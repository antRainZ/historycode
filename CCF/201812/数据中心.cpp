#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct edge{
    int a,b,w;
}e[maxn];
bool cmp(const edge&A,const edge&B){
    return A.w<B.w;
}
int f[maxn],n,m,root,ans,a,b,cnt;
void init(){
    for(int i=1;i<=n;++i)f[i]=i;
}
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
    scanf("%d%d%d",&n,&m,&root);
    for(int i=0;i<m;++i)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
    init();
    sort(e,e+m,cmp);
    cnt=0;
    for(int i=0;i<m;++i){
        a=find(e[i].a);b=find(e[i].b);
        if(a!=b){
            cnt++;
            if(ans<e[i].w)ans=e[i].w;
            if(cnt==n-1)break;
            f[a]=b;
        }
    }
    printf("%d\n",ans);
}
