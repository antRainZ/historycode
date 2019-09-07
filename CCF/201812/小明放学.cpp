#include<cstdio>
typedef long long ll;
ll r,y,g,n,k,t,a;
ll f(){
    if(k==1){
        if(a>=0)return a;
        a+=g;
        k=3;
        f();
    }else if(k==2){
        if(a>=0)return a+r;
        a+=r;
        k=1;
        f();
    }else if(k==3){
        if(a>=0)return 0;
        a+=y;
        k=2;
        f();
    }
}

int main(){
    scanf("%lld%lld%lld%lld",&r,&y,&g,&n);
    ll sum =0,s=r+g+y;
    while(n--){
        scanf("%lld%lld",&k,&t);
        if(k==0)sum+=t;
        else{
            a = t-sum%s;
            sum+=f();
        }
    }
    printf("%lld\n",sum);
}
