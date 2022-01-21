#pragma once
#include "Menu.h"

class ChangePerson :public AbstractMenu
{

public:
	ChangePerson();
	MenuId Show();
};

class ChangeUtility :public AbstractMenu
{
public:
	ChangeUtility();
	MenuId Show();
};