/*
给定一个数K（k>1)，求使得k^n和k^m大于或者等于1000,并且最后三个数相等，min(n+m),其中m>n
*/
#include<cstdio>
using namespace std;
const int maxn =1e3+1;
int a[maxn];

int main(){
    int k;
    while(~scanf("%d",&k)){
        for(int i=0;i<maxn;++i)a[i]=0;
        int ans=1,t=k;
        while(t<1000){
            t*=k;
            ans++;
        }
        t%=1000;
        a[t]=ans;
        while (1)
        {
            t=t*k%1000;
            ans++;
            if(a[t]){
                printf("%d\n",ans+a[t]);
                break;
            }
            a[t]=ans;
        }
    }
}
