#include <iostream>
#include <string>
#include <cstdlib> 
#include "State.h"
#include "County.h"
#include "Vmake.h"
#include "Vtype.h"
#include "Color.h"

using namespace std;

string UserWait();

void Option1()
{
   State * pState = new State;
   County * pCounty = new County;
   Vtype * pVtype = new Vtype;
   Vmake * pVmake = new Vmake;
   Color * pColor = new Color;

   bool loop = true;

   while(loop)
   {
   string opt;

   system("clear");
   cout << "\t\t\t* * * Option 1: Display Auxiliary Files Menu * * *" << endl << endl;
   cout << "\t\tOption 1: Display States" << endl;
   cout << "\t\tOption 2: Display Counties" << endl;
   cout << "\t\tOption 3: Display Vehicle Types" << endl;
   cout << "\t\tOption 4: Display Vehicle Makes" << endl;
   cout << "\t\tOption 5: Display Colors" << endl;
   cout << "\t\tOption 6: Quit" << endl << endl;
   cout << "\tEnter Option Number: ";

   getline(cin,opt);
   cin.sync();
   system("clear");
   switch(opt[0])
    {
      case'1':
	cout << endl << "\t\t\t* * * States and Abbreviations * * *" << endl << endl;
        pState->DisplayStates();
        UserWait();
        break;
      case'2':
	cout << endl << "\t\t\t* * * Counties and Codes * * *" << endl << endl;
        pCounty->DisplayCountys();
        UserWait();
        break;
      case'3':
	cout << endl << "\t\t\t* * * Vehicle Types * * *" << endl << endl;
        pVtype->DisplayVtypes();
        UserWait();
        break;
      case'4':
	cout << endl << "\t\t\t* * * Vehicle Makes * * *" << endl << endl;
        pVmake->DisplayVmakes();
        UserWait();
        break;
      case'5':
	cout << endl << "\t\t\t* * * Vehicle Colors * * *" << endl << endl;
        pColor->DisplayColors();
        UserWait();
        break;
      case'6':
      case'Q':
      case'q':
      case'E':
      case'e':
        loop = false;
        break;
      default:
        cerr << endl << endl <<  "\tError, invalid entry." << endl;
        UserWait();
        break;
    }
   }
	delete pState;
	delete pCounty;
	delete pVmake;
	delete pVtype;
	delete pColor;
}
