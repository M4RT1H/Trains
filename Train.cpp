#include <iomanip>
#include<windows.h>
#include<iostream>
#include <conio.h>
#include "Train.h"
#include "List.h"
#include <string>
#include "Global.h"
#include "Functions.h"


using namespace std;

Train::Train()
{

}

Train::Train(const Train&)
{

}
void Train::SetId(int id)
{
	this->id = id;
}
void Train::SetTimeOut(tm time)
{
	this->timeOut = time;
}
void Train::SetTimeHome(tm time)
{
	this->timeHome = time;
}
void Train::SetFromLoc(string loc)
{
	strcpy_s(this->FromLoc, 30, loc.c_str());

}
void Train::SetToLoc(string loc)
{
	strcpy_s(this->ToLoc, 30, loc.c_str());

}

void UtilityTrain::GetTrain()
{
	float max = 0;
	int ID = -1;
	cout << "Рейс с самым большим перевозимым грузом: " << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < l2.length(); i++)
	{
		if (max < l2[i]->GetWeight())
		{
			max = l2[i]->GetWeight();
			ID = l2[i]->GetId();
		}
	}
	for (int i = 0; i < l2.length(); i++)
	{
		if (ID == l2[i]->GetId())
		{
			cout << *l2[i];
			cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
		
		}
	}

}


int Train::GetId()
{
	return this->id;
}
tm& Train::GetTimeOut()
{
	return this->timeOut;
}
tm& Train::GetTimeHome()
{
	return this->timeHome;
}
string Train::GetFromLoc()
{
	return this->FromLoc;
}
string Train::GetToLoc()
{
	return this->ToLoc;
}

PersonTrain::~PersonTrain()
{

}
//void PersonTrain::SetSeads(int seads)
//{
//	this->Seads = seads;
//}
void PersonTrain::SetPrice(float price)
{
	this->Price = price;
}
//int PersonTrain::GetSeads()
//{
//	return this->Seads;
//}
float PersonTrain::GetPrice()
{
	return this->Price;
}



float UtilityTrain::GetWeight()
{
	return this->Weight;
}
void UtilityTrain::SetWeight(float weight)
{
	this->Weight = weight;
}

void bilet::SetIdTrain(int idT)
{
	this->idTrain = idT;
}
void bilet::SetIdPerson(int idP)
{
	this->idPerson = idP;
}
int bilet::GetIdTrain()
{
	return this->idTrain;
}
int bilet::GetIdPerson()
{
	return this->idPerson;
}

int monthDays[13] = { 0, 31, 29, 31,30,31,30,31,31,30,31,30,31 };

istream& operator>>(istream& stream, tm& obj)
{
	cout << "    Дата:" << endl;
	while (true)
	{
		cout << "Месяц:" << endl;
		obj.tm_mon = integer(2);
		cout << endl;
		if (obj.tm_mon >= 1 && obj.tm_mon <= 12)
		{

			break;
		}
	}
	while (true)
	{
		cout << "День:" << endl;
		obj.tm_mday = integer(2);
		cout << endl;
		if (obj.tm_mday >= 1 && obj.tm_mday <= monthDays[obj.tm_mon])
		{

			break;
		}
	}
	cout << "       Время:" << endl;
	while (true)
	{
		cout << "Часы:" << endl;
		obj.tm_hour = integer(2);
		cout << endl;

		if (obj.tm_hour >= 0 && obj.tm_hour <= 23)
		{
			break;
		}
	}
	while (true)
	{
		cout << "Минуты:" << endl;
		obj.tm_min = integer(2);
		cout << endl;

		if (obj.tm_min >= 0 && obj.tm_min <= 59)
		{
			break;
		}
	}
	return stream;
}



string TimeToString(tm& obj)
{
	string str;
	str.append(to_string(obj.tm_mday));
	str.append(".");
	str.append(to_string(obj.tm_mon));
	str.append("/");
	str.append(to_string(obj.tm_hour));
	str.append(":");
	str.append(to_string(obj.tm_min));
	return str;
}

ostream& operator<<(ostream& stream, tm& obj)
{
	stream << obj.tm_mday << "." << setw(2) << obj.tm_mon << " / " << setw(2) << obj.tm_hour << ":" << setw(2) << obj.tm_min;
	return stream;
}
ostream& operator<<(ostream& stream, PersonTrain& obj)
{
	cout << "|" << setw(5) << obj.id << "|" << setw(20) << obj.FromLoc << "|" << setw(20) << obj.ToLoc << "|" << setw(13) << obj.timeHome << "|" << setw(14) << obj.timeOut << "|" << setw(16) << obj.Price << "|" << endl;
	return stream;
}

istream& operator>>(istream& stream, PersonTrain& obj)
{
	cout << " Место отправления:" << endl;
	obj.SetFromLoc(str(15));
	cout << endl;
	cout << " Место прибытия:" << endl;
	obj.SetToLoc(str(15));
	cout << endl;
	cout << "Время отбытия:" << endl;
	stream >> obj.timeHome;
	cout << endl;
	cout << "Время прибытия:" << endl;
	stream >> obj.timeOut;
	cout << endl;
	cout << "Цена билета:" << endl;
	obj.Price = flt(4);
	cout << endl;
	return stream;
}

istream& operator>>(istream& stream, UtilityTrain& obj)
{
	cout << " Место отправления:" << endl;
	obj.SetFromLoc(str(15));
	cout << endl;
	cout << " Место прибытия:" << endl;
	obj.SetToLoc(str(15));
	cout << endl;
	cout << "Время отбытия:" << endl;
	stream >> obj.timeHome;
	cout << endl;
	cout << "Время прибытия:" << endl;
	stream >> obj.timeOut;
	cout << endl;
	cout << "Вес груза:" << endl;
	obj.Weight = flt(4);
	cout << endl;
	return stream;
}
ostream& operator<<(ostream& stream, UtilityTrain& obj)
{
	cout << "|" << setw(5) << obj.id << "|" << setw(20) << obj.FromLoc << "|" << setw(20) << obj.ToLoc << "|" << setw(13) << obj.timeHome << "|" << setw(14) << obj.timeOut << "|" << setw(16) << obj.Weight << "|" << endl;
	return stream;
}


bool operator >=(const tm& tr1, const tm& tr2)
{
	if (tr1.tm_mon > tr2.tm_mon)
	{
		return true;
	}
	else
	{
		if (tr1.tm_mon == tr2.tm_mon)
		{
			if (tr1.tm_mday > tr2.tm_mday)
			{
				return true;
			}
			else
			{
				if (tr1.tm_mday == tr2.tm_mday)
				{
					if (tr1.tm_hour >= tr2.tm_hour)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
void User::SetId(int id)
{
	this->id = id;
}
int User::GetId()
{
	return this->id;
}
void User::SetLogin(string login)
{
	strcpy_s(this->login, 30, login.c_str());
}
string User::GetLogin()
{
	return this->login;
}
void User::SetPass(string pass)
{
	strcpy_s(this->password, 30, pass.c_str());
}
string User::GetPass()
{
	return this->password;
}
void User::SetAdmin(bool adm)
{
	this->admin = adm;
}
bool User::GetAdmin()
{
	return this->admin;
}