#include <iostream>
#include <cstring>
#include "myStringClass.h"

using namespace std;

myStringClass::myStringClass()
{
	userInput=nullptr;
	userInputLength=0;
}

myStringClass::myStringClass(const char * str)
{
	userInputLength = strlen(str);
	userInput = new char[userInputLength + 1];
	for (int i = 0; i <userInputLength; i++)
	{
		userInput[i] = str[i]; 
	}
	userInput[userInputLength] = '\0';
}

myStringClass::myStringClass(const myStringClass & obj)
{
	userInputLength = obj.userInputLength;
	userInput = new char[userInputLength + 1];
	for (int i = 0; i<userInputLength; i++)
	{
		userInput[i] = obj.userInput[i];
	}
	userInput[userInputLength] = '\0';
}


myStringClass::~myStringClass()
{
	delete[] userInput;
}
int myStringClass::stringLength() const
{
	return userInputLength;
}
myStringClass & myStringClass::operator=(const myStringClass &otherStringClass)
{
	// TODO: insert return statement here

	if (this != &otherStringClass)
	{
		userInputLength = otherStringClass.userInputLength;

		userInput = new char[userInputLength + 1];

		for (int i = 0; otherStringClass.userInput[i] != '\0'; i++)
		{
			userInput[i] = otherStringClass.userInput[i];
		}

		userInput[userInputLength] = '\0';
	}
	return *this;
}

char & myStringClass::operator[](int index)
{
	// TODO: insert return statement here
	return userInput[index];
}
myStringClass & myStringClass::operator+(const myStringClass & right)
{
	// TODO: insert return statement here
	int size = userInputLength + right.userInputLength;
	char *temp = new char[size + 1];

	for (int i = 0; i < userInputLength; i++)
	{
		temp[i] = userInput[i];
	}
	int j = 0;
	for (int i = userInputLength; i < size; i++)
	{
		temp[i] = right.userInput[j];
		j++;
	}

	temp[size] = '\0';
	myStringClass *object = new myStringClass(temp);
	return *object;
}

bool myStringClass::operator==(const myStringClass & otherStringClass)
{

	if (userInputLength == otherStringClass.userInputLength)
	{
		
		for (int i = 0; i < userInputLength; i++)
		{
			if (userInput[i] != otherStringClass.userInput[i])
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

bool myStringClass::operator!=(const myStringClass &otherStringClass)
{
	if (userInputLength != otherStringClass.userInputLength)
	{
		for (int i = 0; i < userInputLength; i++)
		{
			if (userInput[i] == otherStringClass.userInput[i])
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

bool myStringClass::operator<=(const myStringClass &otherStringClass)
{
	return (*this < otherStringClass)||(*this == otherStringClass);
}

bool myStringClass::operator<(const myStringClass &otherStringClass)
{
	for (int i = 0; i < userInputLength; i++)
	{
		if (userInput[i] < otherStringClass.userInput[i])
		{
			return true;
		}
		if (userInput[i] > otherStringClass.userInput[i])
		{
			return false;
		}
	}
	if (userInputLength < otherStringClass.userInputLength)
	{
		return true;
	}
	else return false;
}

bool myStringClass::operator>=(const myStringClass &otherStringClass)
{
	return  (*this > otherStringClass) || (*this == otherStringClass);
}

bool myStringClass::operator>(const myStringClass &otherStringClass)
{
	for (int i = 0; i < userInputLength; i++)
	{

		if (userInput[i] > otherStringClass.userInput[i])
		{
			return true;
		}
		if (userInput[i] < otherStringClass.userInput[i])
		{
			return false;
		}
	}

	if (userInputLength > otherStringClass.userInputLength)
	{
		return true;
	}

	else return false;

}

ostream & operator<<(ostream& cin, const myStringClass *s)
{
	// TODO: insert return statement here

	for (int i = 0; i < s->stringLength(); i++)
	{
		cin << s->userInput[i];
	}
	return cin;
}

ostream & operator<<(ostream & cin, const myStringClass & s)
{
	// TODO: insert return statement here

	for (int i = 0; i < s.stringLength(); i++)
	{
		cin << s.userInput[i];
	}
	return cin;
}

istream& operator>> (istream&cin, myStringClass&s)
{
	if (s.userInput)
	{
		s.userInputLength = 0;
		delete [] s.userInput;
		s.userInput = nullptr;

	}

	char next_char;

	next_char = cin.get();

	while (next_char != '\n')
	{
		s.userInputLength++;

		char *secArray = new char[s.userInputLength];
		secArray[s.userInputLength - 1] = next_char;

		if (s.userInput != nullptr)
		{
			for (int i = 0; i < s.userInputLength - 1; i++)
			{
				secArray[i] = s.userInput[i];
			}
		}

		delete[] s.userInput;
		s.userInput = secArray;
		secArray = nullptr;
		next_char = cin.get();

	}
	return cin;
}

myStringClass myStringClass::operator+=(myStringClass & right)
{
	*this = *this + right;
	return *this;
}

void myStringClass::validateUserInput(myStringClass & myStringClassObject)
{
	int counter = 0; 

	while (counter < myStringClassObject.userInputLength || myStringClassObject.userInputLength == 0)
	{
		if (myStringClassObject.userInputLength == 0 )
		{
			cout << "You have entered an empty string!" << endl;
			cin >> myStringClassObject;
			counter = 0;
		}
		else if (!isalpha(myStringClassObject.userInput[counter]))
		{

			cout << " You're name should only have letters" << endl;
			cin >> myStringClassObject;
			counter = 0;

		}
		else
		{
			counter++;
		}

	}
}

void myStringClass::validateUserInt(myStringClass & myStringClassObject)
{
	int counter = 0;
	int strLength = myStringClassObject.stringLength();

	while (counter < strLength || strLength == 0)
	{
		if (strLength == 0 || !isdigit(myStringClassObject.userInput[counter]))
		{ 
			if (strLength == 0)
				cout << "the string is empty" << endl;
			else
				cout << "that is not an integer, try again\n";
			cin >> myStringClassObject;
			strLength = myStringClassObject.stringLength();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
}
