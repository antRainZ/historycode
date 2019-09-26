#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
char str[maxn],pattern[maxn];
int fail[maxn],cnt;

void getFail(char *p,int plen){
	fail[0]=0;fail[1]=0;
	for(int i=1;i<plen;i++){
		int j=fail[i];
		while(j&&p[i]!=p[j])j=fail[j];
		fail[i+1]=(p[i]==p[j])?j+1:0;
	}
}

int kmp(char *s,char *p){
	int last = -1;
	int slen = strlen(s),plen=strlen(p);
	getFail(p,plen);
	int j =0;
	for(int i=0;i<slen;i++){
		while(j&&s[i]!=p[j])j=fail[j];
		if(s[i]==p[j])j++;
		if(j==plen){
			printf("%d\n",i+1-plen);
			if(i-last>=plen){//判断新的匹配和上一个匹配能否分开
				cnt++;
				last=i;
			}
		}
	}
}

int main(){
	while(~scanf("%s%s",str,pattern)){
		cnt = 0;
		kmp(str,pattern);
		printf("%d\n",cnt); 
	}
}
