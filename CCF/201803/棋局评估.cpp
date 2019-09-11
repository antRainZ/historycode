#include <bits/stdc++.h>
using namespace std;
// Alice 1 Bob 2 空格 0
// 对于Alice已经获胜的局面，评估得分为(棋盘上的空格子数+1)；
// 对于Bob已经获胜的局面，评估得分为 -(棋盘上的空格子数+1)；
// 对于平局的局面，评估得分为0；
//保证输入的局面轮到Alice行棋。
const int N = 4;
const int INF = 1000;
int n, a[N][N];

int four_equ(int aa,int b,int c,int d){
    if(aa==b&&aa==c&&aa==d)return true;
    return false;
}

bool judge(int k)
{
    for (int i = 1; i < N; ++i)
        if(four_equ(a[i][1],a[i][2],a[i][3],k))
            return true;//横行相同
    for (int i = 1; i < N; ++i)
        if(four_equ(a[1][i],a[2][i],a[3][i],k))
            return true;//竖行相同
    if(four_equ(a[1][1],a[2][2],a[3][3],k))return true;
    if(four_equ(a[1][3],a[2][2],a[3][1],k))return true;
    return false;
}

int dfs(int k)
{
    int t = 0; //棋牌空白数
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (!a[i][j])
                t++;
   if(k==1&&judge(2))return -t-1;//bob已经赢了
   if(k==2&&judge(1))return t+1;
   if(t==0)return 0; //无棋可下
   int Max = -INF,Min=INF;
   for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (!a[i][j]){
                a[i][j]=k;
                if(k==1)Max=max(Max,dfs(2));
                else Min = min(Min,dfs(1));
                a[i][j]=0;//回溯
            }
    if(k==1)return Max;
    if(k==2)return Min;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        for (int i = 1; i < N; ++i)
            for (int j = 1; j < N; ++j)
                scanf("%d", &a[i][j]);
        printf("%d\n",dfs(1));
    }
    
}
