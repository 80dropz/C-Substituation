#include <iostream>
#include <string>
#include <list>
#include <Windows.h>
#include <fstream>
#include <filesystem>


void decryptionproccess();
std::string subsitiute();
char EncryptedMessageFunction(int position);
int FindPos(char Letter);



void decryption();
char DecryptMessageFunction(int pos);
int DFindPos(char Charecter);



std::list<char> Alphabet = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z'
};
std::list<char> KeyList;
std::list<char> MessageList;

std::string KeyFile = "Key.txt";
int choice;
std::string EncryptedMessage;
std::string DecryptedMessage;


int main()
{
	
	std::cout << "1: Encrypt \n2: Decrypt\nCHOICE: ";
	std::cin >> choice;
	if (choice == 2)
	{
		decryptionproccess();
	}
	else if (choice == 1)
	{
		std::string message;
		std::string Key;
		std::cout << "Key: ";
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
	else
	{
		std::cout << "INVALID OPTION";
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


void decryptionproccess()
{
	std::string decryptionKey;
	std::string DecryptencryptedMessage;
	std::cout << "Key: ";
	std::cin >> decryptionKey;
	std::cout << "\nEncrypted Message: ";
	std::cin >> DecryptencryptedMessage;
	for (char c : decryptionKey)
	{
		KeyList.push_back(c);
	}
	for (char c : DecryptencryptedMessage)
	{
		MessageList.push_back(c);
	}
	decryption();
}


void decryption()
{
	for (char I : MessageList)
	{
		char DecryptedChar = DecryptMessageFunction(DFindPos(I));
		DecryptedMessage += DecryptedChar;
	}
	std::cout << "Your Message Is: " << DecryptedMessage << std::endl;
	Sleep(10000);
	main();
}

int DFindPos(char Charecter)
{
	int pos = 0;
	for (auto it = KeyList.begin(); it != KeyList.end(); ++it)
	{
		if (*it == Charecter)
		{
			return pos;
		}
		pos++;
	}
}
char DecryptMessageFunction(int pos)
{
	if (pos >= 0 && pos <= 25)
	{
		auto it = Alphabet.begin();
		std::advance(it, pos);
		return *it;
	}
}
