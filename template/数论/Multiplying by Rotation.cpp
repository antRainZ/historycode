/*
Multiplication of natural numbers in general is a cumbersome operation. In some cases however the
product can be obtained by moving the last digit to the front.
Example: 179487 * 4 = 717948
Of course this property depends on the numbersystem you use, in the above example we used the
decimal representation. In base 9 we have a shorter example:
17 * 4 = 71 (base 9)
as (9 * 1 + 7) * 4 = 7 * 9 + 1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        int ans = 0,d=b,e=0;
        if(c==1||c==0){
            printf("1\n");
            continue;
        }
        while(!ans||(d!=b||e!=0)){
            d = d*c+e;
            //printf("%d ",d);
            e=d/a;
            d=d%a;
            ans++;
        }
        printf("%d\n",ans);
    }
}
