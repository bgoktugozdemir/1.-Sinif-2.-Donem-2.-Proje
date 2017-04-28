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
	
	
	/*
	User user1(8, Member, "goktug", "123", "goktuggg@hotmail.com");
	//User* user1 = new User(8, Member, "goktug", "123", "goktuggg@hotmail.com");
	Comment comment(3, time(NULL), "Bugun cok iyisin hee", &user1);
	comment.addComment();
	Comment DosyayiOku();
	return 0;
	Comment  yorum;
	yorum.CommentTime = time(NULL);
	cout << yorum.CommentTime << endl;
	cout << "Yazilimimiz tam surumuyle yakinda sizlerle..." << endl;
	return 0;
	*/
}
