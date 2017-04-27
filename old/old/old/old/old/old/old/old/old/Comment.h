#pragma once
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "User.h"

using namespace std;
class User;
class Movie;
class Comment
{
public:
	int CommentId;
	time_t CommentTime;
	User* UserId;
	Movie* MovieId;
	string comment;

	Comment();
	Comment(int CommentId, time_t CommentTime, string comment, User* UserId);
	~Comment();
	void addComment();
	void deleteComment();
	void editComment();
	void showComment();
	void DosyayaYaz();
	void DosyayiOku();
};


