#include "StdAfx.h"
#include "cd_ROM.h"


cd_ROM::cd_ROM(enum InterfaceType x1, enum InstallationMethod x2, int x3)
{
	interfaceType = x1;
	installMethod = x2;
	CachingCapacity = x3;
}

cd_ROM::cd_ROM(void){
}

cd_ROM::~cd_ROM(void)
{
}