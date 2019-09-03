#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
struct edge{
    int v,w;
    edge(int v,int w):v(v),w(w){}
};
vector<edge>g[maxn];//存储图结构
const int INF = 1<<29;//表示无边
int dist[maxn];//1到其他顶点的最小距离
int pre[maxn],n,m,a,b,w;//pre记录加入顶点v哪条边的权值
queue<int> q;//spfa用到的顶点队列
bool flag[maxn];//标记该顶点是否为访问过
int spfa(){
    for(int i=2;i<=n;++i)dist[i]=pre[i]=INF;
    flag[1]=true;
    q.push(1);
    while(!q.empty()){
        a = q.front();
        q.pop();
        flag[a]=false;//释放标记
        for(int i=0;i<g[a].size();++i){
            w = g[a][i].w;
            b = g[a][i].v;
            if(w+dist[a]<dist[b]){//松弛操作
                dist[b]=w+dist[a];
                pre[b]=w;//由于是最优结果直接加入就行
                if(!flag[b]){
                    flag[b]=true;
                    q.push(b);
                }
            }else if(w+dist[a]==dist[b]&&pre[b]>w)pre[b]=w;//有多个顶点符合的要求的时候，判断加入的边是否为最小
        }
    }
    w = 0;
    for(int i=2;i<=n;++i)w+=pre[i];//计算加入单源最短距离的边的权值和
    return w;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&w);
        g[a].push_back(edge(b,w));
        g[b].push_back(edge(a,w));
    }
    printf("%d\n",spfa());
}
