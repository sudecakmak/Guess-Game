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

bool Dictionary::TestLegalSecretWord(string Word)
{
	bool LegalWord = true;

	for (int i = 0; i < Word.length() - 1; i++)
	{
		for (int j = i + 1; j < Word.length(); j++)
		{
			if (Word[i] == Word[j])
			{
				LegalWord = false;
			}
		}
	}

	return LegalWord;
}

bool Dictionary::IsWordValid(string guessword)
{
	bool ValidWord = false;
	string word;

	textfile.open("words.txt", ios::in);

	if (!textfile)
	{
		cout << "Error opening file!" << endl;
		exit(0);
	}

	while (getline(textfile, word))
	{
		if (word.find(guessword) != string::npos)
		{
			ValidWord = true;
		}
	}

	if (5 > guessword.length())
	{
		ValidWord = false;
	}

	textfile.close();

	return ValidWord;
}

Dictionary::Dictionary(const char *filename)
{
	Dictionary d;

	textfile.open(filename, ios::in);

	if (!textfile)
	{
		cout << "Error opening file!" << endl;
		exit(0);
	}
	else
	{
		textfile >> temporary;

		while (!textfile.eof())
		{
			words.insert(temporary);
			textfile >> temporary;
		}
	}

	textfile.close();

	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		if (d.TestLegalSecretWord(*it))
		{
			buffer = *it;
			secrets.insert(secrets.end(), buffer);
		}
	}
}

string Dictionary::BringValidWord()
{
	srand(time(0));
	secret = secrets[rand() % secrets.size()];

	return secret;
}

int Words::countofMatchLetters(string guessword, string secretword)
{
	int counterOfMatchingLetters = 0;

	for (int i = 0; i < secretword.length(); i++)
	{
		for (int j = 0; j < secretword.length(); j++)
		{
			if (secretword[i] == guessword[j])
			{
				counterOfMatchingLetters++;
				i++;
				j = 0;
			}
		}
	}

	return counterOfMatchingLetters;
}

int Words::countOfLettersTruePlace(string guessword, string secretword)
{
	int counterOfRightPlaceLetters = 0;

	for (int i = 0; i < secretword.length(); i++)
	{
		if (guessword[i] == secretword[i])
		{
			counterOfRightPlaceLetters++;
		}
	}

	return counterOfRightPlaceLetters;
}

void Words::playgame(Words &)
{
	Words w;
	Dictionary d;

	cout << "Bilbakalim Oyununa Hosgeldiniz:" << endl;
	cout << "5 harften olusan bir kelime tuttum." << endl;

	while (1)
	{
		cout << endl << "Tahmininiz Nedir? ";
		getline(cin, guess);

		if (secret == guess)
		{
			numberofguesses++;
			break;
		}

		if (guess == "xxxxx")
		{
			cout << "Ipucu: Gizli kelime: " << secret << endl;
			numberofguesses++;
			cheated = true;
		}

		if (d.IsWordValid(guess) == false)
		{
			if (guess != "xxxxx")
			{
				cout << "Bu kelime sozlukte yok!" << endl;
			}
		}
		else
		{
			cout << "Eslesen harf sayisi:" << w.countofMatchLetters(guess, secret);
			cout << endl << "Eslesen harflerin dogru konumu: " << w.countOfLettersTruePlace(guess, secret) << endl;
			numberofguesses++;
		}
	}

	if (cheated == true)
	{
		cout << endl << "Bildiniz! " << numberofguesses << " tahminde ipucu kullanarak dogru sonuca ulastiniz!";
	}
	else
	{
		cout << endl << "Bildiniz! " << numberofguesses << " tahminde dogru sonuca ulastiniz!";
	}

	cout << "\n\n\n\n";
}