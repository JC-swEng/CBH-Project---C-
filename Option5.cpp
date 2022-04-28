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

void Option5()
{
	Person * pPerson = new Person;
	PersonFile * pPersonFile = new PersonFile;

	Vehicle * pVehicle = new Vehicle;
	VehicleFile * pVehicleFile = new VehicleFile;

	string inSSN;
	string deleteOpt;
   
	while(true)
        {
	system("clear");
	cout << "\t\t\t* * * Option 5: Search by SSN to Delete the Record* * *" << endl << endl;
	cout << "\t\tEnter a Social Security Number to DELETE Record (or Q to Quit): ";
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
	   cout << endl << endl << "\t\tIs this the Record you wish to Delete?(Y/N):";
	   getline(cin, deleteOpt);
	   cin.sync();
		if(deleteOpt[0] == 'y' || deleteOpt[0] == 'Y')
		{ 
		  pPerson->SetDeleted(true); 
		  pVehicle->SetDeleted(true);
		  pPersonFile->UpdatePerson(*pPerson);
		  pVehicleFile->UpdateVehicle(*pVehicle);
		  system("clear");
		  cout << endl << endl << "\t\tRecord was Deleted successfully." << endl;
		  UserWait();
		}
		else
		{
		  system("clear");
		  cout << endl << endl << "\t\tRecord was NOT deleted." << endl;
		  UserWait();
		}
	 }

	if(pPerson->IsFound() && !(pVehicle->IsFound()))
	 {
	   cout << endl << endl;
	   pPerson->DisplayPerson();
	   cout << endl << endl << "\t\tNo Vehicle";

           cout << endl << endl << "\t\tIs this the Record you wish to Delete?(Y/N):";
           getline(cin, deleteOpt);
           cin.sync();
                if(deleteOpt[0] == 'y' || deleteOpt[0] == 'Y')
                {
                  pPerson->SetDeleted(true);
		  pPersonFile->UpdatePerson(*pPerson);
                  system("clear");
                  cout << endl << endl << "\t\tRecord was Deleted successfully." << endl;
                  UserWait();
                }
                else
                {
                  system("clear");
                  cout << endl << endl << "\t\tRecord was NOT deleted." << endl;
                  UserWait();
                }

	 }

        }

	delete pPerson;
	delete pPersonFile;

	delete pVehicle;
	delete pVehicleFile;

	return;
}
