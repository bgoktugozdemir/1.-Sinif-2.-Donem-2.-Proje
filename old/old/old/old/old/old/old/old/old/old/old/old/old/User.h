#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Comment.h"
#include "Rating.h"
#include "CommonData.h"

using namespace std;
class Comment;
class Rating;

class User
{
public:
	int UserId;
	userType UserType;
	string UserName;
	string UserPassword;
	string UserEmail;
	list <Comment*> comments;
	list <Rating*> ratings;

	User(int UserId, userType UserType, string UserName, string UserPassword, string UserEmail);
	User();
	~User();
	void addUser();
	void deleteUser();
	void editUser();
	void showUser();
	void DosyayaYaz();
	void DosyayiOku();
};

