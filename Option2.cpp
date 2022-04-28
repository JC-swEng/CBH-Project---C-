#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Person.h"
#include "PersonFile.h"
#include "Vehicle.h"
#include "VehicleFile.h"

using namespace std;

Person SearchBySSN(const string & aString);
void DisplayPerson();
Vehicle VSearchBySSN(const string & aString);
void DisplayVehicle();
string UserWait();

void Option2()
{
	Person * pPerson = new Person;
	PersonFile * pPersonFile = new PersonFile;

	Vehicle * pVehicle = new Vehicle;
	VehicleFile * pVehicleFile = new VehicleFile;

	string inSSN;
   
	while(true)
        {
	system("clear");
	cout << "\t\t\t* * * Option 2: Search by SSN * * *" << endl << endl;
	cout << "\t\tEnter a Social Security Number (or Q to Quit): ";
	getline(cin, inSSN);
	cin.sync();

	if(inSSN[0] == 'q' || inSSN[0] == 'Q')
	 {
	   break;
	 }

	*pPerson = pPersonFile->SearchBySSN(inSSN);
	*pVehicle = pVehicleFile->VSearchBySSN(inSSN);

	if(!(pPerson->IsFound()))
	{
	   cout << endl << endl;
	   cout << "\t\tSocial Security Number was not found" << endl;
	   UserWait();
	   continue;
	 }

	if(pPerson->IsFound() && pVehicle->IsFound())
	 {
	   cout << endl << endl;
	   pPerson->DisplayPerson();
	   cout << endl << endl;
	   pVehicle->DisplayVehicle();
	   UserWait();
	 }

	if(pPerson->IsFound() && !(pVehicle->IsFound()))
	 {
	   cout << endl << endl;
	   pPerson->DisplayPerson();
	   cout << endl << endl << "\t\t No Vehicle";
	   UserWait();
	 }

        }

	delete pPerson;
	delete pPersonFile;

	delete pVehicle;
	delete pVehicleFile;

	return;
}
