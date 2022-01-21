#pragma once
#include "Menu.h"

class DeletePerson:public AbstractMenu
{
public:
	
	DeletePerson();
	MenuId Show();
};

class DeleteUtility :public AbstractMenu
{
public:
	DeleteUtility();
	MenuId Show();
};
