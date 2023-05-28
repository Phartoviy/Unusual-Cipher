#include <iostream>
#include <map>

using namespace std;


class Cipher
{
	map <char, int> table;
	char alphavit[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
	'v','w','x','y','z' };
	int indexLetter;
public:
	Cipher()
	{
		table['a'] = 8;
		table['b'] = 17;
		table['c'] = 18;
		table['d'] = 24;
		table['e'] = 29;
		table['f'] = 33;
		table['g'] = 39;
		table['h'] = 43;
		table['i'] = 48;
		table['j'] = 54;
		table['k'] = 58;
		table['l'] = 62;
		table['m'] = 69;
		table['n'] = 73;
		table['o'] = 81;
		table['p'] = 84;
		table['q'] = 92;
		table['r'] = 95;
		table['s'] = 101;
		table['t'] = 102;
		table['u'] = 109;
		table['v'] = 112;
		table['w'] = 119;
		table['x'] = 122;
		table['y'] = 128;
		table['z'] = 133;
	}
	int findKeyIndex(char key)
	{
		for (int i = 0; i < 26; i++)
		{
			if (key == alphavit[i])
				return i+1;
		}
		return -1;
	}
	int findWordIndex(char word)
	{
		for (int i = 0;i<26;i++)
		{
			if (word == alphavit[i])
			{
				indexLetter = i;
				break;
			}
		}
		for (auto& element : table)
		{
			if (element.first == word)
				return element.second;
		}
		return -1;
	}
	char getSymbol(int count)
	{
		return alphavit[(count % 26)+indexLetter];
	}
};





int main()
{
	string words = "ball";
	string keyWord = "abc";
	string encryptionMessage;
	int shift = 0;
	Cipher obj;


	for (int j = 0; j < words.length(); j++)
	{
		//cout << obj.findWordIndex(words[j]);
		//cout << " + " << obj.findKeyIndex(keyWord[(j % keyWord.length())]) <<endl;
		shift = obj.findWordIndex(words[j]) + obj.findKeyIndex(keyWord[(j % keyWord.length())]);
		cout << shift << endl;
		encryptionMessage += obj.getSymbol(shift);
	}
	cout << "\n" << encryptionMessage;


	return 0;
}