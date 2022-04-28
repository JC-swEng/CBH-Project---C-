//Main CBH project file

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string UserWait();
void PrintHdMenu();
void Option1();  // menus
void Option2();  // ssn search
void Option3();  // oln search
void Option4();  // add 
void Option5();  // delete
void Option6();  // update
void Option7();  // display all records

int main()
{
  bool loop = true;

  while(loop)
  {
   string opt;
   PrintHdMenu();
   getline(cin,opt);
   cin.sync();
   system("clear");
   switch(opt[0])
    {
      case'1':
        Option1();
        break;
      case'2':
        Option2();
        break;
      case'3':
        Option3();
        break;
      case'4':
        Option4();
        break;
      case'5':
        Option5();
        break;
      case'6':
        Option6();
        break;
      case'7':
        Option7();
        break;
      case'8':
      case'Q':
      case'q':
      case'E':
      case'e':
	loop = false;
	break;
      default:
	cerr << "Error, invalid entry.";
	UserWait();
	break;
    }
  }
}
