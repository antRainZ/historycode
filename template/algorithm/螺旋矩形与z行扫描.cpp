#include<iostream>
using namespace std;
const int maxn=1e2+4;
char a[maxn][maxn],b[maxn][maxn];
char c[maxn*maxn];
int n,inx;
void f1(){
    int x1=0,y1=0,nn=n*n;
    inx=0;
    while(inx<nn){
        if(y1<n-1){
            c[inx++]=a[x1][y1++];
            while(y1)c[inx++]=a[x1++][y1--];
            if(x1<n-1){
                c[inx++]=a[x1++][y1];
                while(x1)c[inx++]=a[x1--][y1++];
            }
            else{
                c[inx++]=a[x1][y1++];
                while(y1<n-1)c[inx++]=a[x1--][y1++];
            } 
            
        }else{
            c[inx++]=a[x1++][y1];
            while(x1<n-1)c[inx++]=a[x1++][y1--];
            if(y1<n-1)c[inx++]=a[x1][y1++];
            else continue;
            while(y1<n-1)c[inx++]=a[x1--][y1++];
        }
    }
}

void f2(){
    int l=0,r=n-1,t=0,d=n-1,x=0,y=0,nn=n*n;
    inx=0;
    while(inx<nn){
        //cout<<l<<" "<<r<<" "<<" "<<t<<" "<<d<<" "<<inx<<endl;
        while(y<r)b[x][y++]=c[inx++];
        t++;
       // cout<<l<<" "<<r<<" "<<" "<<t<<" "<<d<<" "<<inx<<endl;
        while(x<d)b[x++][y]=c[inx++];
        r--;
        //cout<<l<<" "<<r<<" "<<" "<<t<<" "<<d<<" "<<inx<<endl;
        while(y>l)b[x][y--]=c[inx++];
        d--;
       // cout<<l<<" "<<r<<" "<<" "<<t<<" "<<d<<" "<<inx<<endl;
        while(x>t)b[x--][y]=c[inx++];
        b[x][y++]=c[inx++];
        l++;
    }
}

int main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   while(cin>>n){
       for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
       f1();
       f2();
       for(int i=0;i<n;++i){
           for(int j=0;j<n;++j)cout<<b[i][j];
           cout<<"\n";
       }
   }
}
