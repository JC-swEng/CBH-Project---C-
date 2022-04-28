#include <iostream>
#include <string>
#include "Person.h"
#include "PersonFile.h"

using namespace std;

int main()
{
  Person foundPerson1;
  Person foundPerson2;
  Person foundPerson3;

  PersonFile * pPersonFile = new PersonFile;

  foundPerson1 = pPersonFile->SearchBySSN("143466098");
  cout << foundPerson1.GetSSNWithHyphens() << "  " <<  foundPerson1.GetOLN() << foundPerson1.GetLastName();
  cout << ", " << foundPerson1.GetFirstName() << foundPerson1.GetZipWithHyphens() << endl;
  foundPerson2 = pPersonFile->SearchByOLN("3647364  ");
  cout << foundPerson2.GetSSNWithHyphens() << "  " <<  foundPerson2.GetOLN() << foundPerson2.GetLastName();
  cout << ", " << foundPerson2.GetFirstName() << foundPerson2.GetZipWithHyphens() << endl;
  foundPerson3 = pPersonFile->SearchByRecordNumber(1);
  cout << foundPerson3.GetSSNWithHyphens() << "  " <<  foundPerson3.GetOLN() << foundPerson3.GetLastName();
  cout << ", " << foundPerson3.GetFirstName() << foundPerson3.GetZipWithHyphens() << endl;
  delete pPersonFile;
  return 0;
}
