#include "Delete.h"
#include "Train.h"
#include "Input.h"

DeletePerson::DeletePerson()
{

}
MenuId DeletePerson::Show()
{
	system("cls");

	
	if (l1.length() == 0)
	{
		cout << "���������� �������.����������� ������" << endl;
		_getch();
		return TrainsMenu;
	}

	ShowPassenger();

	cout << endl;
	cout << "�������� ������ ������� ������ �������:";

	int k = 0;
	k=integer(2);

	PersonTrain* t = NULL;
	for (int i = 0; i < l1.length(); i++)
	{
		
		if (k == l1[i]->GetId())
		{
			for (int j = 0; j < bilets.length(); j++)
			{
				if (bilets[j]->GetIdTrain() == l1[i]->GetId())
				{
					cout << endl;
					cout << "�� �� ������ ������� ������ ����.�� ���� �������� ������!" << endl;
					_getch();
					
				}
				else
				{
					t = l1[i];
					/*delete t;*/
					l1.del(i);
					system("cls");
					cout << "������ �������!" << endl;
					l1.save();
					_getch();
				}
				return TrainsMenu;
			}
		}

	}
	if (!t)
	{
		cout << "������ �� ������� " << endl;
		return TrainsMenu;
	}
	return TrainsMenu;
	
}
DeleteUtility::DeleteUtility()
{

}
MenuId DeleteUtility::Show()
{
	system("cls");


	if (l2.length() == 0)
	{
		cout << "���������� �������.����������� ������" << endl;
		_getch();
		return UtilityMenu;
	}

	ShowUtility();

	cout << endl;
	cout << "�������� ������ ������� ������ �������:";

	int k = 0;
	k=integer(2);

	UtilityTrain* t = NULL;
	for (int i = 0; i < l2.length(); i++)
	{
		if (k == l2[i]->GetId())
		{
			t = l2[i];
			/*delete t;*/
			l2.del(i);
			system("cls");
			cout << "������ �������!" << endl;
			l2.save();
			_getch();
			return UtilityMenu;
		}

	}
	if (!t)
	{
		cout << "������ �� ������� " << endl;
		_getch();
		return UtilityMenu;
	}
	return UtilityMenu;
}