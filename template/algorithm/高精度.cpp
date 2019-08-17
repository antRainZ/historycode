#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
string a[maxn]={"4","14"};
int stra[maxn],strb[maxn],c[maxn*2];

void toint(const string&A,int b[]){
    int j = 0,len1=A.size();
    for(int i=len1-1;i>=0;--i)b[j++]=A[i]-'0';
}

string mul(const string &A,const string &B){
    int len1 = A.size(),len2=B.size(),lenc=len1+len2+2;
    for(int i=0;i<lenc;++i)c[i]=0;
    toint(A,stra);
    toint(B,strb);
    for(int i=0;i<len1;++i)for(int j=0;j<len2;++j)c[i+j]+=stra[i]*strb[j];
    len1+=len2+2;
    for(int i=0;i<len1;++i)c[i+1]+=c[i]/10,c[i]%=10;
    while(!c[len1])len1--;
    string ans ="";
    for(int i=len1;i>=0;--i)ans+=char(c[i]+'0');
    return ans;
}

string add(const string &A,const string &B){
    int len1 = A.size(),len2=B.size(),bit=0,len3=max(len1,len2)+1;
    for(int i=0;i<len3;++i)stra[i]=strb[i]=0;
    toint(A,stra);
    toint(B,strb);
    for(int i=0;i<len3;++i){
        c[i]=stra[i]+strb[i]+bit;
        if(c[i]>9)c[i]-=10,bit=1;
        else bit=0;
    }
    string ans="";
    while(!c[len3])len3--;
    for(int i=len3;i>=0;--i)ans+=char(c[i]+'0');
    return ans;
}

string quickpow(string A,int b){
    string ans = "1";
    while(b){
        if(b&1)ans=mul(ans,A);
        A = mul(A,A);
        b>>=1;
    }
    return ans;
}

string quickmul(string A,int b){
    string ans = "1";
    while(b){
        if(b&1)ans=add(ans,A);
        A = add(A,A);
        b>>=1;
    }
    return ans;
}

string minu(const string&A,const string &B){
    int len1 = A.size(),len2=B.size(),bit=0;
    for(int i=0;i<len1;++i)stra[i]=strb[i]=0;
    toint(A,stra);
    toint(B,strb);
    for(int i=0;i<len1;++i){
        c[i]=stra[i]-strb[i]-bit;
        if(c[i]<0)c[i]+=10,bit=1;
        else bit=0;
    }
    string ans="";
    for(int i=len1-1;i>=0;--i)ans+=char(c[i]+'0');
    return ans;
}

void init(){
    for(int i=2;i<180;++i)a[i]=minu(quickpow(a[i-1],4),a[i-2]);
}

bool cmp(const string &A,const string &B){
    if(A.size()==B.size())return A<B;
    return A.size()<B.size();
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie();
    int t;cin>>t;
    string s;
    init();
    while(t--){
        cin>>s;
        int k = lower_bound(a,a+180,s,cmp)-a;
        cout<<a[k]<<"\n";
    }
}
