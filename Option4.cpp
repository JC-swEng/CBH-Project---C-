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

string UserWait();

void Option4()
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
	string inEdit;
	bool addVehicle = false;
   
	while(true)
        {
	system("clear");
	cout << "\t\t\t* * * Option 4: Add a Record * * *" << endl << endl;
	cout << "\t\tEnter a New Social Security Number (or Q to Quit): ";
	getline(cin, inSSN);
	cin.sync();

	if(inSSN[0] == 'q' || inSSN[0] == 'Q')
	 {
	   break;
	 }

	*testPerson = pPersonFile->SearchBySSN(inSSN);

	if(testPerson->IsFound())
	   {
	   cout << endl << endl;
	   cout << "\t\tSocial Security Number already exists." << endl;
	   UserWait();
	   continue;
	   }

		pPerson->SetSSN(inSSN);

	        cout << endl << endl << "\t\tEnter New First Name: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetFirstName(inEdit);
			              
	        cout << endl << endl << "\t\tEnter New Last Name: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetLastName(inEdit);
			              
	        cout << endl << endl << "\t\tEnter New Middle Initial: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetMiddleInitial(inEdit);

		while(true)
		{	              
	         cout << endl << endl << "\t\tEnter New OLN: ";
		 getline(cin, inEdit);
	         cin.sync();

		 *testPerson = pPersonFile->SearchByOLN(inEdit);

		 if(testPerson->IsFound())
	   	  {
	   	  cout << endl << endl;
	   	  cout << "\t\tError, Operator's License Number already exists." << endl;
	   	  UserWait();
	   	  continue;
		  }
		 pPerson->SetOLN(inEdit);
		 break;
	        }      
	        cout << endl << endl << "\t\tEnter New Street Address: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetStreet(inEdit);
	              
	        cout << endl << endl << "\t\tEnter New City: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetCity(inEdit);
			              
		cout << endl << endl;
		pState->DisplayStates();
	        cout << endl << endl << "\t\tEnter New State Code: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetStateCode(inEdit);
	              
		cout << endl << endl;
		pCounty->DisplayCountys();
	        cout << endl << endl << "\t\tEnter New County Code: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetCountyCode(inEdit);
			              
	        cout << endl << endl << "\t\tEnter New Zip Code: ";
		getline(cin, inEdit);
	        cin.sync();
		pPerson->SetZip(inEdit);
			              
	cout << endl << endl << "\t\tWould you like to Add a Vehicle Record?(Y/N): ";
		getline(cin, inConfirm);
	        cin.sync();
			if(inConfirm[0] == 'y' || inConfirm[0] == 'Y')
		          {
				addVehicle = true;
				pVehicle->SetSSN(inSSN);
				cout << endl << endl;
				pVmake->DisplayVmakes();
			        cout << endl << endl << "\t\tEnter New Vehicle Make Code: ";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetVmakeCode(inEdit);
			              
				cout << endl << endl;
				pVtype->DisplayVtypes();
			        cout << endl << endl << "\t\tEnter New Vehicle Type Code: ";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetVtypeCode(inEdit);
			               
				cout << endl << endl;
				pColor->DisplayColors();
			        cout << endl << endl << "\t\tEnter New Top Color Code: ";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetTopColorCode(inEdit);
			              
				cout << endl << endl;
				pColor->DisplayColors();
			        cout << endl << endl << "\t\tEnter New Bottom Color Code: ";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetBottomColorCode(inEdit);
			              
			        cout << endl << endl << "\t\tEnter New Tag: ";
				getline(cin, inEdit);
			        cin.sync();
				pVehicle->SetTag(inEdit);
		       	}

		system("clear");
		cout << endl << endl;
		pPerson->DisplayPerson();
		if(addVehicle)
		 pVehicle->DisplayVehicle();
		cout << endl << endl << "\t\tDo you wish to save these changes?(Y/N): ";
		getline(cin, inConfirm);
		cin.sync();
		  if(inConfirm[0] == 'y' || inConfirm[0] == 'Y')
		   { 
		       if(addVehicle)
			{
			pVehicleFile->AddVehicle(*pVehicle);
		        pVehicleFile->SortBySSN();
			}
			pPersonFile->AddPerson(*pPerson);
		        pPersonFile->SortBySSN();
			cout << endl << endl << "\t\tChanges Saved.";
			UserWait();
		   }
		  else
		    {
			cout << endl << endl << "\t\tChanges Not Saved.";
			UserWait();
		    }

        }  //  Loop

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
