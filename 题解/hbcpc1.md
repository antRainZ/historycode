@[TOC]()
下面是一些这次比赛的较简单题目的题解
[题解链接](https://ac.nowcoder.com/acm/contest/903?from=acm_calendar#question)
# B Icebound and Sequence 
求 $$S=\sum_{i=1}^{n} q^i \pmod p $$
思路：利用快速幂处理幂运算，对于除法的模运算处理
（1）求逆元
（2) 利用性质当$\frac{a}{b}\%p = \frac{a\%pb}{b} 其中b|a ,表示b能够整除a$ ,利用这个方法的时候，快速幂利用`long long`就不能容纳数据范围，利用
二分乘法解决 乘法问题

```cpp
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll quickmul(ll a,ll b,ll c){
    ll ans=0;
    while(b){
        if(b&1)ans=(ans+a)%c;
        a=(a+a)%c;
        b>>=1;
    }
    return ans;
}//二分乘法
 
ll quickpow (ll a,ll b,ll c){
    ll ans=1;
    while(b){
        if(b&1)ans=quickmul(a,ans,c);
        a=quickmul(a,a,c);
        b>>=1;
    }
    return ans;
}
 
int main(){
   int t;
   scanf("%d",&t);
   while (t--)
   {
       ll q,n,p;
       scanf("%lld%lld%lld",&q,&n,&p);
       if(q==1){
           printf("%lld\n",n%p);
       }
       else {
           ll mod=(ll)p*(q-1);
           ll ans = quickpow(q,n+1,mod);
           ans = (ans-q)%mod;
           printf("%lld\n",ans/(q-1));
       }
   }   
}
```
# G	点我
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int main(){
   int a;
   scanf("%d",&a);
   if(a==0){
       printf("qiandaoshibai");
       return 0;
   }//特殊处理
   if(a%2)printf("qiandaoshibai");
   else printf("qiandaochenggong");
    return 0;
}
```
# H	天神的密码
```cpp
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll sum(ll a){
    ll s= 0;
    while(a){
        s+=a%10;
        a/=10;
    }
    return s;
}//求数位和
 
int main(){
  int t;
  scanf("%d",&t);
  ll a,k;
  while (t--)
  {
      scanf("%lld%lld",&a,&k);
      if(k==2)a*=a;
      a=sum(a);
      while(a/10){
          a=sum(a);
      }
      printf("%lld\n",a);
  }
}
```
# K	河北美食
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,c;
    std::ios::sync_with_stdio(false);
    cin.tie(0);//关闭同步流，加快cin读取速度
    cin>>n>>m;
    map<int ,string> order;//记录食材出现的顺序
    map<string ,int> number;//记录食材的数量
    string s;
    for(int i=0;i<n;i++){
        cin>>s>>c;
        order[i]= s;
        number[s]=c;
    }
    int flag=0;
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>s>>c;
            if(!flag){
                number[s]-=c;
                if(number[s]<0)flag=1;//如果出现缺食材，以后的食材就可以不用处理，同时也起到标记的作用
            }
           
        }
    }
    if(flag)cout<<"NO"<<endl;
    else{
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            s = order[i];
            c = number[s];
            if(c)cout<<s<<" "<<c<<"\n";
        }
    }
    return 0;
}
```

# L	smart robot
题目的数据可能有点水，这题的答案不会10000所以从一点往下搜索的层次不会超过4层，直接写4个for循环是可以的
```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN =50;
bool reach[10000];
int m[MAXN][MAXN]={0};
int n,a;
int x_offset[4]={1,0,-1,0};
int y_offset[4]={0,-1,0,1};
 
 
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            reach[a]=true;
            m[i][j]=a;
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           for(int t=0;t<4;t++){
               int x1 = i+x_offset[t];
               int y1 = j+y_offset[t];
               if(x1<0||x1>=n||y1<0||y1>=n)continue;
               int z1 = m[i][j]*10+m[x1][y1];
               reach[z1]=true;
               for(int k=0;k<4;k++){
                   int x2 = x1+x_offset[k];
                   int y2 = y1+y_offset[k];
                   if(x2<0||x2>=n||y2<0||y2>=n)continue;
                   int z2 = z1*10+m[x2][y2];
                   reach[z2]=true;
                   for(int l=0;l<4;l++){
                       int x3 = x2+x_offset[l];
                       int y3 = y2+y_offset[l];
                       if(x3<0||x3>=n||y3<0||y3>=n)continue;
                       int z3 = z2*10+m[x3][y3];
                       reach[z3]=true;
                   }
               }
                
           }
        }
    }
    for(int i=0;i<10000;i++){
        if(!reach[i]){
            printf("%d",i);
            return 0;
        }
    }
}
```
