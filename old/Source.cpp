//Berat G�ktu� �zdemir 150101002

#include <iostream>
#include "Database.h"
#include "Interface.h"

using namespace std;

void main()
{
//	setlocale(LC_ALL, "Turkish");
	
	Database data;
	data.FillLists();
	
	Background background(&data);

	Interface Screens(&data, &background);
	Screens.Start();
	

}
