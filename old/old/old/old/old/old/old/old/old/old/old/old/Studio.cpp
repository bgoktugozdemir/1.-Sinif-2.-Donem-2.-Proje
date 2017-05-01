#include "Studio.h"

using namespace std;

Studio::Studio(int StudioId, string StudioName, string StudioInfo)
{
	this->StudioId = StudioId;
	this->StudioName = StudioName;
	this->StudioInfo = StudioInfo;
}

Studio::Studio()
{
	this->StudioId = 0;
	this->StudioName = "";
	this->StudioInfo = "";
}


Studio::~Studio()
{
}
