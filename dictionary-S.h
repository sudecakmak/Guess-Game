// Sude Çakmak
// 152120201044

#ifndef dictionary_h
#define dictionary_h

using namespace std;

class Dictionary
{
public:
	Dictionary() {};
	
	~Dictionary() {};

	Dictionary(const char *);

	string BringValidWord();

	bool IsWordValid(string);

private:
	bool TestLegalSecretWord(string);
	set<string> words;
	vector<string> secrets;
	string temporary, buffer, secret;
	fstream textfile;
};

#endif 