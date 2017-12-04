#pragma once
class cd_ROM
{
private:
	enum InterfaceType {SATA, USB} interfaceType;
	enum InstallationMethod {external, build_in} installMethod;
	int CachingCapacity;
public:
	cd_ROM(enum InterfaceType x1, enum InstallationMethod x2, int x3);
	cd_ROM(void);
	~cd_ROM(void);
};

