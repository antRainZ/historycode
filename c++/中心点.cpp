//题意，求最少添加多少点使得，在一个点集之中满足所有点能够找到一点关于相同点中心对称
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
const int maxn = 1e3+3;
struct point{
    int x,y;
};
point p[maxn];
map<pa,int>m;
map<pa,int>mm;
int main(){
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        x<<=1;
        y<<=1;
        p[i].x=x;
        p[i].y=y;
        mm[pa(x,y)]++;
        
    }
    if(n<=2){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            x = (p[i].x+p[j].x)>>1;
            y = (p[i].y+p[j].y)>>1;
            m[pa(x,y)]++;
        }
    }
    int ans = 1<<28;
    for(map<pa,int>::iterator i=m.begin();i!=m.end();++i){
        int t =n-2*(i->second)-mm[i->first];
        //printf("%d %d %d\n",t,i->first.first,i->first.second);
        if(t<ans)ans=t;
    }
    printf("%d\n",ans);
}
//100
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
const int maxn = 1e3+3;
struct point{
    int x,y;
};
point p[maxn];
map<pa,int>m;
map<pa,int>mm;
int main(){
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        x<<=1;
        y<<=1;
        p[i].x=x;
        p[i].y=y;
        
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            x = (p[i].x+p[j].x)>>1;
            y = (p[i].y+p[j].y)>>1;
            m[pa(x,y)]++;
        }
    }
    int ans = 0;
    for(map<pa,int>::iterator i=m.begin();i!=m.end();++i){
        int t =i->second;
        //printf("%d %d %d\n",t,i->first.first,i->first.second);
        if(t>ans)ans=t;
    }
    printf("%d\n",n-ans);
}
