#include <iostream>

using namespace std;

class CPU
{
private:
	enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7} rank;
	int frequency;
	float voltage;

public:
	CPU(enum CPU_Rank cpu_rank, int fre, float v){
		rank = cpu_rank;
		frequency = fre;
		voltage = v;
	}

	void run(){
	}

	void stop(){
	}

}