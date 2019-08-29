/*
求解树的直径，求树上的两点的最长路径,两遍（dfs，bfs),第一遍求解离根节点最远的点s,第二遍求离s最远的点y,（s,y)之间的为一条最远路径
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn  = 2e4+4;
vector<int>g[maxn];
int n,m,d;
int q[maxn];
int len[maxn];
bool visit[maxn];
int bfs(int v){
    for(int i=1;i<=m;++i)visit[i]=true;
    for(int i=1;i<=m;++i)len[i]=0;
    int f=0,b=0,a,mmax=0,index;
    q[b++]=v;
    visit[v]=false;
    while(f<b){
        a = q[f++];
        for(int i=0;i<g[a].size();++i){
            v = g[a][i];
            if(visit[v]){
                visit[v]=false;
                q[b++]=v;
                len[v]=len[a]+1;
                if(mmax<len[v])mmax=len[v],index=v;
            }
        }
    }
    return index;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;++i){
        scanf("%d",&d);
        g[d].push_back(i);
        g[i].push_back(d);
    }
    m+=n;
    for(int i=n+1;i<=m;++i){
        scanf("%d",&d);
        g[d].push_back(i);
        g[i].push_back(d);
    }
    int ans = bfs(1);
    ans = bfs(ans);
    printf("%d\n",len[ans]);
}
