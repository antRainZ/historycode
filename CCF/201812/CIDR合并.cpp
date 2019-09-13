#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
struct IP{
    int a[4],len;
    string strip="";
    IP(){a[0]=a[1]=a[2]=a[3]=0;len=-1;}
    void to_str(){
        for(int i=0;i<4;++i){
            for(int j=7;j>=0;--j)strip+=char(((a[i]>>j)&1)+'0');
        }
    }
};

IP ip[maxn];//输入
list<int> output;
string str;
/*
第一按前缀排序，第二按长度从小到大排序
*/
bool cmp(const IP&A,const IP&B){
    for(int i=0;i<4;++i)if(A.a[i]!=B.a[i])return A.a[i]<B.a[i];
    return A.len<B.len;
}


/*
标准型：a1.a2.a3.a4/len
省略型：a1.a2/len
a1.a2.a3.a4 len=32,24,16,8
*/
void transfer(int j){
    int len = str.size(),inx=0,sum=0;
    for(int i=0;i<=len;++i){
        if(i==len)ip[j].a[inx++]=sum;
        else if(str[i]>='0'&&str[i]<='9')sum=sum*10+str[i]-'0';
        else if(str[i]=='.')ip[j].a[inx++]=sum,sum=0;
        else if(str[i]=='/'){
            ip[j].a[inx++]=sum;
            sum = 0;
            //for(int t=inx;t<4;++t)ip[j].a[t]=0;
            for(i++;i<len;++i)sum=sum*10+str[i]-'0';
            ip[j].len=sum;
            break;
        }
    }
    if(ip[j].len==-1)ip[j].len = 8*inx;
    ip[j].to_str();
    //cout<<ip[j].strip<<endl;
}


/*
子集判断方法：
ip前缀相同，且a.len<b.len
*/
inline bool ischild(int i,int j){
    if(ip[i].len>ip[j].len)return false;
    int len = ip[i].len;
    for(int t=0;t<len;++t)if(ip[i].strip[t]!=ip[j].strip[t])return false;
    return true;
}

/*
从小到大合并
*/
void merge_sub(int n){
    for(int i=0;i<n;++i){
        int j;
        for(j=i+1;j<n;++j)if(!ischild(i,j))break;
        //cout<<j<<endl;
        output.push_back(i);
        i = j - 1;
    }
}

/*
同级判断：
(1)a.len==b.len
(2)不考虑ip32位最后一位元素
*/

bool issameLevel(int i,int j){
    if(ip[i].len!=ip[j].len)return false;
    int len = ip[i].len-1;
    for(int t=0;t<len;++t)if(ip[i].strip[t]!=ip[j].strip[t])return false;
    return true;
}

/*
同级合并
*/
void merge(){
    auto i = output.begin(),j=output.begin();
    for(++j;j!=output.end();){
        if(issameLevel(*i,*j)){
            j = output.erase(j);//删除元素
            ip[*i].len--;
            //cout<<ip[*i].len<<endl;
            if(i!=output.begin())i--,j--;//往前回溯
        }else i++,j++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        transfer(i);
    }
    sort(ip,ip+n,cmp);//排序
    /*
    // 测试读入的数据是否处理正确
    for(int it=0;it<n;++it){
        for(int i=0;i<3;++i)cout<<ip[it].a[i]<<".";
        cout<<ip[it].a[3]<<"/"<<ip[it].len<<"\n";
    }
    */
    merge_sub(n);
    //cout<<output.size()<<"\n";
    merge();
    //cout<<output.size()<<"\n";
    for(auto &it:output){
        for(int i=0;i<3;++i)cout<<ip[it].a[i]<<".";
        cout<<ip[it].a[3]<<"/"<<ip[it].len<<"\n";
    }
}

