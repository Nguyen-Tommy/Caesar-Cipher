// Caesar Cipher
// Encrypt a secret code with caesar cipher. 
// Decrypt a caesar cipher through every possible shift.

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

string cipher(string word, int shifts) {

	// Shift through desired number of times
	for (int i = 0; i < shifts; i++) {
		word = shift(word);
	}

	return word;
}

void decipher(string word) {

	// Shift through 25 possible combinations
	for (int i = 0; i < 25; i++) {
		word = shift(word);
		cout << word << endl;
	}
}

int main() {
	string word; // String variable
	int shifts; // Integer variable

	// User input
	cout << "Enter a caesar cipher: ";
	cin >> word;
	cout << "Enter number of shifts: ";
	cin >> shifts;

	word = cipher(word, shifts);

	cout << "Encryted secert code: " << word << endl;

	cout << "Decryted code:\n";
	decipher(word);
}