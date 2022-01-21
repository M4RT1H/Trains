#pragma once
#include "List.h"
#include "Train.h"
#include"Registration.h"


extern list<PersonTrain> l1;
extern list<UtilityTrain> l2;
extern list<User> UserList;
extern list<bilet> bilets;
extern string FilePerson;
extern User* curUser;

void ShowPassenger();
void ShowUtility();
void Passenger();
void Utility();