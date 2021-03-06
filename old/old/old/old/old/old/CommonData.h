#pragma once
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
#include <list>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <locale.h>

#include "Background.h"
#include "Comment.h"
#include "Database.h"
#include "Interface.h"
#include "Movie.h"
#include "Rating.h"
#include "Studio.h"
#include "User.h"

#define Version 1.08

using namespace std;

enum userType
{
	Administrator,
	Writer,
	MovieCritic,
	Member
};