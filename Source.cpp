// Hangman The classic game of hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;


int main()
{
	//To setup 
	const int MAX_WRONG = 5; //That it maximum number of incorrect guesses allowed 

	vector<string>words; // It collect of possible words to guess
	words.push_back("RHYME");
	words.push_back("PARADOX");
	words.push_back("METAPHOR");
	words.push_back("SONNET");
	words.push_back("SIMILE");
	words.push_back("STANZA");
	words.push_back("SYNTAX");
	words.push_back("VOLTA");
	words.push_back("PARADOX");
	words.push_back("METAPHOR");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0]; // The word to guess
	int wrong = 0; //The number of incorrect guesses
	string soFar(THE_WORD.size(), '-'); //The word guessed so far
	string used = ""; // The letters that already guessed

	cout << "Welcome to Code Breaker Training Simulation Program for CIA Recruits II. Have fun!!!\n";
	//main loop 
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have" << (MAX_WRONG - wrong);
		cout << "incorrect guesses left.\n";
		cout << "\nYou've used the follwing letters:\n" << soFar << endl;

		char guess;
		cout << "\n\nJust enter your guess.";
		cin >> guess;
		guess = toupper(guess); //To make sure uppercase since word in uppercase
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed" << guess << endl;
			cout << "Just enter your guess.";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "It's right!!" << guess << "is in the word.\n";
			//so to update soFar that include newly guessed letter
			for (int i = 0;i < THE_WORD.length();++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry," << guess << " isn't in the world.\n";
			++wrong;
		}
	}
	//shut it down
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou've been hanged!!";
	}
	else
	{
		cout << "\nThat you guessed it!!!";
	}
	cout << "\nThe word was" << THE_WORD << endl;

	return 0;
}