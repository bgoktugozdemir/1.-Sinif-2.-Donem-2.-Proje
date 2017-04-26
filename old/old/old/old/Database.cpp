#include "Database.h"



Database::Database()
{
}


Database::~Database()
{
}

Comment * Database::FindTheComment(int id)
{
	Comment * found = NULL;
	list<Comment*>::iterator i;
	for (i = Comments.begin(); i != Comments.end(); i++)
	{
		if ((*i)->CommentId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

Movie * Database::FindTheMovie(int id)
{
	Movie * found = NULL;
	list<Movie*>::iterator i;
	for (i = Movies.begin(); i != Movies.end(); i++)
	{
		if ((*i)->MovieId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

Rating * Database::FindTheRating(int id)
{
	Rating * found = NULL;
	list<Rating*>::iterator i;
	for (i = Ratings.begin(); i != Ratings.end(); i++)
	{
		if ((*i)->RatingId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

Studio * Database::FindTheStudio(int id)
{
	Studio * found = NULL;
	list<Studio*>::iterator i;
	for (i = Studios.begin(); i != Studios.end(); i++)
	{
		if ((*i)->StudioId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

User * Database::FindTheUser(int id)
{
	User * found = NULL;
	list<User*>::iterator i;
	for (i = Users.begin(); i != Users.end(); i++)
	{
		if ((*i)->UserId == id)
		{
			found = *i;
			break;
		}
	}
	return found;
}

void Database::FillLists()
{
	string directory = "db/";
	string commentPath = directory + "comment.txt";
	string moviePath = directory + "movie.txt";
	string ratingPath = directory + "rating.txt";
	string studioPath = directory + "studio.txt";
	string userPath = directory + "user.txt";
	
	FillLists(commentPath, moviePath, ratingPath, studioPath, userPath);
}

void Database::FillLists(string commentPath, string moviePath, string ratingPath, string studioPath, string userPath)
{
	ReadComment(commentPath);
	ReadMovie(moviePath);
	ReadRating(ratingPath);
	ReadStudio(studioPath);
	ReadUser(userPath);

	RelationCommentsHaveUsers();
	RelationRatingsHaveUsers();
	RelationStudiosHaveMovies();
	RelationCommentsHaveMovies();
	RelationRatingsHaveMovies();
}

bool Database::SaveFiles()
{
	string directory = "db/";
	string commentPath = directory + "comment.txt";
	string moviePath = directory + "movie.txt";
	string ratingPath = directory + "rating.txt";
	string studioPath = directory + "studio.txt";
	string userPath = directory + "user.txt";

	bool isSaved = SaveFiles(commentPath, moviePath, ratingPath, studioPath, userPath);
	return isSaved;
}

bool Database::SaveFiles(string commentPath, string moviePath, string ratingPath, string studioPath, string userPath)
{
	bool isSavedComment = SaveComment(commentPath);
	bool isSavedMovie = SaveMovie(moviePath);
	bool isSavedRating = SaveRating(ratingPath);
	bool isSavedStudio = SaveStudio(studioPath);
	bool isSavedUser = SaveUser(userPath);
	bool result = isSavedComment && isSavedMovie && isSavedRating && isSavedStudio && isSavedUser;

	return result;
}

void Database::ReadComment(string path)
{
	ifstream file;
	file.open(path);

	if (file.is_open())
	{
		char line[1000];
		file.getline(line, 1000);
		int CommentId;
		time_t CommentTime;
		string comment;
		bool isFirstRow = true;
		while (!file.eof())
		{
			if (isFirstRow)
			{
				isFirstRow = false;
				continue;
			}
			file >> CommentId >> CommentTime >> comment;
			Comment * addThis = new Comment (CommentId, CommentTime, comment);
			Commments.push_back(addThis);

			CommentsHaveMovies.push_back(Comm);
			CommentsHaveUsers.push_back();
		}
	}
}

void Database::RelationCommentsHaveUsers()
{
	list<int>::iterator i;
	for (i = CommentsHaveUsers.begin(); i != CommentsHaveUsers.end(); i++)
	{
		User * user = FindTheUser(*i);

		if(user != NULL)
		{
			list<Comment*>::iterator j;
			for (j = Comments.begin(); j != Comments.end(); j++)
			{
				if ((*j)->)
			}
		}
	}
}