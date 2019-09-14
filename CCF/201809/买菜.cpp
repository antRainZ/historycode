#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+6;
int a[maxn];
int b[maxn];

int main(){
    int n,l,r,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",&l,&r),a[l]++,a[r]--;
    for(int i=0;i<n;++i)scanf("%d%d",&l,&r),b[l]++,b[r]--;
    for(int i=0;i<maxn;++i){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        if(a[i]+b[i]==2)ans++;
    }
    printf("%d",ans);
}
