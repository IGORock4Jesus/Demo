#pragma once

#include <string>
#include "Mesh.h"

class FbxLoader
{
public:
	FbxLoader();
	~FbxLoader();

	Mesh* Load(std::string filename);
};

