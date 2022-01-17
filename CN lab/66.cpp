#include <bits/stdc++.h>

using namespace std;

string encryptRailFence(string text, int key){

	char encrypt[key][(text.length())];

	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			encrypt[i][j] = '1';

	bool direction = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++){
		
		if (row == 0 || row == key-1)
			direction = !direction;

		encrypt[row][col++] = text[i];

		direction ? row++ : row--;
	}

	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (encrypt[i][j]!='1')
				result.push_back(encrypt[i][j]);

	return result;
}

string decryptRailFence(string cipher, int key){

	char decrypt[key][cipher.length()];

	for (int i=0; i < key; i++)
		for (int j=0; j < cipher.length(); j++)
			decrypt[i][j] = '1';

	bool direction;
	int row = 0, col = 0;

	for (int i=0; i < cipher.length(); i++)
    {
		if (row == 0)
			direction = true;

		if (row == key-1)
			direction = false;

		decrypt[row][col++] = '*';

		direction ? row++ : row--;
	}

	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<cipher.length(); j++)
			if (decrypt[i][j] == '*' && index<cipher.length())
				decrypt[i][j] = cipher[index++];


	string result;
	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
    {
		if (row == 0)
			direction = true;

		if (row == key-1)
			direction = false;

		if (decrypt[row][col] != '*')
			result.push_back(decrypt[row][col++]);

		direction ? row++: row--;
	}
	return result;
}

int main(){

    int key;
    string cipher,temp;

    cout << "Enter encryption key \n\t> ";
    cin >> key;

    cout << "\nEnter encryption text \n\t> ";
	getline(cin >> ws, cipher);

    cout << "\nEncrypted from: \'" << cipher.c_str();
	temp = encryptRailFence(cipher, key);
	cout << "\' to: \'" << temp << "\'" << endl;

    cout << "\n1: Decrypt \t\t 2: Exit\n";
    int ch;
    cout << "\nHow would you like to proceed: ";
    cin >> ch;

    if(ch == 1){
        cout << "\nDecrypted back from: \'" << temp.c_str();
        cout << "\' to: \'" << decryptRailFence(temp, key) << "\'" << endl;
    }

    else
        cout << "\nExit...";

	return 0;
}