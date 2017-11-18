// lab1_3.cpp : 定义控制台应用程序的入口点。
//
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	for(int i=1; i<=4 ;i++){
		if( ((i!=1) + (i==3) + (i==2) + (i!=3)) == 3){
			switch(i){
			case 1 : cout << "A" << endl;
				break;
			case 2: cout << "B" << endl;
				break;
			case 3: cout << "C" << endl;
				break;
			case 4: cout << "D" << endl;
				break;
			default: cout << "error";
			}
		}
	}

	system("pause");
	return 0;
}



