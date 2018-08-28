#include "DeviceDependent.h"
#include "graphics.h"


DeviceDependent::DeviceDependent()
{
	registerDependent(this);
}

DeviceDependent::~DeviceDependent()
{
	unregisterDependent(this);
}
