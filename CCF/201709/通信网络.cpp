#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
vector<int>g[maxn];
bool flag[maxn][maxn];
int n,m,a,b;
bool visit[maxn];

void dfs(int v,int s){
    visit[v]=true;
    flag[v][s]=flag[s][v]=true;
    for(int i=0;i<g[v].size();++i){
        a = g[v][i];
        if(!visit[a])dfs(a,s);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
    }
    for(int i=1;i<=n;++i)flag[i][i]=true;
    for(int i=1;i<=n;++i){
        for(int i=1;i<=n;++i)visit[i]=false;
        dfs(i,i);
    }
    
    int cnt=0,i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)if(!flag[i][j])break;
        if(j>n)cnt++;
    }
    printf("%d\n",cnt);
}
