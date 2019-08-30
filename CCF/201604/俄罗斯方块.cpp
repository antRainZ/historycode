#include<cstdio>
const int mr = 16,mc=11;
const int n = 5;
int a[mr][mc],b[n][n],col;

bool judeg(int row){
    // row下落几行
    // a[row+i][s+j];
    for(int i=n-1;i>0;--i){
        for(int j=1;j<n;j++){
            if(b[i][j]&&row+i>=mr)return true;
            if(b[i][j]&&a[row+i][col+j-1])return true;
        }
    }
    return false;
}

int main(){
    for(int i=1;i<mr;++i)for(int j=1;j<mc;++j)scanf("%d",&a[i][j]);
    for(int i=1;i<n;++i)for(int j=1;j<n;++j)scanf("%d",&b[i][j]);
    scanf("%d",&col);
    for(int row=1;row<mr;++row){
        if(judeg(row)){
            row--;
            for(int i=1;i<n;++i)for(int j=1;j<n;++j)a[row+i][col+j-1]+=b[i][j];
            for(int i=1;i<mr;++i){
                for(int j=1;j<mc-1;++j)printf("%d ",a[i][j]);
                printf("%d\n",a[i][mc-1]);
            }
            break;
        }
    }
}
