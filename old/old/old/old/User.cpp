#include "User.h"
#include <fstream>

using namespace std;

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
