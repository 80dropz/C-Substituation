#include <iostream>
#include <string>
#include <list>
#include <Windows.h>
std::string subsitiute();
char EncryptedMessageFunction(int position);
std::string EncryptedMessage;
int FindPos(char Letter);
std::list<char> Alphabet = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z'
};
std::list<char> KeyList;

std::list<char> MessageList;

int main()
{
	std::string message;
	std::string Key;
	std::cin >> Key;
	int keylen = Key.length();
	if (keylen > 26)
	{
		std::cout << "Key is too long \nMust be 26 charecters" << std::endl;
	}
	else if (keylen < 26)
	{
		std::cout << "Key is too short \nKey must be 26 charecters" << std::endl;
	}
	else
	{
		std::cout << "What do you want to encrypt" << std::endl;
		std::cin >> message;
		std::cout << "Just right" << std::endl;
		for (char c : Key)
		{
			KeyList.push_back(c);
		}
		Sleep(1000);
		std::cout << "it sent the key to the list";
		for (char c : message)
		{
			MessageList.push_back(c);
		}
		Sleep(1000);
		std::cout << "It sent the message to the list";
		std::cout << "Encrypted Message: " << subsitiute() << std::endl;

	}

}

std::string subsitiute()
{
	for (char i : MessageList)
	{
		std::cout << i << std::endl;
		char newchar = EncryptedMessageFunction(FindPos(i));
		EncryptedMessage += newchar;
		Sleep(1000);
		std::cout << EncryptedMessage;
	}
	return EncryptedMessage;
}

int FindPos(char Letter)
{
	int pos = 0;
	for (auto it = Alphabet.begin(); it != Alphabet.end(); ++it)
	{
		if (*it == Letter)
		{
			return pos;
		}
		pos++;
	}
}
char EncryptedMessageFunction(int position)
{
	if (position >= 0 && position <= 25)
	{
		auto it = KeyList.begin();
		std::advance(it, position);
		return *it;
	}
}
