#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2;

/*
二分图：
*/


/*
无向图G为二分图的充分必要条件是，G至少有两个顶点, 且其所有回路的长度均为偶数。
通过染色法对判断图是否为二分图
二分图是由二个集合构成，并且图中的每条边的顶点归属于两个不同的集合，从边的角度考虑
从一条边，假设边一个顶点a属于集合A，则另外一个顶点b则属于B，可以通过DFS或者BFS来完成搜索
*/


bool g[maxn][maxn]={false};//无向无权图
int n,m;//顶点编号从0开始
int visit[maxn]={0};

bool dfs(int v=0,int c=1){
      visit[v]=c;
	  for(int i=0;i<n;i++){
		  if(!g[v][i])continue;
		  if(!visit[i])return dfs(i,-c);
		  else if(visit[i]==c)return false;
	  }
	  return true;
}

bool bfs(int v=0){
	for(int i=0;i<n;i++)visit[i]=0;
	visit[v]=1;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(g[v][i]){
				if(visit[i]==visit[v])return false;
                else if(!visit[i])visit[i]=-visit[v],q.push(i);
			}
		}
	}
	return true;
}

int main(){
	int a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
       cin>>a>>b;
	   g[a][b]=g[b][a]=true;
	}
	//dfs();
   cout<<bfs()<<endl;

}
