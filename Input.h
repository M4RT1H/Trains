#pragma once
#include "Menu.h"
#include "Train.h"
#include "List.h"
#include "Global.h"

class InputMenu :public AbstractMenu
{
private:

public:
	InputMenu();
	MenuId Show();
};

class OutputMenu :public AbstractMenu
{
public:
	OutputMenu();
	MenuId Show();
};

class InputUtility :public AbstractMenu
{
public:
	InputUtility();
	MenuId Show();
};
class OutputUtility : public AbstractMenu
{
public:
	OutputUtility();
	MenuId Show();
};

class SortPerson :public AbstractMenu
{
public:
	SortPerson();
	MenuId Show();
};

class SortUtility :public AbstractMenu
{
public:
	SortUtility();
	MenuId Show();
};

class FiltrPerson :public AbstractMenu
{
public:
	FiltrPerson();
	MenuId Show();
};
class FiltrUtility :public AbstractMenu
{
public:
	FiltrUtility();
	MenuId Show();
};