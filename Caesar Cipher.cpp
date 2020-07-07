// Caesar Cipher
// Encrypt a secret code with caesar cipher. 
// Decrypt a caesar cipher code through every possible shift.

#include<iostream>
#include<string>
using namespace std;

string shift(string word) {

	// Iterate through string and shift letters by 1
	for (int i = 0; i < word.size(); i++) {
		word[i] = ((word[i] - 'a') + 1) % 26 + 'a';
	}
	return word;
}

void cipher(string word, int shifts) {

	// Shift through desired number of times
	for (int i = 0; i < shifts; i++) {
		word = shift(word);
	}

	cout << "Encryted secert code: " << word << endl;
}

void decipher(string word) {

	// Shift through 25 possible combinations
	for (int i = 0; i < 25; i++) {
		word = shift(word);
		cout << word << endl;
	}
}

int main() {
	string word; 
	int shifts;
	int input;

	cout << "Caesar Cipher.\n";

	while (true) {

		// User prompt
		cout << "1: Encrypt a secret code.\n"
			"2: Decrypt a caesar cipher code.\n"
			"3: Exit.\n";
		cin >> input;

		if (input == 1) {

			// User input
			cout << "Enter a secret code: ";
			cin >> word;
			cout << "Enter the number of shifts: ";
			cin >> shifts;

			cipher(word, shifts);
		}
		else if (input == 2) {

			// User input
			cout << "Enter a caesar cipher code: ";
			cin >> word;

			cout << "Decryted code:\n";
			decipher(word);
		}
		else if (input == 3)
			break;
		else
			cout << "Invalid input.\n";
	}
}