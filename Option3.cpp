#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Person.h"
#include "PersonFile.h"
#include "Vehicle.h"
#include "VehicleFile.h"

using namespace std;

Person SearchByOLN(const string & aString);
void DisplayPerson();
Vehicle VSearchBySSN(const string & aString);
void DisplayVehicle();
string UserWait();

void Option3()
{
	Person * pPerson = new Person;
	PersonFile * pPersonFile = new PersonFile;

	Vehicle * pVehicle = new Vehicle;
	VehicleFile * pVehicleFile = new VehicleFile;

	string inOLN;
	string inSSN;
   
	while(true)
        {
	system("clear");
	cout << "\t\t\t* * * Option 3: Search by OLN * * *" << endl << endl;
	cout << "\t\tEnter an Operator License Number (or Q to Quit): ";
	getline(cin, inOLN);
	cin.sync();

	if(inOLN[0] == 'q' || inOLN[0] == 'Q')
	 {
	   break;
	 }

	*pPerson = pPersonFile->SearchByOLN(inOLN);
	
	inSSN = pPerson->GetSSN();	

	*pVehicle = pVehicleFile->VSearchBySSN(inSSN);

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
	   cout << endl << endl << "\t\tNo Vehicle";
	   UserWait();
	 }

	if(!(pPerson->IsFound()))
	{
	   cout << endl << endl;
	   cout << "\t\tSocial Security Number was not found" << endl;
	   UserWait();
	 }
        }

	delete pPerson;
	delete pPersonFile;

	delete pVehicle;
	delete pVehicleFile;

	return;
}
