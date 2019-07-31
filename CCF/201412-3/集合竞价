#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
typedef long long ll;//数据大
struct node{
	ll s1,s2,num;
	double p;
	void init(ll a,ll b,ll c,double d){
		s1 = a;
		s2 = b;
		num = c;
		p = d;
	}
};//存放读取的数据记录
struct node2{
	double p;ll num;
	void init(double a,ll b){
		p = a;
		num = b;
	}
};//存放竞价的价格与数量
node no[maxn];
node2 no1[maxn],no2[maxn];//分别表示buy，sell
int in1,in2;
bool cmp(const node2&A,const node2&B){
	return A.p<B.p;
}
int f(node2 a[],int n){
	int j = 0 ;
	for(int i=1;i<n;i++){
		if(a[i].p-a[i-1].p<1e-6)a[j].num+=a[i].num;
		else a[++j].init(a[i].p,a[i].num);
	}
	return j+1;
}//将重复的合并
int main(){
	// freopen("test.in","r",stdin);//将该文件作为标准输入
	// freopen("test.out","w",stdout);
	string s;
	double p;
	ll num;
	int inx=1;
	while(cin>>s){
		if(s[0]=='b')cin>>p>>num,no[inx].init(1,1,num,p);
		else if(s[0]=='s')cin>>p>>num,no[inx].init(0,1,num,p);
		else cin>>num,no[num].s2=0,no[inx].s2=0;
		inx++;
	}
	for(int i=1;i<inx;i++){
		if(!no[i].s2)continue;
		if(no[i].s1)no1[in1++].init(no[i].p,no[i].num);
		else no2[in2++].init(no[i].p,no[i].num);
	}
	sort(no1,no1+in1,cmp);
	sort(no2,no2+in2,cmp);
	// for(int i=0;i<in1;i++)cout<<no1[i].p<<" "<<no1[i].num<<endl;
	// cout<<endl;
    // for(int i=0;i<in1;i++)cout<<no2[i].p<<" "<<no2[i].num<<endl;
	//cout<<endl;
	in1= f(no1,in1);in2=f(no2,in2);
	double maxp=0;ll nmax=0,tt,sum=0;
	int j=0;
	for(int i=in1-2;i>=0;i--)no1[i].num+=no1[i+1].num;
	for(int i=1;i<in2;i++)no2[i].num+=no2[i-1].num;
	//   for(int i=0;i<in1;i++)cout<<no1[i].p<<" "<<no1[i].num<<endl;
	// cout<<endl;
	//  for(int i=0;i<in1;i++)cout<<no2[i].p<<" "<<no2[i].num<<endl;
	//  cout<<endl;
    for(int i=0;i<in2;i++){
		while(j<in1&&no1[j].p<no2[i].p)j++;
		tt =min(no2[i].num,no1[j].num);
		if(tt>=nmax)nmax=tt,maxp=no2[i].p; 
	}
	j = 0;
	for(int i=0;i<in1;i++){
		while(j<in2&&no2[j].p<=no1[i].p)j++;
		tt =min(no2[j-1].num,no1[i].num);
		if(tt>nmax)nmax=tt,maxp=no1[i].p;
		else if(tt==nmax&&no1[i].p>maxp)maxp=no1[i].p; 
	}
	printf("%.2f %lld\n",maxp,nmax);
	return 0;
}
