/*
There are many homeless cats in PKU campus. 
They are all happy because the students in the cat club of PKU take good care of them. 
Li lei is one of the members of the cat club. He loves those cats very much. Last week, 
he won a scholarship and he wanted to share his pleasure with cats. 
So he bought some really tasty fish to feed them, and watched them eating with great pleasure. 
At the same time, he found an interesting question:

There are m fish and n cats, and it takes ci minutes for the ith cat to eat out one fish.
A cat starts to eat another fish (if it can get one) immediately after it has finished one fish.
A cat never shares its fish with other cats. When there are not enough fish left,
the cat which eats quicker has higher priority to get a fish than the cat which eats slower. 
All cats start eating at the same time. Li Lei wanted to know, after x minutes, how many fish would be left.
*/

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e2+4;
int a[maxn];
int main(){
    int m,n,x;
    while (~scanf("%d%d%d",&m,&n,&x))
    {
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
        int b[maxn]={0};
        int j=m>n?n:m;
        for(int i=0;i<j;++i)b[i]=1;
        m-=j;
        int t=0,sum=0;
        while(t<x)
        {
            t++;
            for(int i=0;i<j;++i)
            {
                if(t%a[i]==0)
                {
                    b[i]=0;
                    if(m&&t<x)b[i]=1,m--;
                }
            }
            while(!b[j-1]&&!m)j--;
        }
        for(int i=0;i<j;++i)sum+=b[i];
        printf("%d %d\n",m,sum);
    }
    
}
