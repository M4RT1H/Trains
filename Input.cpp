#include "Input.h"
#include "Menu.h"
#include "Train.h"
#include "List.h"
#include "Global.h"
#include "Functions.h"
#include <string.h>


InputMenu::InputMenu()
{

}
MenuId InputMenu::Show()
{

	int max = 0;
	system("cls");
	auto t = new PersonTrain();

	cout << "     Введите данные:" << endl;

	cin >> *t;


	if (l1.length() < 1)
	{
		t->SetId(1);
	}
	else
	{
		for (int i = 0; i < l1.length(); i++)
		{
			if (l1[i]->GetId() > max)
			{
				max = l1[i]->GetId();
			}
		}
		t->SetId(max + 1);
	}



	l1.add(t);
	cout << endl;
	cout << "       Данные записаны" << endl;//TODO файл 
	l1.save();
	_getch();
	return TrainsMenu;
}


OutputMenu::OutputMenu()
{

}
MenuId OutputMenu::Show()
{
	ShowPassenger();

	_getch();
	if (curUser->GetAdmin() == true)
	{
		return FormatOutputPerson;
	}
	else
	{
		return Users;
	}
}

InputUtility::InputUtility()
{

}
MenuId InputUtility::Show()
{

	system("cls");
	int max = 0;
	auto t = new UtilityTrain();

	cout << "         Введите данные:" << endl;

	cin >> *t;

	if (l2.length() < 1)
	{
		t->SetId(1);
	}
	else
	{
		for (int i = 0; i < l2.length(); i++)
		{
			if (l2[i]->GetId() > max)
			{
				max = l2[i]->GetId();
			}
			t->SetId(max + 1);
		}
		t->SetId(max + 1);
	}
	l2.add(t);
	cout << endl;
	cout << "         Данные записаны" << endl;
	l2.save();
	_getch();
	return UtilityMenu;
}

OutputUtility::OutputUtility()
{

}
MenuId OutputUtility::Show()
{
	ShowUtility();
	cout << endl;
	UtilityTrain::GetTrain();
	_getch();
	return UtilityMenu;
}


SortPerson::SortPerson()
{

}
MenuId SortPerson::Show()
{
	system("cls");
	PersonTrain* t = NULL;


	while (true)
	{

		int count = 6;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "Место отправления:(А-Я) ";
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "Место прибытия:(А-Я) ";
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "Время отправления(0-23) ";
		menuItems[2].NextMenu = MenuId::Edit_3;

		menuItems[3].Name = "Время прибытия (0-23)";
		menuItems[3].NextMenu = MenuId::Edit_4;

		menuItems[4].Name = "Цена:(По возрастанию)  ";
		menuItems[4].NextMenu = MenuId::Edit_5;

		menuItems[5].Name = "Назад";
		menuItems[5].NextMenu = MenuId::Edit_6;


		Menu edit(menuItems, count);
		auto result = edit.Show();
		system("cls");

		if (result == Edit_1)
		{
			for (int i = 0; i < l1.length() - 1; i++)
			{
				for (int j = 0; j < l1.length() - i - 1; j++)
				{
					if (strCmpReg(l1[j]->GetFromLoc(), l1[j + 1]->GetFromLoc()) < 0)
					{
						l1.swap(j, j + 1);
					}
				}
			}
		}

		if (result == Edit_2)
		{
			for (int i = 0; i < l1.length() - 1; i++)
			{
				for (int j = 0; j < l1.length() - i - 1; j++)
				{
					if (strCmpReg(l1[j]->GetToLoc(), l1[j + 1]->GetToLoc()) < 0)
					{
						l1.swap(j, j + 1);
					}
				}
			}
		}
		if (result == Edit_3)
		{
			for (int i = 0; i < l1.length() - 1; i++)
			{
				for (int j = 0; j < l1.length() - i - 1; j++)
				{
					if (l1[j]->GetTimeHome() >= l1[j + 1]->GetTimeHome() == true)
					{
						l1.swap(j, j + 1);
					}
				}
			}

		}
		if (result == Edit_4)
		{
			for (int i = 0; i < l1.length() - 1; i++)
			{
				for (int j = 0; j < l1.length() - i - 1; j++)
				{
					if (l1[j]->GetTimeOut() >= l1[j + 1]->GetTimeOut())
					{
						l1.swap(j, j + 1);
					}
				}
			}
		}

		if (result == Edit_5)
		{
			for (int i = 0; i < l1.length() - 1; i++)
			{
				for (int j = 0; j < l1.length() - i - 1; j++)
				{
					if (l1[j]->GetPrice() > l1[j + 1]->GetPrice())
					{
						l1.swap(j, j + 1);
					}
				}
			}
		}

		if (result == Edit_6)
		{
			break;
		}
		cout << "Сортировка выполнена успешно";
		_getch();
	}

	//_getch();
	if (curUser->GetAdmin() == true)
	{
		return FormatOutputPerson;
	}
	else
	{
		return Users;
	}
}

SortUtility::SortUtility()
{

}
MenuId SortUtility::Show()
{
	system("cls");
	UtilityTrain* t = NULL;


	while (true)
	{

		int count = 6;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "Место отправления:(А-Я) ";
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "Место прибытия:(А-Я) ";
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "Время отправления(0-23) ";
		menuItems[2].NextMenu = MenuId::Edit_3;

		menuItems[3].Name = "Время прибытия (0-23)";
		menuItems[3].NextMenu = MenuId::Edit_4;

		menuItems[4].Name = "Вес груза:(По возрастанию)  ";
		menuItems[4].NextMenu = MenuId::Edit_5;

		menuItems[5].Name = "Назад";
		menuItems[5].NextMenu = MenuId::Edit_6;


		Menu edit(menuItems, count);
		auto result = edit.Show();
		system("cls");

		if (result == Edit_1)
		{
			for (int i = 0; i < l2.length() - 1; i++)
			{
				if (strCmpReg(l2[i]->GetFromLoc(), l2[i + 1]->GetFromLoc()) < 0)
				{
					l2.swap(i, i + 1);
				}
			}

		}

		if (result == Edit_2)
		{
			for (int i = 0; i < l2.length() - 1; i++)
			{
				if (strCmpReg(l2[i]->GetToLoc(), l2[i + 1]->GetToLoc()) < 0)
				{
					l2.swap(i, i + 1);
				}
			}
		}
		if (result == Edit_3)
		{
			for (int i = 0; i < l2.length() - 1; i++)
			{
				if (l2[i]->GetTimeHome() >= l2[i + 1]->GetTimeHome() == true)
				{
					l2.swap(i, i + 1);
				}
			}

		}
		if (result == Edit_4)
		{
			for (int i = 0; i < l2.length() - 1; i++)
			{
				if (l2[i]->GetTimeOut() >= l2[i + 1]->GetTimeOut())
				{
					l2.swap(i, i + 1);
				}
			}
		}

		if (result == Edit_5)
		{
			for (int i = 0; i < l1.length() - 1; i++)
			{
				if (l2[i]->GetWeight() > l2[i + 1]->GetWeight())
				{
					l2.swap(i, i + 1);
				}
			}
		}

		if (result == Edit_6)
		{
			break;
		}
		cout << "Сортировка выполнена успешно";
		_getch();
	}

	//_getch();
	return FormatOutputUtility;
}

FiltrPerson::FiltrPerson()
{

}

MenuId FiltrPerson::Show()
{
	system("cls");


	while (true)
	{

		int count = 6;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "Место отправления: ";
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "Место прибытия: ";
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "Время отправления:";
		menuItems[2].NextMenu = MenuId::Edit_3;

		menuItems[3].Name = "Время прибытия:";
		menuItems[3].NextMenu = MenuId::Edit_4;

		menuItems[4].Name = "Цена: ";
		menuItems[4].NextMenu = MenuId::Edit_5;

		menuItems[5].Name = "Назад";
		menuItems[5].NextMenu = MenuId::Edit_6;


		Menu edit(menuItems, count);
		auto result = edit.Show();
		system("cls");

		if (result == Edit_1)
		{
			cout << "Введите место отправления:" << endl;
			string Home;
			Home = str(15);
			int flag = 0;
			system("cls");


			Passenger();
			for (int i = 0; i < l1.length(); i++)
			{
				if (strstr(l1[i]->GetFromLoc().c_str(), Home.c_str()) != NULL)
				{
					cout << *l1[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;

			}
			_getch();
		}

		if (result == Edit_2)
		{
			cout << "Введите место прибытия:" << endl;
			string Out;
			Out = str(15);
			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l1.length(); i++)
			{
				if (strstr(l1[i]->GetToLoc().c_str(), Out.c_str()) != NULL)
				{
					cout << *l1[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}
		if (result == Edit_3)
		{

			cout << "Введите от и до какого времени(отправления) необходимо отфильтровать:" << endl;
			tm time1;
			tm time2;

			cout << "От:" << endl;
			cout << "> ";
			cin >> time1;
			cout << "До:" << endl;
			cout << "> ";
			cin >> time2;

			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l1.length(); i++)
			{
				if (l1[i]->GetTimeHome() >= time1 && time2 >= l1[i]->GetTimeHome())
				{
					cout << *l1[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}
		if (result == Edit_4)
		{
			cout << "Введите от и до какого времени(прибытия) необходимо отфильтровать:" << endl;
			tm time3;
			tm time4;

			cout << "От:" << endl;
			cout << "> ";
			cin >> time3;
			cout << "До:" << endl;
			cout << "> ";
			cin >> time4;

			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l1.length(); i++)
			{
				if (l1[i]->GetTimeOut() >= time3 && time4 >= l1[i]->GetTimeOut())
				{
					cout << *l1[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}

		if (result == Edit_5)
		{
			cout << "Введите от и до какой цены необходимо отфильтровать:" << endl;
			float price1;
			float price2;

			cout << "От:" << endl;
			cout << "> ";
			cin >> price1;
			cout << "До:" << endl;
			cout << "> ";
			cin >> price2;

			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l1.length(); i++)
			{
				if (l1[i]->GetPrice() >= price1 && price2 >= l1[i]->GetPrice())
				{
					cout << *l1[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}

		if (result == Edit_6)
		{
			break;
		}

	}

	//_getch();
	if (curUser->GetAdmin() == true)
	{
		return FormatOutputPerson;
	}
	else
	{
		return Users;
	}
}
FiltrUtility::FiltrUtility()
{

}

MenuId FiltrUtility::Show()
{
	system("cls");


	while (true)
	{

		int count = 6;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "Место отправления: ";
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "Место прибытия: ";
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "Время отправления:";
		menuItems[2].NextMenu = MenuId::Edit_3;

		menuItems[3].Name = "Время прибытия:";
		menuItems[3].NextMenu = MenuId::Edit_4;

		menuItems[4].Name = "Вес груза: ";
		menuItems[4].NextMenu = MenuId::Edit_5;

		menuItems[5].Name = "Назад";
		menuItems[5].NextMenu = MenuId::Edit_6;


		Menu edit(menuItems, count);
		auto result = edit.Show();
		system("cls");

		if (result == Edit_1)
		{
			cout << "Введите место отправления:" << endl;
			string Home;
			Home = str(15);
			int flag = 0;
			system("cls");


			Passenger();
			for (int i = 0; i < l2.length(); i++)
			{
				if (strstr(l2[i]->GetFromLoc().c_str(), Home.c_str()) != NULL)
				{
					cout << *l2[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;

			}
			_getch();
		}

		if (result == Edit_2)
		{
			cout << "Введите место прибытия:" << endl;
			string Out;
			Out = str(15);
			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l2.length(); i++)
			{
				if (strstr(l2[i]->GetToLoc().c_str(), Out.c_str()) != NULL)
				{
					cout << *l2[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}
		if (result == Edit_3)
		{

			cout << "Введите от и до какого времени(отправления) необходимо отфильтровать:" << endl;
			tm time1;
			tm time2;

			cout << "От:" << endl;
			cout << "> ";
			cin >> time1;
			cout << "До:" << endl;
			cout << "> ";
			cin >> time2;

			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l2.length(); i++)
			{
				if (l2[i]->GetTimeHome() >= time1 && time2 >= l2[i]->GetTimeHome())
				{
					cout << *l2[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}
		if (result == Edit_4)
		{
			cout << "Введите от и до какого времени(прибытия) необходимо отфильтровать:" << endl;
			tm time3;
			tm time4;

			cout << "От:" << endl;
			cout << "> ";
			cin >> time3;
			cout << "До:" << endl;
			cout << "> ";
			cin >> time4;

			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l2.length(); i++)
			{
				if (l2[i]->GetTimeOut() >= time3 && time4 >= l2[i]->GetTimeOut())
				{
					cout << *l2[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}

		if (result == Edit_5)
		{
			cout << "Введите от и до какого веса груза необходимо отфильтровать:" << endl;
			float price1;
			float price2;

			cout << "От:" << endl;
			cout << "> ";
			cin >> price1;
			cout << "До:" << endl;
			cout << "> ";
			cin >> price2;

			int flag = 0;
			system("cls");
			Passenger();
			for (int i = 0; i < l2.length(); i++)
			{
				if (l2[i]->GetWeight() >= price1 && price2 >= l2[i]->GetWeight())
				{
					cout << *l2[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
				}
			}

			if (flag == 0)
			{
				cout << endl;
				cout << "Ничего не найдено!" << endl;
			}
			_getch();
		}

		if (result == Edit_6)
		{
			break;
		}

	}

	//_getch();
	return FormatOutputUtility;
}