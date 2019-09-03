#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+2;
bool  visit[maxn][maxn][maxn<<2];
// 标记(x,y,t):点(x,y)在时间为t的时候被访问过
int p[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

struct dan
{
    int s,e;
};

dan a[maxn][maxn];//记录危险点(x,y)的危险时间段
int n,m,t,cut;

struct node
{
    int x,y,t;
    node(int x,int y,int t):x(x),y(y),t(t){}
    node(){}
};// 存储当前时间为t时，经过点（x,y)

bool check(int xx,int yy,int t){
    if(xx<1||yy<1||xx>n||yy>m)return false;
    if(t>=a[xx][yy].s&&t<=a[xx][yy].e)return false;
    if(visit[xx][yy][t])return false;
    return true;
}//该点经过合法

queue<node> q;
node no;
int bfs(){
    q.push(node(1,1,0));
    while(!q.empty()){
        no=q.front();
        q.pop();
        if(no.x==n&&no.y==m)return no.t;
        cut=no.t+1;
        for(int i=0;i<4;++i){
            int xx = no.x+p[i][0];
            int yy = no.y+p[i][1];
            if(check(xx,yy,cut)){
                visit[xx][yy][cut]=true;
                q.push(node(xx,yy,cut));
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    int a1,b1;
    for(int i=0;i<t;i++){
        scanf("%d%d",&a1,&b1);
        scanf("%d%d",&a[a1][b1].s,&a[a1][b1].e);
    }
    printf("%d\n",bfs());
}
