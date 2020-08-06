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
	int total = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0,
		i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0,
		s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;

	// Iterate through the string
	for (int count = 0; count < word.size(); count++) {

		// Ignore non-alphabetical chars
		if (isalpha(word[i])) {
			word[count] = tolower(word[count]); // 

			// Increment corresponding letters
			switch (word[count]) {
			case 'a':
				a++;
				break;
			case 'b':
				b++;
				break;
			case 'c':
				c++;
				break;
			case 'd':
				d++;
				break;
			case 'e':
				e++;
				break;
			case 'f':
				f++;
				break;
			case 'g':
				g++;
				break;
			case 'h':
				h++;
				break;
			case 'i':
				i++;
				break;
			case 'j':
				j++;
				break;
			case 'k':
				k++;
				break;
			case 'l':
				l++;
				break;
			case 'm':
				m++;
				break;
			case 'n':
				n++;
				break;
			case 'o':
				o++;
				break;
			case 'p':
				p++;
				break;
			case 'q':
				q++;
				break;
			case 'r':
				r++;
				break;
			case 's':
				s++;
				break;
			case 't':
				t++;
				break;
			case 'u':
				u++;
				break;
			case 'v':
				v++;
				break;
			case 'w':
				w++;
				break;
			case 'x':
				x++;
				break;
			case 'y':
				y++;
				break;
			case 'z':
				z++;
				break;
			}
			total++;
		}
	}

	// Calculate the percentage of each letter from the string
	percentages[0] = (double)a / total * 100;
	percentages[1] = (double)b / total * 100;
	percentages[2] = (double)c / total * 100;
	percentages[3] = (double)d / total * 100;
	percentages[4] = (double)e / total * 100;
	percentages[5] = (double)f / total * 100;
	percentages[6] = (double)g / total * 100;
	percentages[7] = (double)h / total * 100;
	percentages[8] = (double)i / total * 100;
	percentages[9] = (double)j / total * 100;
	percentages[10] = (double)k / total * 100;
	percentages[11] = (double)l / total * 100;
	percentages[12] = (double)m / total * 100;
	percentages[13] = (double)n / total * 100;
	percentages[14] = (double)o / total * 100;
	percentages[15] = (double)p / total * 100;
	percentages[16] = (double)q / total * 100;
	percentages[17] = (double)r / total * 100;
	percentages[18] = (double)s / total * 100;
	percentages[19] = (double)t / total * 100;
	percentages[20] = (double)u / total * 100;
	percentages[21] = (double)v / total * 100;
	percentages[22] = (double)w / total * 100;
	percentages[23] = (double)x / total * 100;
	percentages[24] = (double)y / total * 100;
	percentages[25] = (double)z / total * 100;
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