#include "Global.h"

list<PersonTrain> l1("d:\\PersonTrain.bin");
list<UtilityTrain> l2("d:\\UtilityTrain.bin");
list<User> UserList("d:\\UserList.bin");
list<bilet> bilets("d:\\bilet.bin");

User* curUser;

void Passenger()
{
	cout << "=====================================================================================================================" << endl;
	cout << "|" << setw(6) << " |" << setw(21) << "|" << setw(21) << "|" << setw(25) << "|" << setw(26) << "|" << setw(17) << "|" << endl;
	cout << "| ID  " << "| ����� �����������  " << "|   ����� ��������   |" << " ����/����� ����������� |" << "   ����/����� ��������   |" << "  ���� ������   |" << endl;
	cout << "|" << setw(6) << " |" << setw(21) << "|" << setw(21) << "|" << setw(25) << "|" << setw(26) << "|" << setw(17) << "|" << endl;
	cout << "=====================================================================================================================" << endl;
}
void ShowPassenger()
{
	system("cls");
	Passenger();
	for (int i = 0; i < l1.length(); i++)
	{
		auto item = l1[i];
		cout /*<< "|" << setw(5) << i + 1 << "|"*/ << *item;
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	}
}
void Utility()
{
	cout << "=====================================================================================================================" << endl;
	cout << "|" << setw(6) << " |" << setw(21) << "|" << setw(21) << "|" << setw(25) << "|" << setw(26) << "|" << setw(17) << "|" << endl;
	cout << "| ID  " << "| ����� �����������  " << "|   ����� ��������   |" << " ����/����� ����������� |" << "   ����/����� ��������   |" << "    ��� �����   |" << endl;
	cout << "|" << setw(6) << " |" << setw(21) << "|" << setw(21) << "|" << setw(25) << "|" << setw(26) << "|" << setw(17) << "|" << endl;
	cout << "=====================================================================================================================" << endl;
}
void ShowUtility()
{

	system("cls");
	Utility();
	for (int i = 0; i < l2.length(); i++)
	{
		auto item = l2[i];
		cout /*<< "|" << setw(5) << i + 1 << "|" */ << *item;
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	}
}