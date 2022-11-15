// Sude Çakmak
// 152120201044

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>  
#include <vector>
#include <string>
#include <set>
#include <ctime>
#include "words-S.h"
#include "dictionary-S.h"

using namespace std;

int main()
{
	Words Wordsobject;
	Dictionary Dobj("words.txt");

	Wordsobject.secret = Dobj.BringValidWord();

	Wordsobject.playgame(Wordsobject);

	system("pause");
	return 0;
}