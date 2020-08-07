// Caesar Cipher
// Encrypt a secret code with caesar cipher
// Decrypt a caesar cipher code through brute force
// Guess through frequency analysis

#include<iostream>
#include<string>
using namespace std;

// Shift given string letters by 1
string shift(string word) {

	// Iterate through string and shift letters by 1
	for (int i = 0; i < word.size(); i++) {

		// Ignore non-alphabetical chars
		if (isalpha(word[i])) {

			// Check for lower or upper case letters and shift according
			if (islower(word[i]))
				word[i] = ((word[i] - 'a') + 1) % 26 + 'a';
			else
				word[i] = ((word[i] - 'A') + 1) % 26 + 'A';
		}
	}
	return word;
}

// Print encrypted Caesar cipher code
void cipher(string word, int shifts) {

	// Shift through desired number of times
	for (int i = 0; i < shifts; i++) {
		word = shift(word);
	}
	cout << "Encryted secert code: " << word << endl;
}

// Calculate percentages of letters for given string
void calculatePercentages(double percentages[], string word) {
	int letters[26] = { 0 };
	int total = 0;

	// Iterate through the string
	for (int count = 0; count < word.size(); count++) {

		// Ignore non-alphabetical chars
		if (isalpha(word[count])) {
			word[count] = tolower(word[count]); // 

			// Increment corresponding letters
			switch (word[count]) {
			case 'a':
				letters[0]++;
				break;
			case 'b':
				letters[1]++;
				break;
			case 'c':
				letters[2]++;
				break;
			case 'd':
				letters[3]++;
				break;
			case 'e':
				letters[4]++;
				break;
			case 'f':
				letters[5]++;
				break;
			case 'g':
				letters[6]++;
				break;
			case 'h':
				letters[7]++;
				break;
			case 'i':
				letters[8]++;
				break;
			case 'j':
				letters[9]++;
				break;
			case 'k':
				letters[10]++;
				break;
			case 'l':
				letters[11]++;
				break;
			case 'm':
				letters[12]++;
				break;
			case 'n':
				letters[13]++;
				break;
			case 'o':
				letters[14]++;
				break;
			case 'p':
				letters[15]++;
				break;
			case 'q':
				letters[16]++;
				break;
			case 'r':
				letters[17]++;
				break;
			case 's':
				letters[18]++;
				break;
			case 't':
				letters[19]++;
				break;
			case 'u':
				letters[20]++;
				break;
			case 'v':
				letters[21]++;
				break;
			case 'w':
				letters[22]++;
				break;
			case 'x':
				letters[23]++;
				break;
			case 'y':
				letters[24]++;
				break;
			case 'z':
				letters[25]++;
				break;
			}
			total++;
		}
	}

	// Calculate the percentage of each letter from the string
	percentages[0] = (double)letters[0] / total * 100;
	percentages[1] = (double)letters[1] / total * 100;
	percentages[2] = (double)letters[2] / total * 100;
	percentages[3] = (double)letters[3] / total * 100;
	percentages[4] = (double)letters[4] / total * 100;
	percentages[5] = (double)letters[5] / total * 100;
	percentages[6] = (double)letters[6] / total * 100;
	percentages[7] = (double)letters[7] / total * 100;
	percentages[8] = (double)letters[8] / total * 100;
	percentages[9] = (double)letters[9] / total * 100;
	percentages[10] = (double)letters[10] / total * 100;
	percentages[11] = (double)letters[11] / total * 100;
	percentages[12] = (double)letters[12] / total * 100;
	percentages[13] = (double)letters[13] / total * 100;
	percentages[14] = (double)letters[14] / total * 100;
	percentages[15] = (double)letters[15] / total * 100;
	percentages[16] = (double)letters[16] / total * 100;
	percentages[17] = (double)letters[17] / total * 100;
	percentages[18] = (double)letters[18] / total * 100;
	percentages[19] = (double)letters[19] / total * 100;
	percentages[20] = (double)letters[20] / total * 100;
	percentages[21] = (double)letters[21] / total * 100;
	percentages[22] = (double)letters[22] / total * 100;
	percentages[23] = (double)letters[23] / total * 100;
	percentages[24] = (double)letters[24] / total * 100;
	percentages[25] = (double)letters[25] / total * 100;
}

// Compare the difference of given letter percentages with presumed data
double compare(double percentages[]) {
	double result = 0;
	double data[] = { 8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0,
		2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1 };

	// Iterate through the data and add the resulting difference
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) 
		result += abs(data[i] - percentages[i]);
	return result;
}

// Print brute forced decrypted Caesar cipher code
void decipher(string word) {
	pair<string, double> guesses[4];
	double percentages[26];

	// Shift through 25 possible combinations
	for (int i = 0; i < 25; i++) {
		word = shift(word);
		cout << word << endl;

		// Retrieve the difference double for each string
		calculatePercentages(percentages, word);
		pair<string, double> pair;
		pair.first = word;
		pair.second = compare(percentages);

		// Iterate through guesses
		for (int j = 0; j < sizeof(guesses) / sizeof(guesses[0]); j++){

			// Check if empty slot
			if (guesses[j].second == NULL) {
				guesses[j] = pair;
				break;
			}

			// Check if pair's difference is less than guesses'
			if (pair.second < guesses[j].second) {

				// Check if not at end of array
				if (j != sizeof(guesses) / sizeof(guesses[0]) - 1) {

					// Shift elements in array right by 1 to open slot for new entry
					for (int k = sizeof(guesses) / sizeof(guesses[0]) - 1; k > j; k--)
						guesses[k] = guesses[k - 1];
				}
				guesses[j] = pair;
				break;
			}
		}
	}

	cout << "Guess:\n" + guesses[0].first << endl;

	// Retrieve user input if guess was correct
	int input;
	cout << "Correct guess?\n"
		"1. Yes\n"
		"2. No\n";
	cin >> input;

	// Print other possible guesses if guess was wrong
	if (input == 1)
		cout << "Yay!" << endl;
	else if (input == 2) {
		cout << "Other possible guesses:" << endl;

		// Iterate through guesses and print string
		for (int i = 1; i < sizeof(guesses) / sizeof(guesses[0]); i++) {
			cout << guesses[i].first << endl;
		}
	}
	else
		cout << "Invalid input" << endl;
}

// Main menu 
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
			cin.ignore();
			getline(cin, word);
			cout << "Enter the number of shifts: ";
			cin >> shifts;

			cipher(word, shifts);
		}
		else if (input == 2) {

			// User input
			cout << "Enter a caesar cipher code: ";
			cin.ignore();
			getline(cin, word);

			cout << "Decryted code:\n";
			decipher(word);
		}
		else if (input == 3)
			break;
		else
			cout << "Invalid input.\n";
	}
}