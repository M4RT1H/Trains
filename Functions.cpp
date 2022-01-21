#include "Functions.h"
#include "Train.h"
#include <iostream>   
#include <string> 

string login(int len, bool safe)
{
	string str = "";
	char c;
	int i = 0;

	fflush(stdin);
	while (TRUE)
	{
		c = _getch();

		if (c > 0)
		{
			if (c == 8)
			{
				if (i != 0)
				{
					str.pop_back();
					i--;
					cout << "\b \b";
				}
			}
			else
				if (c == 13)
					break;
				else
					if (i < len)
					{
						if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
						{
							i++;
							str += c;
							fflush(stdin);
							if (!safe)
								cout << c;
							else
								cout << '*';
						}
					}
		}
		else
			_getch();

	}

	return str;
}
float flt(int len)
{
	string str;
	char c;
	int i = 0, dot = 0;

	fflush(stdin);
	while (TRUE)
	{
		c = _getch();

		if (c > 0)
		{
			if (c == 8)
			{
				if (i != 0)
				{
					i--;
					cout << "\b \b";
					if (str[i] == '.')
						dot = 0;
					str.pop_back();
				}
			}
			else
				if (c == 13)
					break;
				else
					if ((i < len) && ((c > 47 && c < 58) || (c == 46 && dot == 0)))
					{
						i++;
						str += c;
						fflush(stdin);
						cout << c;
						if (c == 46)
							dot++;
					}
		}
		else
			_getch();
	}
	if (str == "")
		return -1;

	return stof(str);
}
string str(int len)
{
	string str = "";
	int c;
	int i = 0;

	fflush(stdin);
	while (TRUE)
	{
		c = _getch();
		if (c > 0)
		{
			if (c == 8)
			{
				if (i != 0)
				{
					str.pop_back();
					i--;
					cout << "\b \b";
				}
			}
			else
				if (c == 13)
					break;
				else
					if (i < len)
					{
						if ((c > 31 && c < 127) || (c > 159))
						{
							i++;
							str += c;
							fflush(stdin);
							cout << (char)c;
						}
					}
		}
		else
			_getch();

	}
	return str;
}
int integer(int len)
{
	string str;
	char c;
	int i = 0;

	fflush(stdin);
	while (TRUE)
	{
		c = _getch();

		if (c > 0)
		{
			if (c == 8)
			{
				if (i != 0)
				{
					str.pop_back();
					i--;
					cout << "\b \b";
				}
			}
			else
				if (c == 13)
					break;
				else
					if ((i < len) && (c > 47 && c < 58))
					{
						i++;
						str += c;
						fflush(stdin);
						cout << c;
					}
		}
		else
			_getch();
	}
	if (str == "")
		return -1;
	int d = atoi(str.c_str());
	return d;
}
void encription::encript(char* s)
{
	for (int i = 0; s[i] != NULL; i++)
		s[i] = (s[i] ^ encipt_key) + encipt_key;

}
void encription::decript(char* data)
{
	*data = (*data - encipt_key) ^ encipt_key;
}


unsigned char toLowerReg(unsigned char c)
{
	if (c >= 192 && c < 224)
	{
		c += 32;
	}

	if (c >= 65 && c <= 90)
	{
		c += 32;
	}

	if (c == 168)
	{
		c = 197;
	}

	if (c == 184)
	{
		c = 229;
	}

	return c;
}
int strCmpReg(string s1, string s2)
{
	int i = 0;
	while (true)
	{
		unsigned char c1 = toLowerReg(s1[i]);
		unsigned char c2 = toLowerReg(s2[i]);

		if (c1 == NULL && c2 == NULL)
		{
			return 0;
		}

		if (c1 == NULL && c2 != NULL)
		{
			return 1;
		}

		if (c1 != NULL && c2 == NULL)
		{
			return -1;
		}

		if (c2 == c1)
		{
			i++;
			continue;
		}

		if (c2 > c1)
		{
			return 1;
		}

		if (c2 < c1)
		{
			return -1;
		}
	}
}