#pragma once
#include "Menu.h"

class Registr :public AbstractMenu
{

public:
	
	Registr();
	MenuId Show();	
};

class Login :public AbstractMenu
{
public:
	Login();
	MenuId Show();
};

class OutputUsers :public AbstractMenu
{
public:
	OutputUsers();
	MenuId Show();
};
