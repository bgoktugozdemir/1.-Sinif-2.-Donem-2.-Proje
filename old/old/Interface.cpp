#include "Interface.h"

Interface::Interface()
{
}

Interface::Interface(Database * data, Background * background)
{
	Datas = data;
	Backgrounds = background
}

Interface::~Interface()
{
}

void Interface::Start()
{
	while (true)
	{
		MainMenu();
		char Selection;
		cin >> Selection;
		system("CLS");
		switch (Selection)
		{
		case 'a':
			Comments();
			break;
		case 'b':
			Movies();
			break;
		case 'c':
			Ratings();
			break;
		case 'd':
			Studios();
			break;
		case 'e':
			Users();
			break;
		case '0':
			exit(0);
			break;
		default:
			Start();
			break;
		}
		system("CLS");
	}
}

void Interface::MainMenu()
{
	char yazi[60];
	sprintf(yazi, "title Welcome back to Movie System (v%.2f)", Version);
	system(yazi);
	cout << "Main Menu" << endl
		 << "a - Comments Menu" << endl
		 << "b - Movies Menu" << endl
		 << "c - Ratings Menu" << endl
		 << "d - Studios Menu" << endl
		 << "e - Users Menu" << endl
	 	 << "0 - Exit" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";
}

void Interface::Comments()
{
	cout << "Comment Menu" << endl;

	ListComments();
}

void Interface::Movies()
{
	cout << "Movies Menu" << endl;
		 
	ListMovies();
}

void Interface::Ratings()
{
	cout << "Rating Menu" << endl;
		
	ListRatings();
}

void Interface::Studios()
{
	cout << "Studio Menu" << endl;
	
	ListStudios();
}

void Interface::Users()
{
	cout << "User Menu" << endl;

	ListUsers();
}

void Interface::ListComments()				//EDÝTLERDEKÝ SORUNU ÇÖZ
{
	ShowComments(Datas->Comments);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit Comment " << endl
		<< "2 - Add Comment " << endl
		<< "3 - Delete Comment " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int CommentId;
		cout << "Please enter the comment's id: ";
		cin >> CommentId;
		EditComments(CommentId);  //DÜZELT
		break;
	case '2':
		AddComments();
		break;
	case '3':
		DeleteComments();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::AddComments()										 //CommentTime'a çözüm bul!++++++
{
	cout << "You will add a new comment..." << endl;
	Comment * newComment = new Comment(-1, time(NULL), "", -1, -1);
}

void Interface::DeleteComments()
{

}

void Interface::ListMovies()
{
	ShowMovies(Datas->Movies);

	//Screen
	cout << endl
		 << "-----------------------------------" << endl
		 << "1 - Edit Movie " << endl
		 << "2 - Add Movie " << endl
		 << "3 - Delete Movie " << endl << endl
	 	 << "0 - Return to Main Menu" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int MovieId;
		cout << "Please enter the movie's id: ";
		cin >> MovieId;
		EditMovies(MovieId);
		break;
	case '2':
		AddMovies();
		break;
	case '3':
		DeleteMovies();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditMovies(Movie * movie)
{
	//ID
	cout << "Movie's Id: " << movie->MovieId << endl
		 << "Please enter a new id: ";
	int newMovieId = -1;
	cin >> newMovieId;

	//TITLE
	cout << "Movie's Title: " << movie->MovieTitle << endl
		 << "Please enter a new title: ";
	string newMovieTitle = "";
	cin >> newMovieTitle;

	//GENRE
	cout << "Movie's Genres: " << movie->MovieGenre << endl
		 << "Please enter new genres: ";
	string newMovieGenre = "";
	cin >> newMovieGenre;

	//RELEASE YEAR
	cout << "Movie's Release Year: " << movie->MovieReleaseYear << endl
		 << "Please enter a new release year: ";
	string newMovieReleaseYear = "";
	cin >> newMovieReleaseYear;

	//LANGUAGE
	cout << "Movie's Language: " << movie->MovieLanguage << endl
		 << "Please enter a new language: ";
	string newMovieLanguage = "";
	cin >> newMovieLanguage;

	//RATING
	cout << "Movie's Rating: " << movie->MovieRating << endl
		 << "Please enter a new rating: ";
	float newMovieRating = -1;
	cin >> newMovieRating;

	//CENSORSHIP
	cout << "Movie's Censorship: " << movie->MovieCensorship << endl
		 << "Please enter a new cencorship: ";
	string newMovieCensorship = "";
	cin >> newMovieCensorship;

	//STORY
	cout << "Movie's Story: " << movie->MovieStory << endl
		 << "Please enter a new story: ";
	string newMovieStory = "";
	cin >> newMovieStory;

	//BUDGET
	cout << "Movie's Budget: " << movie->MovieBudget << endl
		 << "Please enter a new budget: ";
	unsigned int newMovieBudget = 1;
	cin >> newMovieId;

	//STORY
	cout << "Movie's Studio Id: " << movie->studio_id << endl
		 << "Please enter a new studio id: ";
	int newstudio_id = 1;
	cin >> newstudio_id;
	
	//Changes
	movie->MovieId = newMovieId;
	movie->MovieTitle = newMovieTitle;
	movie->MovieGenre = newMovieGenre;
	movie->MovieReleaseYear = newMovieReleaseYear;
	movie->MovieLanguage = newMovieLanguage;
	movie->MovieRating = newMovieRating;
	movie->MovieCensorship = newMovieCensorship;
	movie->MovieStory = newMovieStory;
	movie->MovieBudget = newMovieBudget;
	movie->studio_id = newstudio_id;

	//TODO: ÝLÝÞKÝLER
}

void Interface::AddMovies()
{
	cout << "You will add a new movie..." << endl;

	Movie *newMovie = new Movie(-1, "", "", "", "", -1, "", "", 1, -1);

	EditMovies(newMovie);

	Datas->Movies.push_back(newMovie);
}

void Interface::DeleteMovies()						//ÖðrenciÝþleri Classýna alternatif bul. 
{
	cout << "Please enter the movie's id -> ";
	int id;
	cin >> id;

	if (Backgrounds->RemoveMovie == false)
	{
		cout << "Operation failed!. Please, make sure the movie's id is correct. " << endl;
		DeleteMovies();
	}

	else
	{
		cout << id << "Operation successful!" << endl;
	}
}

void Interface::ListRatings()
{
	ShowRatings(Datas->Ratings);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit Rating " << endl
		<< "2 - Add Rating " << endl
		<< "3 - Delete Rating " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int RatingId;
		cout << "Please enter the rating's id: ";
		cin >> RatingId;
		EditRatings(RatingId);
		break;
	case '2':
		AddRatings();
		break;
	case '3':
		DeleteRatings();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditRatings(Rating * rating)
{
	//ID
	cout << "Rating's Id: " << rating->RatingId << endl
		 << "Please enter a new id: ";
	int newRatingId = -1;
	cin >> newRatingId;

	//RATING
	cout << "Rating's Rating: " << rating->rating << endl
		 << "Please enter a new rating: ";
	float newrating = -1;
	cin >> newrating;

	//USER ID
	cout << "Rating's User Id: " << rating->user_id << endl
		<< "Please enter a new user id: ";
	int newuser_id = 1;
	cin >> newuser_id;

	//MOVIE ID
	cout << "Rating's Movie Id: " << rating->movie_id << endl
		<< "Please enter a new movie id: ";
	int newmovie_id = 1;
	cin >> newmovie_id;

	//CHANGES

	rating->RatingId = newRatingId;
	rating->rating = newrating;
	rating->user_id = newuser_id;
	rating->movie_id = newmovie_id;
}

void Interface::AddRatings()
{
	cout << "You will add a new rating..." << endl;

	Rating *newRating = new Rating(-1, -1, -1, -1);

	EditRatings(newRating);

	Datas->Ratings.push_back(newRating);
}

void Interface::ListStudios()
{
	ShowStudios(Datas->Studios);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit Studio " << endl
		<< "2 - Add Studio " << endl
		<< "3 - Delete Studio " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int StudioId;
		cout << "Please enter the studio's id: ";
		cin >> StudioId;
		EditStudios();
		break;
	case '2':
		AddStudios();
		break;
	case '3':
		DeleteStudios();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditStudios(Studio * studio)
{
	//ID
	cout << "Studio's Id: " << studio->StudioId << endl
		 << "Please enter a new id: ";
	int newStudioId = -1;
	cin >> newStudioId;

	//NAME
	cout << "Studio's Name: " << studio->StudioName << endl
		 << "Please enter a new name: ";
	string newStudioName = "";
	cin >> newStudioName;

	//INFO
	cout << "Studio's Info: " << studio->StudioInfo << endl
		<< "Please enter a new info: ";
	string newStudioInfo = "";
	cin >> newStudioInfo;

	studio->StudioId = newStudioId;
	studio->StudioName = newStudioName;
	studio->StudioInfo = newStudioInfo;
}

void Interface::AddStudios()
{
	cout << "You will add a new studio..." << endl;

	Studio *newStudio = new Studio(-1, "", "");

	EditStudios(newStudio);

	Datas->Studios.push_back(newStudio);
}

void Interface::ListUsers()
{
	ShowUsers(Datas->Users);

	//Screen
	cout << endl
		<< "-----------------------------------" << endl
		<< "1 - Edit User " << endl
		<< "2 - Add User " << endl
		<< "3 - Delete User " << endl << endl
		<< "0 - Return to Main Menu" << endl
		<< "-----------------------------------" << endl
		<< "Please choose one of the options -> ";

	//User
	char Selection = _getch();
	//cin >> Selection;
	switch (Selection)
	{
	case '1':
		int UserId;
		cout << "Please enter the user's id: ";
		cin >> UserId;
		EditUsers();
		break;
	case '2':
		AddUsers();
		break;
	case '3':
		DeleteUsers();
		break;
	case '0':
		MainMenu();
		break;
	}
}

void Interface::EditUsers(User * user)
{
	//ID
	cout << "User's Id: " << user->UserId << endl
		 << "Please enter a new id: ";
	int newUserId = -1;
	cin >> newUserId;

	//USERTYPE
	cout << "User's Type: " << user->UserType << endl;
	userType newUserType = Member;
	cout << "a - Administrator" << endl << "b - Writer" << "c - Movie Critic" << endl << "d - Member" << endl << "Please select a user type: ";
	char Selection = _getch();
	switch (Selection)
	{
	case 'a':
		newUserType = Administrator;
		break;

	case 'b':
		newUserType = Writer;
		break;

	case 'c':
		newUserType = MovieCritic;
		break;

	case 'd':
		newUserType = Member;
		break;

	default:
		newUserType = Member;
		break;
	}

	//NAME
	cout << "User's Name: " << user->UserName << endl
		 << "Please enter a new name: ";
	string newUserName = "";
	cin >> newUserName;

	//PASSWORD
	cout << "User's Password: " << user->UserPassword << endl
		 << "Please enter a new password: ";
	string newUserPassword = "";
	cin >> newUserPassword;

	//MAIL
	cout << "User's Mail: " << user->UserEmail << endl
		 << "Please enter a new email: ";
	string newUserEmail = "";
	cin >> newUserEmail;

	//CHANGES
	user->UserId = newUserId;
	user->UserType = newUserType;
	user->UserName = newUserName;
	user->UserPassword = newUserPassword;
	user->UserEmail = newUserEmail;
}

void Interface::AddUsers()
{
	cout << "You will add a new user..." << endl;

	User *newUser = new User(-1, Member, "", "", "");

	EditUsers(newUser);

	Datas->Users.push_back(newUser);
}
