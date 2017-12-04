#include "StdAfx.h"
#include "Computer.h"
#include "iostream"
using namespace std;


Computer::Computer(CPU* x1, RAM* x2, cd_ROM* x3)
{
	cpu = x1;
	ram = x2;
	cd_rom = x3;
}


Computer::~Computer(void)
{
}

void Computer::run(void){
	cout << "computer run" << endl;
}

void Computer::stop(void){
	cout << "Computer stop" <<endl;
}

int main(){

	CPU* cpu = new CPU(p1, 1000, 220.0);

	system("pause");
	return 0;
}

