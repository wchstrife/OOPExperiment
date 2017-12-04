#pragma once
class RAM
{
private:
	int capacity;
	int frequency;
	enum Type {P1=1,P2,P3,P4,P5,P6,P7} type;

public:
	RAM(int x1, int x2, enum Type type);
	RAM(void);
	~RAM(void);
};

