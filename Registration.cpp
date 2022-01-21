#include "Registration.h"
#include "Train.h"
#include "Global.h"
#include"Functions.h"

Registr::Registr()
{

}

MenuId Registr::Show()
{
	system("cls");
	int max = 0;
	auto Person = new User();
	while (true)
	{
		cout << "Введите логин" << endl;
		cout << ">";
		string log;
		log = login(16, false);
		cout << endl;
		bool exists = false;

		for (int i = 0; i < UserList.length(); i++)
		{
			if (UserList[i]->GetLogin() == log)
			{
				exists = true;
				break;
			}
		}
		if (exists)
		{
			cout << "Такой логин уже существует" << endl;
			_getch();
		}
		else
		{
			Person->SetLogin(log);
			break;
		}
	}
	while (true)
	{
		string pass1;
		cout << "Введите пароль" << endl;
		cout << ">";
		pass1 = login(16, true);
		cout << endl;

		string pass2;
		cout << "Повторите пароль" << endl;
		cout << ">";
		pass2 = login(16, true);
		cout << endl;

		if (pass1 != pass2)
		{
			cout << "Пароли не совпадают" << endl;
			cout << "Повторите ввод" << endl;

		}
		else
		{
			Person->SetPass(pass1);
			break;
		}
	}
	if (UserList.length() == 0)
	{
		Person->SetAdmin(true);
	}

	if (UserList.length() < 1)
	{
		Person->SetId(1);
	}
	else
	{
		for (int i = 0; i < UserList.length(); i++)
		{
			if (UserList[i]->GetId() > max)
			{
				max = UserList[i]->GetId();
			}
		}
		Person->SetId(max + 1);
	}

	UserList.add(Person);
	UserList.save();
	system("cls");
	cout << "Регистрация прошла успешно" << endl;
	_getch();
	return MainMenu;

}
Login::Login()
{

}
MenuId Login::Show()
{
	system("cls");

	cout << "Введите логин" << endl;
	string Login;
	Login = login(16, false);
	cout << endl;
	cout << "Введите пароль" << endl;
	string passw;
	passw = login(16, true);
	cout << endl;

	int flag = 0;
	system("cls");
	if (UserList.length() == 0)
	{
		cout << "Error" << endl;
		_getch();
		return MainMenu;
	}
	for (int i = 0; i < UserList.length(); i++)
	{
		if (Login == UserList[i]->GetLogin() && passw == UserList[i]->GetPass())
		{
			curUser = UserList[i];
			if (UserList[i]->GetAdmin() == true)
			{
				cout << "Вы зашли как администратор!" << endl;
				_getch();
				return Admin;
			}
			else
			{
				cout << "Вы зашли как пользователь!" << endl;
				_getch();
				return Users;
			}

			flag = 1;
		}

	}
	if (flag == 0)
	{
		cout << "Неверный логин и/или пароль" << endl;
		_getch();
		return MainMenu;
	}
	return MainMenu;
}
OutputUsers::OutputUsers()
{

}
MenuId OutputUsers::Show()
{
	system("cls");
	cout << "==============================================" << endl;
	cout << "|  ID  " << "|  Имя пользователя  " << "|     Доступ     |" << endl;
	cout << "==============================================" << endl;

	for (int i = 0; i < UserList.length(); i++)
	{
		cout << "|" << setw(6) << UserList[i]->GetId() << "|" << setw(20) << UserList[i]->GetLogin() << "|" << setw(17);
		if (UserList[i]->GetAdmin() == true)
		{
			cout << "Администратор |" << endl;
		}
		else
		{
			cout << "Пользователь |" << endl;
		}
		cout << "----------------------------------------------" << endl;
	}

	cout << endl;
	cout << "Выберите пользователя:";

	int k = 0;
	int num = -1;
	k = integer(2);


	for (int i = 0; i <= UserList.length(); i++)
	{

		if (k == UserList[i]->GetId())
		{
			num = i;
			break;
		}

	}
	if (num == -1)
	{
		cout << "Пользователь не найден " << endl;
		return TrainsMenu;
	}

	while (true)
	{

		int count = 3;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "Удалить пользователя:";
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "Изменить права ";
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "Назад";
		menuItems[2].NextMenu = MenuId::Edit_3;

		Menu edit(menuItems, count);
		auto result = edit.Show();

		system("cls");

		if (result == Edit_1)
		{
			if (strcmp(curUser->GetLogin().c_str(), UserList[num]->GetLogin().c_str()) == 0)
			{
				cout << "Вы не можете удалить себя!" << endl;
				_getch();

			}
			else
			{
				for (int i = 0; i < bilets.length(); i++)
				{
					if (UserList[num]->GetId() == bilets[i]->GetIdPerson())
					{
						cout << "Вы не можете удалить этого пользователя.Он заказал билет!";
						_getch();
						break;
					}
					else
					{
						UserList.del(num);

						cout << "Пользователь удален!" << endl;
						_getch();
						break;

					}
				}
			}
		}
		if (result == Edit_2)
		{
			if (strcmp(curUser->GetLogin().c_str(), UserList[num]->GetLogin().c_str()) == 0)
			{
				cout << "Вы не можете изменить свои права!" << endl;
				_getch();

			}
			else
			{
				UserList[num]->SetAdmin(!UserList[num]->GetAdmin());
				cout << "Права изменены!" << endl;
				_getch();
			}
		}
		if (result == Edit_3)
		{
			break;
		}
		return Admin;

		UserList.save();
		return Admin;
	}
	return Admin;
}