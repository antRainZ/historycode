#include <bits/stdc++.h>
using  namespace std;
const int maxn = 1e2;

bool visit[maxn];

void E_sieve(){
	for(int i=2;i*i<maxn;i++){//跟试除法一样所以i*i即可
		if(!visit[i]){
			for(int j=i*i;j<maxn;j+=i)visit[j]=true;//前面的部分已优化，所以j=i*i开始
		}
	}
}

int main(){
	E_sieve();
	for(int i=2;i<maxn;i++)if(!visit[i])cout<<i<<" ";
}
