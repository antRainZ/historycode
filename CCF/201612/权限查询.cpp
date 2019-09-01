#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+2;
typedef pair<string,int> pa;
typedef map<string,int> m;
string str;
m role;
m a;
m user;
vector<pa> role_a[maxn];
vector<pa> user_a[maxn];

void join(int v){
    int k = role[str],j;
    for(int i = 0;i<role_a[k].size();++i){
        pa p = role_a[k][i];
        for( j = 0;j<user_a[v].size();++j){
            pa pp = user_a[v][j];
            if(p.first==pp.first){
                if(p.second>pp.second)user_a[v][j].second=p.second;
                break;
            }
        }
        if(j==user_a[v].size())user_a[v].push_back(p);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p ,k,r,u,q,n;
    cin>>p;cin.ignore();
    for(int i=0;i<p;++i){
       cin>>str;
       k = str.find(":");
       if(k==string::npos)a[str]=10;
       else a[str.substr(0,k)]=str[str.size()-1]-48;
    }
    cin>>r;
    for(int i=0;i<r;++i){
        cin>>str>>n;
        role[str]=i;
        for(int j=0;j<n;++j){
            cin>>str;
            k = str.find(":");
            if(k==string::npos)role_a[i].push_back(pa(str,10));
            else role_a[i].push_back(pa(str.substr(0,k),str[str.size()-1]-48));
        }
    }
    cin>>u;
    for(int i=1;i<=u;++i){
        cin>>str>>n;
        user[str]=i;
        for(int j=0;j<n;++j){
            cin>>str;
            join(i);
        }
    }
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>str;
        k = user[str];
        cin>>str;
        if(k==0){
            cout<<"false\n";
            continue;
        }else{
            int j,lev=10;
            j = str.find(":");
            if(j!=string::npos){
                lev = str[str.size()-1]-'0';
                str=str.substr(0,j);
            }
            for(j=0;j<user_a[k].size();++j){
                pa pp = user_a[k][j];
                if(pp.first==str){
                   if(pp.second>=lev)cout<<"true\n";
                   else if(lev==10)cout<<pp.second<<"\n";
                   else cout<<"false\n";
                   break;
                }
            }
            if(j == user_a[k].size())cout<<"false\n";
        }
    }
}
