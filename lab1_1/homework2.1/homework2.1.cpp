// homework2.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include <stdlib.h>

using namespace std;

class Student{

public:

	string strName;

	Student(){
	}

	Student(string _name){
		strName = _name;
	}

	Student(const Student& stu){
		strName = stu.strName;
	}

	~Student(){
	}

	void setName(string _name){
		strName = _name;
	}

	string getName(){

		return strName;
	}
};

int main()
{
	Student *stu = new Student("����");
	cout << stu->strName << endl;

	system("pause");
	return 0;
}

