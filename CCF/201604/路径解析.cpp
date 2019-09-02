#include<iostream>
#include<string>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k,pre,len;
    string cur,str;
    cin>>n>>cur;
    cin.ignore();
    while (n--)
    {
        getline(cin,str);
        if(str[0]!='/')str=cur+"/"+str;
        if(str.size()==0)str=cur;
        while(true){
            k = str.find("//");
            if(k==string::npos)break;
            str = str.replace(k,2,"/");
        }// 去除多余的"/"
        while(true){
            k = str.find("/../");
            if(k==string::npos)break;
            if(k==0)str.erase(k+1,3);//多余的部分
            else {
                pre = str.rfind("/",k-1);
                //反向查找上一个目录
                str.erase(pre,k-pre+3);
                // 删除上一个目录及../
           }
        }// 去除../
        while(true){
            k = str.find("/./");
            if(k==string::npos)break;
            str.erase(k+1,2);
        }// 去除./
        len = str.size();
        if(len>1&&str[len-1]=='/')str.erase(len-1,1);
        cout<<str<<endl;
    }
    
}
