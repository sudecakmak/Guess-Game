// Sude Çakmak
// 152120201044

#ifndef words_h
#define words_h

using namespace std;

class Words
{
public:
	Words() {};
	
	~Words() {};
	
	void playgame(Words &);

	string secret;

private:
	string guess;
	bool cheated = false;
	int numberofguesses = 0;
	int countofMatchLetters(string, string);
	int countOfLettersTruePlace(string, string);
};

#endif 
