#pragma once

#include "DeviceDependent.h"


bool initializeGraphics();
void releaseGraphics();

void registerDependent(DeviceDependent* dependent); 
void unregisterDependent(DeviceDependent* dependent);


void startRendering();
void stopRendering();