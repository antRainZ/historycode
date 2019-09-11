#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while (t-- ){
        char c[10];
        scanf("%s",c);
        int flag =1;
        stack<int> s;
        for(int i=0;c[i];++i){
            if(c[i]>='0'&&c[i]<='9')s.push(flag*(c[i]-'0'));
            else if(c[i]=='+')flag=1;
            else if(c[i]=='-')flag=-1;
            else if(c[i]=='x'){
                int a1=c[++i]-'0';
                int a2=s.top();s.pop();
                s.push(a1*a2);
               // printf("%d %d ",a1,a2);
            }else if(c[i]=='/'){
                int a1=c[++i]-'0';
                int a2=s.top();s.pop();
                s.push(a2/a1);
            }
        }
        flag=0;
        while (!s.empty())
        {
            flag+=s.top();s.pop();
           // printf("%d ",flag);
        }
        
        if(flag==24)printf("Yes\n");
        else printf("No\n");

    }
    
}
// #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while (t-- ){
        char c[10];
        scanf("%s",c);
        int flag =1;
        stack<int> s;
        for(int i=0;c[i];++i){
            if(c[i]>='0'&&c[i]<='9')s.push(flag*(c[i]-'0'));
            else if(c[i]=='+')flag=1;
            else if(c[i]=='-')flag=-1;
            else if(c[i]=='x'){
                int a1=c[++i]-'0';
                int a2=s.top();s.pop();
                s.push(a1*a2);
               // printf("%d %d ",a1,a2);
            }else if(c[i]=='/'){
                int a1=c[++i]-'0';
                int a2=s.top();s.pop();
                s.push(a2/a1);
            }
        }
        flag=0;
        while (!s.empty())
        {
            flag+=s.top();s.pop();
           // printf("%d ",flag);
        }
        
        if(flag==24)printf("Yes\n");
        else printf("No\n");

    }
    
}
// https://www.cnblogs.com/xidian-mao/p/10588813.html
