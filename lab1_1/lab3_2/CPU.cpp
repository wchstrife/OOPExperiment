#include "CPU.h"
#include <iostream>

using namespace std;

CPU::CPU(CPU_Rank cpu_rank, int fre, float v)
{
	rank = cpu_rank;
	frequency = fre;
	voltage = v;
}

CPU::CPU(void){
}

void CPU::run(){
	cout << "CPU RUN" <<endl;
}

void CPU::stop(){
	cout << "CPU STOP" <<endl;
}
