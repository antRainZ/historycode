#include<iostream>
#include<string>
using namespace std;

struct summon
{
     int a,h;//攻击力，生命值
};

summon f_s[8],s_s[8];//先手，后手随从空间
int fp,sp;//先手，后手随从个数
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    f_s[0].h=s_s[0].h=30;
    f_s[0].a=s_s[0].a=0;//初始化英雄
    int n,p,a,h;
    bool f = false;
    // f=false代表先手，f=true代表后手
    // p,a,h 位置，攻击力，生命值
    // 在处理attack的时候，p,a代表后手，先手随从位置
    string str;
    cin>>n;
    while (n--)
    {
       cin>>str;
       if(str[0]=='s'){
           cin>>p>>a>>h;
           if(f){
               if(p<=sp)for(int i=sp+1;i>p;--i)s_s[i]=s_s[i-1];
               s_s[p].a=a;s_s[p].h=h;sp++;
           }else{
               if(p<=fp)for(int i=fp+1;i>p;--i)f_s[i]=f_s[i-1];
               f_s[p].a=a;f_s[p].h=h;fp++;
           }
       }else if(str[0]=='a'){
           if(f){
               cin>>p>>a;
               s_s[p].h-=f_s[a].a;
               f_s[a].h-=s_s[p].a;
               if(f_s[0].h<=0)break;
               if(s_s[p].h<=0){
                   for(int i=p;i<sp;++i)s_s[i]=s_s[i+1];
                   sp--;
               }
               if(f_s[a].h<=0){
                   for(int i=a;i<fp;++i)f_s[i]=f_s[i+1];
                   fp--;
               }
           }else{
               cin>>a>>p;
                s_s[p].h-=f_s[a].a;
                f_s[a].h-=s_s[p].a;
                if(s_s[0].h<=0)break;
                if(s_s[p].h<=0){
                   for(int i=p;i<sp;++i)s_s[i]=s_s[i+1];
                   sp--;
                }
                if(f_s[a].h<=0){
                   for(int i=a;i<fp;++i)f_s[i]=f_s[i+1];
                   fp--;
                }
           }
       }else f=!f;
    }
    if(f_s[0].h>0&&s_s[0].h>0)cout<<"0\n";
    else if(f_s[0].h>0)cout<<"1\n";
    else cout<<"-1\n";
    cout<<f_s[0].h<<"\n"<<fp;
    for(int i=1;i<=fp;++i)cout<<" "<<f_s[i].h;
    cout<<"\n"<<s_s[0].h<<"\n"<<sp;
    for(int i=1;i<=sp;++i)cout<<" "<<s_s[i].h;
    cout<<"\n";
}
