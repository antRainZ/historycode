#include<bits/stdc++.h>
using namespace std;

int f(int a){
    for(int i=0;i<32;i++)if(!((a>>i)&1))return 1<<i;//返回最后1个0，的2的次方
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(f(n)<n)printf("0\n");
        else printf("1\n");
        for(int i=2;i<n;i++)printf("%d ",f(i));
        if(f(n)<n)printf("%d\n",f(n));
        else printf("1\n");
    }
}
