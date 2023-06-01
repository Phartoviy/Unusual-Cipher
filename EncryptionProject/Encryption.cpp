#include <iostream>
#include <map>

using namespace std;


class Cipher
{
	map <char, int> table;
	char alphavit[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u',
	'v','w','x','y','z' };
	int indexLetter;
	string encryptionMessage;
public:
	/// <summary>
	/// constructor init table
	/// </summary>
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
	/// <summary>
	/// finding the letter number of the code word
	/// </summary>
	/// <param name="key">letter key word</param>
	/// <returns>number letter</returns>
	int findKeyIndex(char key)
	{
		for (int i = 0; i < 26; i++)
		{
			if (key == alphavit[i])
				return i+1;
		}
		return -1;
	}
	/// <summary>
	/// finding number letter from unusual table
	/// </summary>
	/// <param name="word">letter word</param>
	/// <returns>number denoting the letter</returns>
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
	/// <summary>
	/// get symbol from alphavit subject to shift
	/// </summary>
	/// <param name="count">number shift</param>
	/// <returns>letter</returns>
	char getSymbol(int count)
	{
		return alphavit[(count % 26)+indexLetter];
	}
	/// <summary>
	/// return message after encrypting
	/// </summary>
	/// <returns>encrypted message</returns>
	string getEncrypt()
	{
		return encryptionMessage;
	}
	/// <summary>
	/// encrypt word
	/// </summary>
	/// <param name="word"></param>
	/// <param name="key"></param>
	void encrypt(string word,string key)
	{
		int shift = 0;
		int count = 0;
		for (int j = 0; j < word.length(); j++)
		{
			if (word[j] == ' ')
			{
				encryptionMessage += " ";
				continue;
			}
			shift = findWordIndex(word[j]) + findKeyIndex(key[(count++ % key.length())]);
			encryptionMessage += getSymbol(shift);
		}
		
	}
	
};





int main()
{
	string words = "ball";
	string keyWord = "abc";
	Cipher cipher;

	cipher.encrypt(words, keyWord);
	cout << cipher.getEncrypt();

	return 0;
}