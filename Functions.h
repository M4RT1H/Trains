#pragma once
#include"Train.h"
#include "List.h"


class encription
{
	static const int encipt_key = 37;
public:
	static void encript(char*);
	static void decript(char*);
};

float flt(int len);
string str(int len);
int integer(int len);
string login(int len, bool safe);
int strCmpReg(string s1, string s2);
unsigned char toLowerReg(unsigned char c);