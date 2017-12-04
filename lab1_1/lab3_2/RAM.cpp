#include "StdAfx.h"
#include "RAM.h"


RAM::RAM(int x1, int x2, enum Type x3)
{
	capacity = x1;
	frequency = x2;
	type = x3;
}

RAM::RAM()
{
}

RAM::~RAM(void)
{
}
