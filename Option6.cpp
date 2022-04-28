#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include "Person.h"
#include "PersonFile.h"
#include "Vehicle.h"
#include "VehicleFile.h"
#include "State.h"
#include "County.h"
#include "Color.h"
#include "Vmake.h"
#include "Vtype.h"

using namespace std;

Person SearchBySSN(const string & aString);
void DisplayPerson();
Vehicle VSearchBySSN(const string & aString);
void DisplayVehicle();
string UserWait();

void Option6()
{
	Person * pPerson = new Person;
	PersonFile * pPersonFile = new PersonFile;

	Person * testPerson = new Person;

	Vehicle * pVehicle = new Vehicle;
	VehicleFile * pVehicleFile = new VehicleFile;

	State * pState = new State;
	County * pCounty = new County;
        Vtype * pVtype = new Vtype;
        Vmake * pVmake = new Vmake;
        Color * pColor = new Color;


	string inSSN;
	string inConfirm;
	string inOpt;
	string inEdit;
   
	while(true)
        {
	system("clear");
	cout << "\t\t\t* * * Option 6: Update Record * * *" << endl << endl;
	cout << "\t\tEnter a Social Security Number to Update a Record(or Q to Quit): ";
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

	else
	 {
	   cout << endl << endl;
	   pPerson->DisplayPerson();
	   if(!pVehicle->IsFound())           
		cout << endl << endl << "\t\tNo Vehicle";
	   if(pVehicle->IsFound())
            {
              cout << endl << endl;
	      pVehicle->DisplayVehicle();
            }
	   cout << endl << endl << "\t\tIs this the record you wish to Update?(Y/N):";
	   getline(cin, inConfirm);
	   cin.sync();
	   if(inConfirm[0] == 'y' || inConfirm[0] == 'Y')
	     {

		bool loop = true;	
		bool edited = false;	

		while(loop)
		  {
			system("clear");
			cout << endl << "\t\t\t* * * Update Record Menu * * *";
			cout << endl << endl << "\t\t0. SSN";
			cout << endl << "\t\t1. First Name";
			cout << endl << "\t\t2. Middle Initial";
			cout << endl << "\t\t3. Last Name";
			cout << endl << "\t\t4. OLN";
			cout << endl << "\t\t5. Street Address";
			cout << endl << "\t\t6. City";
			cout << endl << "\t\t7. County";
			cout << endl << "\t\t8. State";
			cout << endl << "\t\t9. Zip Code";
		     if(pVehicle->IsFound())
			{
			cout << endl << "\t\tA. Vehicle Make";
			cout << endl << "\t\tB. Vehicle Type";
			cout << endl << "\t\tC. Top Color";
			cout << endl << "\t\tD. Bottom Color";
			cout << endl << "\t\tE. License Plate Tag";
			}
			cout << endl << endl << "\tEnter the number of the member you wish to edit (or Q to Quit):";
			getline(cin, inOpt);
			cin.sync();
			switch(inOpt[0])
			   {
			      case'0':
				cout << endl << endl << "\tCurrent SSN: " <<  pPerson->GetSSNWithHyphens();
			        cout << endl << endl << "\t\tEnter New SSN:";
				getline(cin, inEdit);
			        cin.sync();
				*testPerson = pPersonFile->SearchBySSN(inEdit);
				if(testPerson->IsFound())
				 {
				   cout << endl << endl << "\tError, SSN already exists." << endl;
				   UserWait;
				   break;
				 }
				pPerson->SetSSN(inEdit);
				if(pVehicle->IsFound())
				  pVehicle->SetSSN(inEdit);
				edited = true;
			        break;
			      case'1':
				cout << endl << endl << "\tCurrent First Name: " << pPerson->GetFirstName();
			        cout << endl << endl << "\t\tEnter New First Name:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetFirstName(inEdit);
				edited = true;
				break;
			      case'3':
				cout << endl << endl << "\tCurrent Last Name: " << pPerson->GetLastName();
			        cout << endl << endl << "\t\tEnter New Last Name:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetLastName(inEdit);
				edited = true;
			        break;
			      case'2':
				cout << endl << endl << "\tCurrent Middle Initial: " << pPerson->GetMiddleInitial();
			        cout << endl << endl << "\t\tEnter New Middle Initial:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetMiddleInitial(inEdit);
				edited = true;
			        break;
			      case'4':
				cout << endl << endl << "\tCurrent OLN: " << pPerson->GetOLN();
			        cout << endl << endl << "\t\tEnter New OLN:";
				getline(cin, inEdit);
			        cin.sync();
				*testPerson = pPersonFile->SearchByOLN(inEdit);
				if(testPerson->IsFound())
				 {
				   cout << endl << endl << "\tError, OLN already exists." << endl;
				   UserWait;
				   break;
				 }
				pPerson->SetOLN(inEdit);
				edited = true;
			        break;
			      case'5':
				cout << endl << endl << "\tCurrent Street Address: " << pPerson->GetStreet();
			        cout << endl << endl << "\t\tEnter New Street Address:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetStreet(inEdit);
				edited = true;
			        break;
			      case'6':
				cout << endl << endl << "\tCurrent City: " << pPerson->GetCity();
			        cout << endl << endl << "\t\tEnter New City:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetCity(inEdit);
				edited = true;
			        break;
			      case'8':
				cout << endl << endl;
				pState->DisplayStates();
			        cout << endl << endl << "\t\tEnter New State Code:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetStateCode(inEdit);
				edited = true;
			        break;
			      case'7':
				cout << endl << endl;
				pCounty->DisplayCountys();
			        cout << endl << endl << "\t\tEnter New County Code:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetCountyCode(inEdit);
				edited = true;
			        break;
			      case'9':
				cout << endl << endl << "\tCurrent Zip Code: " << pPerson->GetZipWithHyphens();
			        cout << endl << endl << "\t\tEnter New Zip Code:";
				getline(cin, inEdit);
			        cin.sync();
				pPerson->SetZip(inEdit);
				edited = true;
			        break;
			      case'A':
			      case'a':
				cout << endl << endl;
				pVmake->DisplayVmakes();
			        cout << endl << endl << "\t\tEnter New Vehicle Make Code:";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetVmakeCode(inEdit);
				edited = true;
			        break;
			      case'B':
			      case'b':
				cout << endl << endl;
				pVtype->DisplayVtypes();
			        cout << endl << endl << "\t\tEnter New Vehicle Type Code:";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetVtypeCode(inEdit);
				edited = true;
			        break;
			      case'C':
			      case'c':
				cout << endl << endl;
				pColor->DisplayColors();
			        cout << endl << endl << "\t\tEnter New Top Color Code:";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetTopColorCode(inEdit);
				edited = true;
			        break;
			      case'D':
			      case'd':
				cout << endl << endl;
				pColor->DisplayColors();
			        cout << endl << endl << "\t\tEnter New Bottom Color Code:";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetBottomColorCode(inEdit);
				edited = true;
			        break;
			      case'E':
			      case'e':
				cout << endl << endl << "\tCurrent License Plate Tag: " << pVehicle->GetTag();
			        cout << endl << endl << "\t\tEnter New Tag:";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetTag(inEdit);
				edited = true;
			        break;
			      case'Q':
			      case'q':
			        loop = false;
			        break;
			      default:
			        cerr << "Error, invalid entry.";
			        UserWait();
			        break;

			   }   // Switch 
		  }  // inner loop
		if(edited = true)
		{
		system("clear");
		cout << endl << endl;
		pPerson->DisplayPerson();
		if(pVehicle->IsFound())
		 pVehicle->DisplayVehicle();
		cout << endl << endl << "\t\tDo you wish to save these changes?(Y/N): ";
		getline(cin, inConfirm);
		cin.sync();
		  if(inConfirm[0] == 'y' || inConfirm[0] == 'Y')
		   { 
		       if(pVehicle->IsFound())
			{
			pVehicleFile->UpdateVehicle(*pVehicle);
		        pVehicleFile->SortBySSN();
			}
			pPersonFile->UpdatePerson(*pPerson);
		        pPersonFile->SortBySSN();
			cout << endl << endl << "\t\tChanges Saved.";
			UserWait();
		   }
		  else
		    {
			cout << endl << endl << "\t\tChanges Not Saved.";
			UserWait();
		    }
	        }
	     }  // inner if

	 }  // outer else
        }  // outer Loop

	delete pPerson;
	delete pPersonFile;
	delete testPerson;

	delete pVehicle;
	delete pVehicleFile;

	delete pVmake;
	delete pVtype;
	delete pColor;
	delete pState;
	delete pCounty;

	return;
}
