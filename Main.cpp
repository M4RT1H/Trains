#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "Input.h"
#include "Change.h"
#include"Registration.h"
#include "Delete.h"
#include "List.h"
#include "Task.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>cls");

	l1.load();
	l2.load();
	UserList.load();
	bilets.load();

	AbstractMenu* menu = NULL;
	MenuId menuId = MenuId::MainMenu;
	while (true)
	{
		if (menu)
		{
			delete menu;
		}

		if (menuId == MenuId::MainMenu)
		{
			int count = 3;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Войти в систему";
			menuItems[0].NextMenu = MenuId::LoginMenu;

			menuItems[1].Name = "Регистрация";
			menuItems[1].NextMenu = MenuId::Registration;

			menuItems[2].Name = "Выход";
			menuItems[2].NextMenu = MenuId::ExitMenu;

			menu = (AbstractMenu*)new Menu(menuItems, count);
		}
		if (menuId == MenuId::Registration)
		{
			menu = new Registr();

		}
		if (menuId == MenuId::LoginMenu)
		{
			menu = new Login();
		}
		if (menuId == MenuId::Users)
		{
			int count = 6;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Просмотр рейсов";
			menuItems[0].NextMenu = MenuId::OutputPassenger;

			menuItems[1].Name = "Фильтрация рейсов";
			menuItems[1].NextMenu = MenuId::FilteredPerson;

			menuItems[2].Name = "Сортировка рейсов";
			menuItems[2].NextMenu = MenuId::SortingPerson;

			menuItems[3].Name = "Покупка билета";
			menuItems[3].NextMenu = MenuId::TaskBilet;

			menuItems[4].Name = "Список Ваших приобретенных билетов";
			menuItems[4].NextMenu = MenuId::OutPutBilet;

			menuItems[5].Name = "Назад";
			menuItems[5].NextMenu = MenuId::MainMenu;

			menu = (AbstractMenu*) new Menu(menuItems, count, "Выберите:");
		}
		if (menuId == MenuId::Admin)
		{
			int count = 4;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Пассажирский";
			menuItems[0].NextMenu = MenuId::TrainsMenu;

			menuItems[1].Name = "Грузовой";
			menuItems[1].NextMenu = MenuId::UtilityMenu;

			menuItems[2].Name = "Список пользователей";
			menuItems[2].NextMenu = MenuId::UsersOutPut;

			menuItems[3].Name = "Назад";
			menuItems[3].NextMenu = MenuId::MainMenu;

			menu = (AbstractMenu*) new Menu(menuItems, count, "Выберите:");
		}
		if (menuId == MenuId::UtilityMenu)
		{
			int count = 6;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Ввод";
			menuItems[0].NextMenu = MenuId::UtitlityInput;

			menuItems[1].Name = "Редактирование";
			menuItems[1].NextMenu = MenuId::UtilityChange;

			menuItems[2].Name = "Форматированный вывод";
			menuItems[2].NextMenu = MenuId::FormatOutputUtility;

			menuItems[3].Name = "Удаление ";
			menuItems[3].NextMenu = MenuId::UtilityDelete;

			menuItems[4].Name = "Отчет: ";
			menuItems[4].NextMenu = MenuId::ReportUtility;

			menuItems[5].Name = "Назад ";
			menuItems[5].NextMenu = MenuId::Admin;

			menu = (AbstractMenu*)new Menu(menuItems, count, "Выберите:");
		}
		if (menuId == MenuId::TrainsMenu)
		{
			int count = 6;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Ввод";
			menuItems[0].NextMenu = MenuId::InputPassenger;

			menuItems[1].Name = "Редактирование";
			menuItems[1].NextMenu = MenuId::ChangePassenger;

			menuItems[2].Name = "Форматированный вывод";
			menuItems[2].NextMenu = MenuId::FormatOutputPerson;

			menuItems[3].Name = "Удаление ";
			menuItems[3].NextMenu = MenuId::PersonDelete;

			menuItems[4].Name = "Отчет: ";
			menuItems[4].NextMenu = MenuId::ReportPerson;

			menuItems[5].Name = "Назад ";
			menuItems[5].NextMenu = MenuId::Admin;

			menu = (AbstractMenu*)new Menu(menuItems, count, "Выберите:");
		}
		if (menuId == MenuId::FormatOutputPerson)
		{
			int count = 4;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Сортировка";
			menuItems[0].NextMenu = MenuId::SortingPerson;

			menuItems[1].Name = "Фильтрация";
			menuItems[1].NextMenu = MenuId::FilteredPerson;

			menuItems[2].Name = "Вывод";
			menuItems[2].NextMenu = MenuId::OutputPassenger;

			menuItems[3].Name = "Назад";
			menuItems[3].NextMenu = MenuId::TrainsMenu;

			menu = (AbstractMenu*)new Menu(menuItems, count, "Выберите:");
		}
		if (menuId == MenuId::FormatOutputUtility)
		{
			int count = 4;
			MenuItem* menuItems = new MenuItem[count];

			menuItems[0].Name = "Сортировка";
			menuItems[0].NextMenu = MenuId::SortingUtility;

			menuItems[1].Name = "Фильтрация";
			menuItems[1].NextMenu = MenuId::FilteredUtility;

			menuItems[2].Name = "Вывод";
			menuItems[2].NextMenu = MenuId::UtitlityOutput;

			menuItems[3].Name = "Назад";
			menuItems[3].NextMenu = MenuId::UtilityMenu;

			menu = (AbstractMenu*)new Menu(menuItems, count, "Выберите:");
		}

		if (menuId == MenuId::OutputPassenger)
		{
			menu = new OutputMenu();
		}
		if (menuId == MenuId::InputPassenger)
		{
			menu = new InputMenu();
		}

		if (menuId == MenuId::ChangePassenger)
		{
			menu = new ChangePerson();
		}
		if (menuId == MenuId::UtilityChange)
		{
			menu = new ChangeUtility();
		}

		if (menuId == MenuId::UtitlityOutput)
		{
			menu = new OutputUtility();
		}
		if (menuId == MenuId::UtitlityInput)
		{
			menu = new InputUtility();
		}

		if (menuId == MenuId::PersonDelete)
		{
			menu = new  DeletePerson();
		}
		if (menuId == MenuId::UtilityDelete)
		{
			menu = new DeleteUtility();
		}

		if (menuId == MenuId::SortingPerson)
		{
			menu = new SortPerson();
		}
		if (menuId == MenuId::SortingUtility)
		{
			menu = new SortUtility();
		}
		if (menuId == MenuId::ExitMenu)
		{
			break;
		}

		if (menuId == MenuId::FilteredPerson)
		{
			menu = new FiltrPerson();
		}
		if (menuId == MenuId::FilteredUtility)
		{
			menu = new FiltrUtility();
		}

		if (menuId == MenuId::UsersOutPut)
		{
			menu = new OutputUsers();
		}

		if (menuId == MenuId::TaskBilet)
		{
			menu = new BuyBilet();
		}

		if (menuId == MenuId::OutPutBilet)
		{
			menu = new ShowBilet();
		}

		if (menuId == MenuId::ReportPerson)
		{
			menu = new AdminBilets();
		}
		if (menuId == MenuId::ReportUtility)
		{
			menu = new AdminWeight();
		}

		if (menu)
		{
			menuId = menu->Show();
		}
	}
}