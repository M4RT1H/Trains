#pragma once
#include "Menu.h"
class BuyBilet :public AbstractMenu
{
public:
	BuyBilet();
	MenuId Show();
};

class ShowBilet :public AbstractMenu
{
public:
	ShowBilet();
	MenuId Show();
};

class AdminBilets :public AbstractMenu
{
public:
	AdminBilets();
	MenuId Show();
};
class AdminWeight :public AbstractMenu
{
public:
	AdminWeight();
	MenuId Show();
};
