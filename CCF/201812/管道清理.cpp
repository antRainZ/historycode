//链接：https://blog.csdn.net/qq_43202683/article/details/90047864
/*
需要清洁的管道下界为1，不需要清洁的管道下界为0。
可重复经过的管道上界为正无穷，不可重复经过的管道上界为1。
然后建图直接跑最小费用流。
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int maxn = 233;
const int inf = 0x3f3f3f3f;
struct node{
	int u,v,f,w,nxt;
	node(){};
	node(int a,int b,int c,int d,int e):u(a),v(b),f(c),w(d),nxt(e){}
}e[maxn*maxn];
int cnt = 0;
int head[maxn];
void add(int u,int v,int f,int w){
	e[cnt] = node(u,v,f,w,head[u]);
	head[u] = cnt++;
	e[cnt] = node(v,u,0,-w,head[v]);
	head[v] = cnt++;
}
int st,ed,E,ex;
int n,m;
int du[maxn];
int sum;
int num = 0;
void init(){
	scanf("%d%d",&n,&m);
	st = 0;ed = n + 1;
	ex = n + 2;
	cnt = 0;
	sum = 0;
	num = 0;
	memset(head,-1,ex<<2);
	memset(du,0,ex<<2);
	while(m--){
		int u,v;char c[2];
		scanf("%d%d%s",&u,&v,c);
		if(c[0] == 'A'){
			add(u,v,inf,E);
			du[u]--;
			du[v]++;
			num+=E;
		}
		else if(c[0] == 'B'){
			du[u]--;
			du[v]++;
			num+=E;
		}
		else if(c[0] == 'C'){
			add(u,v,inf,E);
		}
		else add(u,v,1,E);
	}
	for(int i = 1;i <= n;++i){
		if(du[i] > 0){
			sum += du[i];
			add(st,i,du[i],0);
		}
		else if(du[i] < 0){
			add(i,ed,-du[i],0);
		}
	}
}
int pre[maxn];
int flow[maxn];
int inq[maxn];
int dis[maxn];
int spfa(){
	memset(pre,-1,ex<<2);
	memset(inq,0,ex<<2);
	memset(dis,0x3f,ex<<2);
	queue<int> q;q.push(st);
	flow[st] = inf;inq[st] = 1;
	dis[st] = 0;
	while(q.size()){
		int u = q.front();q.pop();
		inq[u] = 0;
		for(int i = head[u];i != -1; i = e[i].nxt){
			int v = e[i].v;
			if(e[i].f && dis[v] > dis[u] + e[i].w){
				dis[v] = dis[u] + e[i].w;
				pre[v] = i;
				flow[v] = min(flow[u],e[i].f);
				if(!inq[v]) inq[v] = 1,q.push(v);
			}
		}
	}
	if(pre[ed] == -1) return -1;
	return flow[ed];
}
int mfmv(){
	int fw = 0;
	int ans = 0;
	int d;
	while((d = spfa())!=-1){
		fw += d;
		ans += dis[ed]*d;
		int v = ed;
		while(v!=st){
			e[pre[v]].f -= d;
			e[pre[v]^1].f += d;
			v = e[pre[v]].u;
		}
	}
	if(fw!=sum) return -1;
	return ans + num;
}
void sol(){
	int ans = mfmv();
	printf("%d\n",ans);
}
int main(){
	int T;cin>>T;cin>>E>>E;//输入的S没有用，不管它
	while(T--){
		init();sol();
	}
} 
