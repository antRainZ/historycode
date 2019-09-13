#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+3;
int n,s,l;//硬盘的数目，条带大小，现存数目
string str[maxn];
int inx,q,len,L,Lr;//下标,询问个数,字符的长度,阵列的长度，每一行含有的条块大小
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s>>l;
    for(int i=0;i<n;++i)str[i]="";
    for(int i=0;i<l;++i){
        // 硬盘的序号，内容
        cin>>inx;
        cin>>str[inx];
    }
    len = str[inx].size();
    L = len/8*(n-1);
    Lr = (n-1)*s;
    //cout<<len<<" "<<L<<" "<<Lr<<"\n";
    cin>>q;
    while(q--){
        cin>>inx;
        if(inx>=L){
            cout<<"-\n";
            continue;
        }
        int row = inx/Lr,col = (n-row+inx/s-row*(n-1))%n;
        int start = 8*(row*s+inx%s);
        //cout<<row<<" "<<col<<" "<<start<<"\n";
        if(str[col].size()){
            for(int i=0;i<8;++i)cout<<str[col][start+i];
            cout<<"\n";
        }else{
           if(l==n-1){
               char c;
               for(int j=0;j<8;++j){
                   int xor1 = 0,xor2;
                   for(int i=0;i<n;++i){
                       if(i!=col){
                            c = str[i][start+j];
                            xor2 = c>='A'?c-'A'+10:c-'0';
                            xor1^=xor2;
                       }
                   }
                   cout<<(xor1>9?char(xor1-10+'A'):char(xor1+'0'));
               }
           }
            else cout<<"-1\n";
        }
    }
}
/*
2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
2
0
1
*/

/*
3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5
*/
