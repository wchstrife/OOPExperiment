// lab2_2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout<< "�����빺�������������ÿ�������: ";
	cin >> n >> w;
	weight = w;
	Total += n * w;

	return Total;
}

double Cargo::Out(){
	int n, w;
	cout<< "�����������Ļ����������ÿ���������";
	cin >> n >> w;
	weight = w;
	Total -= n*w;

	return Total;
}

void Cargo::Show(){
	cout << "Ŀǰ���Ļ��������Ϊ��"<<Total<<endl;
}

int main()
{
	Cargo obj;
	int n;
	char c;
mark:
	cout<<"********************************��ѡ�������Ŀ********************************"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~1.��������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~2.��������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~3.�˳�ϵͳ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
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
	cout<<"�Ƿ������(Y/N)";
	cin >> c;
	if(c == 'y' || c == 'Y')
		goto mark;
	
	return 0;
}

