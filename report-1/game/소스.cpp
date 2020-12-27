#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

int main() {
	
	string solution;
	char ch;
	char flag;
	

	string list[] = { "Apple","Apricot","Avocado","Banana","Bilberry","Blackberry","Blackcurrant","Blueberry","Boysenberry",
"Cantaloupe","Currant","Cherry","Cherimoya","Cloudberry","Coconut","Cranberry","Damson","Date",
"Dragonfruit","Durian","Elderberry","Feijoa","Fig","Goji berry","Gooseberry","Grape","Raisin",
"Grapefruit","Guava","Huckleberry" };

	
	while (true) {
		int tried = 0;
		char bag[30];
		int n = rand() % 30;

		solution = list[n];
		transform(solution.begin(), solution.end(), solution.begin(), tolower);

		string guess(solution.length(), '_');

		cout << endl << "The word now looks like this: " << guess << endl;
		cout << "you have" << 6 - tried << " guesses left" << endl;

		while (true) {
			cout << "You guessed:";
			cin >> ch;
			bag[tried] = ch;
			cout << endl;

			for (int i = 0; i < solution.length(); i++) {
				if (tolower(ch) == tolower(solution[i])) {
					guess[i] = tolower(ch);
				}
			}
			cout << endl << "The word now looks like this: " << guess << endl;
			cout << "you have" << 6-tried << " guesses left(tried letters: ";

			for (int i = 0; i <= tried; i++) {
				cout << bag[i] << ",";
			}
			cout << ")" << endl;

			if (guess == solution) {
				cout << "You Win" << endl;

				break;
			}

			if (tried > 5) {
				break;
			}
			tried += 1;
		}

		cout << "You win or You failed : dictionary (tried letters:";
		for (int i = 0; i <= tried; i++) {
			cout << bag[i] << ",";
		}
		cout << ")" << endl;

		cout << "To be continued? (y/n)";
		cin >> flag;
		if (flag == 'n')
			break;
	}

	return 0;
}