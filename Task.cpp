#include "Task.h"
#include "Global.h"
#include "Train.h"
BuyBilet::BuyBilet()
{

}
MenuId BuyBilet::Show()
{
	system("cls");

	ShowPassenger();
	auto b = new bilet();

	cout << "�������� ����� �����:  ";
	int k = 0;
	int num = -1;
	k = integer(2);
	cout << endl;


	for (int i = 0; i < l1.length(); i++)
	{
		if (k == l1[i]->GetId())
		{
			b->SetIdTrain(l1[i]->GetId());
			b->SetIdPerson(curUser->GetId());
			num = 1;
			break;
		}
	}
	if (num == -1)
	{
		cout << "������ �� ������� " << endl;
		_getch();
		return Users;
	}


	system("cls");
	bilets.add(b);
	bilets.save();
	cout << "����� �������! " << endl;
	_getch();
	return Users;
}
ShowBilet::ShowBilet()
{

}
MenuId ShowBilet::Show()
{
	system("cls");
	cout << "���� ��������� ������:" << endl;
	cout << endl;
	Passenger();

	int flag = 0;
	float sum = 0;
	for (int j = 0; j < bilets.length(); j++)
	{
		if (bilets[j]->GetIdPerson() == curUser->GetId())
		{
			for (int i = 0; i < l1.length(); i++)
			{
				if (bilets[j]->GetIdTrain() == l1[i]->GetId())
				{
					cout << *l1[i];
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
					flag = 1;
					sum += l1[i]->GetPrice();
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << endl;
		cout << "� ��� ��� ������������� �������!" << endl;
	}
	else
	{
		cout << "�������� ����� �� ��� ������������� ������ = " << endl;
		cout << sum << endl;
	}
	_getch();
	return Users;
}

AdminBilets::AdminBilets()
{

}
MenuId AdminBilets::Show()
{
	system("cls");
	Passenger();

	float sum = 0;
	int flag = 0;
	
	for (int j = 0; j < bilets.length(); j++)
	{
		for (int i = 0; i < l1.length(); i++)
		{
			if (bilets[j]->GetIdTrain() == l1[i]->GetId())
			{
				cout << *l1[i];
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				flag = 1;
				sum += l1[i]->GetPrice();
			}
		}

	}
	if (flag == 0)
	{
		cout << endl;
		cout << "�� ���� ����� �� ��� ����������!" << endl;
		_getch();
	}

	cout << "�������� ����� �� ��� ������������� ������ = " << endl;
	cout << sum << endl;
	_getch();
	return TrainsMenu;
}
AdminWeight::AdminWeight()
{

}
MenuId AdminWeight::Show()
{
	system("cls");
	ShowUtility();

	float sum = 0;

	cout << "�������� ��� ����� �� ��� ��������� = " << endl;
	for (int i = 0; i < l2.length(); i++)
	{
		sum += l2[i]->GetWeight();
	}
	cout << sum << endl;
	_getch();
	return UtilityMenu;
}
