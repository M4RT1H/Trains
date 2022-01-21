#include "Change.h"
#include"Menu.h"
#include "Input.h"
#include "Train.h"
#include <iomanip>
#include "Functions.h"


ChangePerson::ChangePerson()
{

}
MenuId ChangePerson::Show()
{
	system("cls");

	if (l1.length() == 0)
	{
		cout << "���������� ��������.����������� ������" << endl;
		_getch();
		return TrainsMenu;
	}

	ShowPassenger();

	cout << endl;
	cout << "�������� ������ ������� ������ ��������:";

	int k = 0;
	k = integer(2);

	PersonTrain* t = NULL;
	for (int i = 0; i < l1.length(); i++)
	{

		if (k == l1[i]->GetId())
		{
			t = l1[i];
			break;
		}

	}
	if (!t)
	{
		cout << "������ �� ������� " << endl;
		return TrainsMenu;
	}

	while (true)
	{

		int count = 6;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "����� �����������: " + t->GetFromLoc();
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "����� ��������: " + t->GetToLoc();
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "����� ����������� " + TimeToString(t->GetTimeHome());
		menuItems[2].NextMenu = MenuId::Edit_3;

		menuItems[3].Name = "����� �������� " + TimeToString(t->GetTimeOut());
		menuItems[3].NextMenu = MenuId::Edit_4;

		menuItems[4].Name = "����: " + to_string(t->GetPrice());
		menuItems[4].NextMenu = MenuId::Edit_5;

		menuItems[5].Name = "�����";
		menuItems[5].NextMenu = MenuId::Edit_6;

		Menu edit(menuItems, count);
		auto result = edit.Show();
		system("cls");

		if (result == Edit_1)
		{
			cout << "����� �����������: ";
			string v;
			v = str(15);
			t->SetFromLoc(v);
		}

		if (result == Edit_2)
		{
			cout << "����� ��������:";
			string v;
			v = str(15);
			t->SetToLoc(v);
		}
		if (result == Edit_3)
		{
			tm v;
			cout << "����� �����������: ";
			cin >> v;
			t->SetTimeHome(v);
		}
		if (result == Edit_4)
		{
			cout << "����� ��������: ";
			tm v;
			cin >> v;
			t->SetTimeOut(v);
		}

		if (result == Edit_5)
		{
			cout << "����: ";
			float price;
			price = flt(4);
			t->SetPrice(price);
		}

		if (result == Edit_6)
		{
			break;
		}
	}

	l1.save();
	return TrainsMenu;
}

ChangeUtility::ChangeUtility()
{

}

MenuId ChangeUtility::Show()
{
	system("cls");

	if (l2.length() == 0)
	{
		cout << "���������� ��������.����������� ������" << endl;
		_getch();
		return UtilityMenu;
	}

	ShowUtility();

	cout << endl;
	cout << "�������� ������ ������� ������ ��������:";

	int k = 0;
	k = integer(2);

	UtilityTrain* t = NULL;
	for (int i = 0; i < l2.length(); i++)
	{

		if (k == l2[i]->GetId())
		{
			t = l2[i];
			break;
		}

	}
	if (!t)
	{
		cout << "������ �� ������� " << endl;
		_getch();
		return UtilityMenu;
	}

	while (true)
	{

		int count = 6;
		MenuItem* menuItems = new MenuItem[count];

		menuItems[0].Name = "����� �����������: " + t->GetFromLoc();
		menuItems[0].NextMenu = MenuId::Edit_1;

		menuItems[1].Name = "����� ��������: " + t->GetToLoc();
		menuItems[1].NextMenu = MenuId::Edit_2;

		menuItems[2].Name = "����� ����������� " + TimeToString(t->GetTimeHome());
		menuItems[2].NextMenu = MenuId::Edit_3;

		menuItems[3].Name = "����� �������� " + TimeToString(t->GetTimeOut());
		menuItems[3].NextMenu = MenuId::Edit_4;

		menuItems[4].Name = "��� �����: " + to_string(t->GetWeight());
		menuItems[4].NextMenu = MenuId::Edit_5;

		menuItems[5].Name = "�����";
		menuItems[5].NextMenu = MenuId::Edit_6;

		Menu edit(menuItems, count);
		auto result = edit.Show();
		system("cls");

		if (result == Edit_1)
		{
			cout << "����� �����������: ";
			string v;
			v = str(15);
			t->SetFromLoc(v);
		}

		if (result == Edit_2)
		{
			cout << "����� ��������:";
			string v;
			v = str(15);
			t->SetToLoc(v);
		}
		if (result == Edit_3)
		{
			tm v;
			cout << "����� �����������: ";
			cin >> v;
			t->SetTimeHome(v);
		}
		if (result == Edit_4)
		{
			cout << "����� ��������: ";
			tm v;
			cin >> v;
			t->SetTimeOut(v);
		}

		if (result == Edit_5)
		{
			cout << "��� �����: ";
			float weight;
			weight = flt(4);
			t->SetWeight(weight);
		}

		if (result == Edit_6)
		{
			break;
		}
	}
	l2.save();
	//_getch();
	return UtilityMenu;
}