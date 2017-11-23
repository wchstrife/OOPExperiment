// lab2_2.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Cargo{

	double weight;

public:
	static double Total;
	Cargo(double x=0);
	double In();
	double Out();
	void Show();
};

double Cargo::Total = 0;

Cargo::	Cargo(double x){
	weight = x;
}

double Cargo::In(){
	int n, w;
	cout<< "请输入购进货物的数量和每箱的重量: ";
	cin >> n >> w;
	weight = w;
	Total += n * w;

	return Total;
}

double Cargo::Out(){
	int n, w;
	cout<< "请输入卖出的货物的数量和每箱的重量：";
	cin >> n >> w;
	weight = w;
	Total -= n*w;

	return Total;
}

void Cargo::Show(){
	cout << "目前库存的货物的总量为："<<Total<<endl;
}

int main()
{
	Cargo obj;
	int n;
	char c;
mark:
	cout<<"********************************请选择服务项目********************************"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~1.购进货物~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~2.卖出货物~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~3.退出系统~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cin >> n;
	switch(n){
	case 1:
		obj.In();
		obj.Show();
		break;
	case 2:
		obj.Out();
		obj.Show();
		break;
	case 3:
		break;
	default:
		break;
	}
	cout<<"是否继续？(Y/N)";
	cin >> c;
	if(c == 'y' || c == 'Y')
		goto mark;
	
	return 0;
}

