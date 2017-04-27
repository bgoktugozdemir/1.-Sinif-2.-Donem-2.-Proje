#include "Comment.h"


Comment::Comment(int CommentId, time_t CommentTime, string comment, int movie_id, int user_id)
{
	this->CommentId = CommentId;
	this->CommentTime = CommentTime;
	this->comment = comment;
	this->movie_id = movie_id;
	this->user_id = user_id;
}

Comment::Comment()
{
	this->CommentId = 0;
	this->CommentTime = NULL;
	this->comment = "";
}


Comment::~Comment()
{
}


void Comment::addComment()
{
	DosyayaYaz();
}

void Comment::deleteComment()
{

}

void Comment::editComment()
{

}

void Comment::showComment()
{

}

void Comment::DosyayaYaz()
{
	ofstream dosyaYaz("Comments.txt", ios::app);
	dosyaYaz << CommentId << " " << UserId->UserId << " " << CommentTime << " " << comment << " " << endl;
	dosyaYaz.close();
}

void Comment::DosyayiOku()
{
	ifstream dosyaOku("Comments.txt");
	if (dosyaOku.is_open())
	{

		while (!dosyaOku.eof())
		{
			dosyaOku >> CommentId >> UserId->UserId >> CommentTime >> comment;
			cout << CommentId << " " << UserId->UserId << " " << CommentTime << " " << comment << " " << endl;
		}
	}
}