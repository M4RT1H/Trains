#pragma once

#include <iomanip>
#include<windows.h>
#include<iostream>
#include <conio.h>


using namespace std;

class Train
{
protected:

	int id;
	char FromLoc[30];
	char ToLoc[30];
	tm timeOut;
	tm timeHome;


public:

	Train();
	Train(const Train&);

	void SetId(int);
	void SetTimeOut(tm);
	void SetTimeHome(tm);
	void SetFromLoc(string);
	void SetToLoc(string);

	int GetId();
	tm& GetTimeOut();
	tm& GetTimeHome();
	string GetFromLoc();
	string GetToLoc();

	

};
string TimeToString(tm& time);
ostream& operator<<(ostream& stream, tm& obj);
istream& operator>>(istream& stream, tm& obj);
bool operator>=(const tm& tr1,const tm& tr2);

class PersonTrain :public Train
{
private:

	//int Seads;
	float Price;
	//bool Service;

public:
	//void SetSeads(int);
	void SetPrice(float);
	float GetPrice();

	friend ostream& operator<<(ostream& stream, PersonTrain& obj);
	friend istream& operator>>(istream& stream, PersonTrain& obj);
	~PersonTrain();

};

class UtilityTrain :public Train
{
private:
	int Type;
	float Weight;
public:
	void SetWeight(float);
	float GetWeight();
	friend ostream& operator<<(ostream& stream, UtilityTrain& obj);
	friend istream& operator>>(istream& stream, UtilityTrain& obj);

	static void GetTrain();

};

class bilet
{
private:
	int idTrain;
	int idPerson;
public:

	void SetIdTrain(int);
	void SetIdPerson(int);
	int GetIdTrain();
	int GetIdPerson();
};

class User
{
private:
	int id;
	char login[30];
	char password[30];
	bool admin;
public:
	void SetId(int);
	int GetId();
	void SetLogin(string);
	string GetLogin();
	void SetPass(string);
	string GetPass();
	void SetAdmin(bool);
	bool GetAdmin();
	
};

int integer(int len);