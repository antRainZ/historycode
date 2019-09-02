// 80
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+2;

struct lable{
    string name;
    int father;
};

map<string,int> id;
lable str[maxn];
string sub[maxn];
int pre[maxn],inx,output[maxn],inxo,n;

void tolower(string &s){
    for(int i=0;i<s.size();++i)if(s[i]>='A'&&s[i]<='Z')s[i]+=32;
}


void split(string &s){
    int l=0,r;
    while(true){
        r=s.find(" ",l);
        if(r==string::npos)break;
        sub[inx++]=s.substr(l,r-l);
        l = r+1;
    }
    sub[inx++]=s.substr(l);
}

void find(int p,int strp){
    if(p==inx){
        output[inxo++]=strp-1;
    }
    for(int i=strp;i<=n;++i){
        if(str[i].name==sub[p]){
            if(p==0)find(p+1,i+1);
            else if(str[i].father==strp-1)find(p+1,i+1);
        }else if(sub[p][0]=='#'){
            int k = id[sub[p]];
            if(k==i)find(p+1,i+1);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m,dot,k;
    cin>>n>>m;
    cin.ignore();
    string s,lname,lid;
    for(int i=1;i<=n;++i){
        getline(cin, s);
        dot=0;
        while(s[dot]=='.')dot++;
        k = s.find("#");
        if(k==-1){
            lname = s.substr(dot);
        }else{
            lname = s.substr(dot,k-dot-1);
            lid = s.substr(k);
            //cout<<lid<<endl;
            id[lid]=i;
        }
        dot>>=1;
        tolower(lname);
        str[i].name=lname;
        if(dot==0)str[i].father=0;
        else str[i].father=pre[dot-1];
        pre[dot]=i;
    }
    //for(int i=1;i<=n;++i)cout<<i<<" "<<str[i].name<<" "<<str[i].father<<"\n";
    while (m--)
    {
        getline(cin,s);
        inxo=inx=0;
        split(s);
        for(int i=0;i<inx;++i)if(sub[i][0]!='#')tolower(sub[i]);
       // for(int i=0;i<inx;++i)cout<<sub[i]<<" ";
       // cout<<endl;
        //for(int i=1;i<=n;++i)
        find(0,1);
        cout<<inxo;
        for(int i=0;i<inxo;++i)cout<<" "<<output[i];
        cout<<endl;
    }
}
/*
输入：
11 10
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #one
......div
........p #two
p
#subtitle
h3
div p
div div p
#main h2
#main #one
#main p
#main div #two
#main h3
*/
