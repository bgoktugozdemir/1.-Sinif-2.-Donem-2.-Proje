#include "User.h"
#include <fstream>


User::User(int UserId, userType UserType, string UserName, string UserPassword, string UserEmail)
{
	this->UserId = UserId;
	this->UserType = UserType;
	this->UserName = UserName;
	this->UserPassword = UserPassword;
	this->UserEmail = UserEmail;
}

User::User()
{
	this->UserId = 0;
	//this->UserType = NULL;
	this->UserName = "";
	this->UserPassword = "";
	this->UserEmail = "";
}


User::~User()
{
}

void User::addUser()
{

}

void User::deleteUser()
{

}

void User::editUser()
{

}

void User::showUser()
{

}

/*
int UserId;
userType UserType;
string UserName;
string UserPassword;
string UserEmail;
list <Comment*> comments;
list <Rating*> ratings;
*/

void User::DosyayaYaz()
{
	ofstream dosyaYaz("Users.txt", ios::app);
	//	dosyaYaz << UserId << " " << UserType << " " << UserName << " " << UserPassword << " " << UserEmail << " " << Comment.comments << Rating.ratings << endl; //TODO: List'li komutlar tamamlanacak.
	dosyaYaz.close();
}

void User::DosyayiOku()
{

}