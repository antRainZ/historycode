#include<cstdio>
const int maxn =1e2+10;

char p[maxn][maxn];//匹配规则
char r[maxn][maxn];//匹配名称
char str[maxn];//目的字符串
char out[maxn];//输出

inline bool isdigit(char c){
    return c>='0'&&c<='9';
}

int main(){
    int n,m,plen,slen,inx;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%s %s",p[i],r[i]);
    }//输入是合法
    while(m--){
        scanf("%s",str);
        //printf("%s:\n",str);
        int i,flag=1;
        for(i=0;i<n;++i){
           plen=slen=inx=0;//初始化，分别表示匹配规则、目的字符串、输出的长度
           while(p[i][plen]&&str[slen]){
               if(p[i][plen]==str[slen])plen++,slen++;
               else{
                    if(p[i][plen++]!='<')break;
                    out[inx++]=' ';//参数，用空格隔开
                    bool state = true;
                    if(p[i][plen]=='i'){//处理<int>
                        while(str[slen]&&isdigit(str[slen])){//遇到非数字退出
                            if(str[slen]!='0')state=false;//去除前导0
                            if(!state)out[inx++]=str[slen];
                            slen++;
                        }
                        if(state&&str[slen]!='/')break;
                        else if(state&&str[slen]=='/')out[inx++]='0';//当int为一个0
                        plen+=4;
                    }else if(p[i][plen]=='s') {//处理<str>
                        while(str[slen]&&str[slen]!='/'){
                            state=false;
                            out[inx++]=str[slen];
                            slen++;
                        }
                        if(state)break;
                        plen+=4;
                    }else if(p[i][plen]=='p'){//处理<path> 处理到规则结束
                        while(str[slen])out[inx++]=str[slen++];
                        flag=0;
                        break;
                    }
               }
           }
            if(!p[i][plen]&&!str[slen])flag=0;
            if(!flag)break;
        }
        if(flag)printf("404\n");
        else{
            out[inx]=0;
            printf("%s %s\n",r[i],out+1);//输出的out[0]=' '，所以需要从out+1输出
        }
    }
}
