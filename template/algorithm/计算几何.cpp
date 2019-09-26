#include<bits/stdc++.h>
using namespace std;
const int pi = acos(-1.0);
const int eps = 1e-8;
/*
计算几何
*/

int sgn(double a){
	if(fabs(a)<eps)return 0;
	return a>0?1:-1;
}//判断浮点数的符号

int dcmp(double a,double b){
	if(fabs(a-b)<eps)return 0;//浮点数相等
	return a>b?1:-1;
}//比较两个浮点数

struct point{
	int x,y;
	point(){}
	point(int a,int b):x(a),y(b){}
};

double dist(point&a,point&b){
	double x = a.x-b.x,y=a.y-b.y;
	return sqrt(x*x-y*y);
}//求两点之间的距离

typedef point Vector;//定义向量

Vector operator+(Vector&a,Vector&b){
	return Vector(a.x+b.x,a.y+b.y);
}//向量加法

Vector operator-(Vector&a,Vector&b){
	return Vector(a.x-b.x,a.y-b.y);
}//向量减法

Vector operator*(Vector&a,double b){
	return Vector(a.x*b,a.y*b);
}//向量的数量积

double Dot(Vector&a,Vector&b){
	return a.x*b.x+a.y*b.y;
}//向量的点乘

double len(Vector&a){
	return sqrt(Dot(a,a));
}//向量的模长

double Angle(Vector&a,Vector&b){
	return acos(Dot(a,b)/len(a)/len(b));
}//向量夹角

double cross(Vector&a,Vector&b){
	return a.x*b.y-a.y*b.x;
}//向量叉积的模长
/*
判断向量A、B的方向关系
计算两向量构成的平行四边形有向面积
计算三点构成的三角形的面积
向量旋转
*/

Vector rotate(Vector&a,double rad){
	return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}//向量旋转


struct line{
	point p1,p2;
	line(){}
	//两点式
	line(point&a1,point&a2):p1(a1),p2(a2){}
	//点斜式 y-y0=tana(x-x0);
	line(point&a1,double angle){
		p1=a1;
		if(sgn(angle-pi/2)==0)p2=point(p1.x,p2.y+1);//直角情况
		else p2 =point(p1.x+1,p2.y+tan(angle));
	}
	//ax+by+c=0;
	line(double a,double b,double c){
		if(sgn(a)==0){
			p1 = point(0,-c/b);
			p2 = point(1,-c/b);
		}else if(sgn(b)==0){
			p1 = point(-c/b,0);
			p2 = point(-c/b,1);
		}else {
			p1 = point(0,-c/b);
			p2 = point(1,(-c-a)/b);
		}
	}
};

typedef line segm;//定于线段

double Pldist(point&a,line&v){
	return fabs(cross(a-v.p1,v.p2-v.p1))/dist(v.p1,v.p2);
}//点到直线的距离

int main(){
	//double 读入使需用到%lf，输出时用到%f

}
