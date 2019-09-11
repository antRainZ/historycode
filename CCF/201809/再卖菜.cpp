#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;

struct edge{
    int w,v,next;
};

edge e[maxn]; 
int a[maxn],head[maxn],tot=0,dist[maxn],visit[maxn],n;

void add(int u,int v,int w){
    e[tot].v=v;
    e[tot].w=w;
    e[tot].next=head[u];
    head[u]=tot++;
}
queue<int>q;
void spfa(){
    for(int i=0;i<=n;++i){
        q.push(i);
        visit[i]=false;
        dist[i]=0;
    }
    int u,v,w;
    while(!q.empty()){
        u = q.front();
        q.pop();
        visit[u]=false;
        for(int i=head[u];~i;i=e[i].next){
            w = e[i].w,v = e[i].v;
            if(dist[v]<dist[u]+w){
                dist[v]=dist[u]+w;
                if(!visit[v]){
                    visit[v]=true;
                    q.push(v);
                }
            }
        }

    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=0;i<maxn;++i)head[i]=-1;
    for(int i=0;i<n-2;++i){
        add(i+3,i,-(a[i+2]*3+2));
        add(i,i+3,a[i+2]*3);
    }
    add(2,0,-(a[1]*2+1));add(0,2,2*a[1]);
    add(n,n-2,-(a[n]*2+1));add(n-2,n,2*a[n]);
    for(int i=1;i<=n;++i)add(i-1,i,1);
    spfa();
    for(int i=1;i<=n;++i)printf("%d ",dist[i]-dist[i-1]);
}
