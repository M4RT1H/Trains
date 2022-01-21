#pragma once
#include <string>
#include "Console.h"
#include <iostream>
#include <conio.h>

using namespace std;

enum Action { up, down, left, right, enter, esc, null, space, del, f3 };

enum MenuId { ExitMenu, MainMenu, LoginMenu, TrainsMenu, InputPassenger, OutputPassenger, Registration,
	UtilityMenu, UtitlityInput, UtitlityOutput, ChangePassenger, UtilityChange, PersonDelete, UtilityDelete, FormatOutputPerson, FormatOutputUtility,
	SortingPerson, SortingUtility, FilteredPerson, FilteredUtility, Admin, Users, UsersOutPut, TaskBilet, OutPutBilet, ReportPerson, ReportUtility,
	Edit_1, Edit_2, Edit_3, Edit_4, Edit_5, Edit_6
};

class  AbstractMenu
{
public:virtual MenuId Show() = 0;
};

struct MenuItem
{
	string Name;
	MenuId NextMenu = MenuId::ExitMenu;
};

class Menu :AbstractMenu
{
private:
	MenuItem* items = NULL;
	int count;
	int selection;
	string title;

public:
	Menu()
	{

	}
	Menu(MenuItem* items, int count) :Menu(items, count, "")
	{

	}
	Menu(MenuItem* items, int count, string title)
	{
		this->items = items;
		this->count = count;
		this->title = title;
	}


	MenuId Show()
	{
		system("cls");

		Console::Cursor(false);

		this->selection = 0;
		if (this->title.length() != 0)
		{
			cout << title << endl;
		}

		for (int i = 0; i < this->count; i++)
		{
			if (i == 0)
			{
				cout << "> ";
			}
			else {
				cout << "  ";
			}

			cout << this->items[i].Name << endl;
		}


		while (true)
		{
			Action action = this->GetAction();

			if (action == Action::down)
			{
				this->selection++;
				if (this->selection == this->count)
				{
					this->selection = 0;
				}
			}

			if (action == Action::up)
			{
				this->selection--;
				if (this->selection < 0)
				{
					this->selection = this->count - 1;
				}
			}

			if (action == Action::enter)
			{
				return this->items[this->selection].NextMenu;
			}

			this->ClearSelection();

			this->SetSelection();
		}

	}

private:
	void ClearSelection()
	{
		int offset = 0;
		if (this->title.length() != 0)
		{
			offset = 1;
		}

		for (int i = 0; i < this->count; i++)
		{
			Console::SetCursorPosition(0, i + offset);
			cout << " ";
		}
	}

	void SetSelection()
	{
		int offset = 0;
		if (this->title.length() != 0)
		{
			offset = 1;
		}

		Console::SetCursorPosition(0, this->selection + offset);
		cout << ">";

	}

	Action GetAction()
	{
		int sc, sc_c;
		while (true)
		{
			sc = _getch();
			if (sc == 224 || sc == 0)
			{
				sc_c = _getch();
			}
			else
			{
				sc_c = NULL;
			}

			fflush(stdin);

			if (sc_c == 72 && sc == 224)
				return Action::up;
			if (sc_c == 80 && sc == 224)
				return Action::down;
			if (sc_c == 75 && sc == 224)
				return Action::left;
			if (sc_c == 77 && sc == 224)
				return Action::right;
			if (sc_c == 83 && sc == 224)
				return Action::del;
			if (sc == 13)
				return Action::enter;
			if (sc == 27)
				return Action::esc;
			if (sc == 32)
				return Action::space;
			if (sc == 0 && sc_c == 61)
				return Action::f3;
		}
	}

public:
	~Menu()
	{
		if (this->items)
		{
			delete[] this->items;
		}
	}
};

