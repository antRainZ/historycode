#include <bits/stdc++.h>
using  namespace std;
const int n = 3;
typedef long long ll;

void matrixcopy(int a[][n],int b[][n]){
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)a[i][j]=b[i][j];
}//将矩阵B的内容赋值给矩阵A

// 矩阵A(n*n)*矩阵B(n*n),并且结果保留在矩阵A中
void mul(int a[][n],int b[][n]){
	int tmp[n][n]={0};//用来暂存结果
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				tmp[i][j]+=a[i][k]*b[k][j];
	matrixcopy(a,tmp);
}

ll quickpow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}// 整数的快速幂（用来与矩阵快速幂比较）

void matrixquickpow(int a[][n],int b){
	int ans[n][n]={0};
	for(int i=0;i<n;i++)ans[i][i]=1;//形成单位矩阵
	while (b)
	{
		if(b&1)mul(ans,a);
		mul(a,a);
		b>>=1;
	}
	matrixcopy(a,ans);
}//矩阵快速幂


void output(int a[][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)printf("%d ",a[i][j]);
		printf("\n");
	}
}

int main(){
	int a[3][3]={{0 ,3 ,8 },{6 ,4 ,4 },{5, 3 ,6}};
	matrixquickpow(a,4);
	output(a);
}//测试
