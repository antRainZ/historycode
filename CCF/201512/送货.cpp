#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+4;
vector<int>g[maxn];
int f[maxn],n,m,a,b;
bool visit[maxn][maxn];

void init(){
    for(int i=1;i<=n;++i)f[i]=i;
}

int find(int x){
    int root=x,j;
    while(root!=f[root])root=f[root];
    while(x!=root){
        j = f[x];
        f[x]=root;
        x = j;
    }
    return root;
}

void join(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx!=yy)f[xx]=yy;
}

bool scc(){
    for(int i=2;i<=n;++i)if(f[i]!=f[1])return false;
    return true;
}//判断图的连通性

bool eulerjudeg(){
    int num = 0;
    for(int i=1;i<=n;++i)if(g[i].size()&1)num++;
    if(!num||(num==2&&g[1].size()&1))return true;
    return false;
}//根据欧拉路径的性质，且要满足1为起点

typedef pair<int,int> pa;
stack<int> path;
stack<pa >s;
void dfs(){
    s.push(pa(1,0));
    int i;
    while(!s.empty()){
        a = s.top().first;
        i = s.top().second;
        s.pop();
        for(;i<g[a].size();++i){
            b=g[a][i];
            if(!visit[a][b]){
                visit[a][b]=visit[b][a]=true;
                s.push(pa(a,i+1));//优化
                s.push(pa(b,0));
                break;
            }
        }
        if(i==g[a].size())path.push(a);
    }
}//需要利用栈来模拟dfs,不然会出现运行错误的情况

int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        g[b].push_back(a);
        g[a].push_back(b);
        join(a,b);
    }
    for(int i=1;i<=n;++i)find(i);//刷新并查集
    if(scc()&&eulerjudeg()){
        for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end());
        //利用dfs的性质，将顶点排序后，取出的数自动满足字典序
        dfs();
        while(!path.empty()){
            a = path.top();
            path.pop();
            cout<<a<<" ";
        }cout<<endl;
    }else printf("-1\n");
    
}
