// lab2_1.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class CRectangle{
private:
	double x;
	double y;
	double a;
	double b;
public:
	CRectangle(){
		cout<<"\nCRectangle Constructed."<<endl;
	}
	CRectangle(double dx, double dy, double da, double db){
		x = dx;
		y = dy;
		a = da;
		b = db;
		cout << "\nCRectangle Constructed." <<endl;
	}
	~CRectangle() {
		cout<<"CRectangle Destructed."<<endl;
	}
	void putxy(double dx, double dy){ x=dx; y=dy;}
	void putab(double da, double db){ a=da; b=db;}
	double getx(){ return x;}
	double gety(){ return y;}
	double geta(){ return a;}
	double getb(){ return b;}
	double getperimeter(){ return 2*(a+b);}
	double getarea(){ return a*b;}	
	//定义友元函数
	friend double dist(CRectangle& rt);
};
	double dist(CRectangle& rt){	/*计算距离*/
		double tx, ty;
		tx=rt.x+rt.a/2.0;
		ty=rt.y+rt.b/2.0;

		return sqrt(tx*tx+ty*ty);
	}

int main()
{
	CRectangle rect;
	rect.putxy(100.0, 50.0);
	rect.putab(1200.0, 700.0);
	cout<<"Down_Left corner point is: ("
	<<rect.getx() <<", " <<rect.gety() <<")" <<endl;
	cout<<"a= " <<rect.geta() <<", b= " <<rect.getb() <<endl;
	cout<<"Perimeter of this rectangle is: "
	<<rect.getperimeter() <<endl;
	cout<<"Area of this rectangle is: "
	<<rect.getarea() <<endl;
	cout<<"The Distance is :"
	<<dist(rect) <<endl;
	CRectangle recta(200,150,2000,800);
	cout<<"Down_Left corner point is: ("
	<<recta.getx() <<", " <<recta.gety() <<")" <<endl;
	cout<<"a= " <<recta.geta() <<", b= " <<recta.getb() <<endl;
	cout<<"Perimeter of this rectangle is: "
	<<recta.getperimeter() <<endl;
	cout<<"Area of this rectangle is: "
	<<recta.getarea() <<endl;
	cout<<"The Distance is :" << dist(recta) <<endl;

	system("pause");
	return 0;
}

