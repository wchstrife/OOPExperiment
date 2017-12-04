#pragma once
class cd_ROM;
class CPU;
class RAM;

class Computer
{
private:
	CPU* cpu;
	RAM* ram;
	cd_ROM* cd_rom;

public:
	Computer(CPU* x1, RAM* x2, cd_ROM* x3);
	~Computer(void);
	void run(void);
	void stop(void);
};

