#pragma once

#include <string>


class FbxFile
{
	struct Description
	{
		struct FBXHeaderExtension_
		{
			int FBXHeaderVersion;
			int FBXVersion;
			struct TimeStamp
			{
				int Version;
				int Year;
				int Month;
				int Day;
				int Hour;
				int Minute;
				int Second;
				int Millisecond;
			} CreationTimeStamp;
			std::string Creator;
		};
	};
public:
	FbxFile();
	~FbxFile();
};

