#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "Person.h"
#include "PersonFile.h"
#include "Vehicle.h"
#include "VehicleFile.h"

using namespace std;

void Option7()
{
	Person * pPerson = new Person;
	PersonFile * pPersonFile = new PersonFile;
	Vehicle * pVehicle = new Vehicle;
	VehicleFile * pVehicleFile = new VehicleFile;

	int NumberRecords = pPersonFile->GetNumberOfPersons();
	int printed = 0;
	string inSSN;
	string inQuit;

	int lastheader = -1;  //negative so it won't ever equal printed first time around

	for(int i = 1; i <= NumberRecords; ++i)
	   {
		if(printed%5 == 0 && lastheader != printed )
		  {
			system("clear");
			cout << "\t\t\t* * * Option 7: MasterFile * * *";
			cout << endl << "\t-----------------------------------------------------------------------------------\n";
			cout << "\t    SSN                Full Name                            OLN      State Abbrv.    \n";
			cout << "\t-----------------------------------------------------------------------------------\n";
			cout << "\t  Street                             City              County   State Abbrv.   Zip \n";
			cout << "\t-----------------------------------------------------------------------------------\n";
		    	cout << "\t            Vehicle Make          Vehicle Type         License Plate Tag           \n";
			cout << "\t-----------------------------------------------------------------------------------\n";
			cout << "\t     Top Color                                  Bottom Color                       \n";	
			cout << "\t-----------------------------------------------------------------------------------\n";
			lastheader = printed;
		  }

	 	*pPerson = pPersonFile->SearchByRecordNumber(i);
	 	inSSN = pPerson->GetSSN();
		*pVehicle = pVehicleFile->VSearchBySSN(inSSN);

		if(pPerson->IsFound())
		  {
			cout << endl << endl;
			pPerson->PrintPerson();
			++printed;
			if(!pVehicle->IsFound())
			  cout << endl << "\t\tNo Vehicle" << endl;
			if(pVehicle->IsFound())
			  pVehicle->PrintVehicle();
			cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		  }
		if(printed%5 == 0 || i == NumberRecords)
		 {
		  if(printed != 0)
		   {
			cout << endl << endl << "\t\tPress Enter to continue or Q to Quit: ";
			getline(cin, inQuit);
			cin.sync();
			if(inQuit[0] == 'q' || inQuit[0] == 'Q')
			   break;
		   }
		 }
	   }  // Loop
}
