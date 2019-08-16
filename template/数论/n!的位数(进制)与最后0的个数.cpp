#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a;i<=b;++i)
#define __for(i,a,b) for(int i=a;i<b;++i)
const int maxn =1e3+4;
int p[maxn],inx=0;
bool a[maxn];

void init(){
    __for(i,2,maxn){
        if(!a[i])p[inx++]=i;
        for(int k=0;i*p[k]<maxn;++k){
            a[i*p[k]]=1;
            if(i%p[k]==0)break;
        }
    }
}

/*
一个m位的b进制数N，最小是b^(m-1)，最大不超过b^m，即b^(m-1)≤N<b^m。
解不等式，得log10(N)/log10(b)<m≤log10(N)/log10(b)+1。
*/
int digit(int n,int b){
    double ans = 0;
    _for(i,2,n)ans+=log10(i);
    return  ans = ans/log10(b+0.0)+1.0;
}

/*
至于0的个数，要对n！分解质因数，对base分解质因数。看n！的质因数中能凑出多少个base。
能凑出的base的个数就是末尾0的个数。设n！与base的共同质因数所构成的集合为s1。
base的质因数构成的集合为s2，则末尾0的个数就是min(s1(s2(i))/s2(i))
*/
int zero(int n,int b){
    map<int,int>m1,m2;
    map<int,int>::iterator it;
    int j = 0,x,m=111111111;
    _for(i,2,n){
        x=i,j=0;
        while(j<inx){
            if(x%p[j]==0)m1[p[j]]++,x/=p[j];
            else j++;
            if(x==1)break;
        }
    }
    j=0;
    while(j<inx){
        if(b%p[j]==0)m2[p[j]]++,b/=p[j];
        else j++;
        if(b==1)break;
    }
    for(it=m2.begin();it!=m2.end();it++){
        int j = it->first;
        m=min(m,m1[j]/m2[j]);
    }
    return m;
}

int main(){
    int n,b;
    init();
    while(~scanf("%d%d",&n,&b)){
        printf("%d %d\n",zero(n,b),digit(n,b));
    }
}
