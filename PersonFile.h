#include <fstream>
#include <string>

using namespace std;

class Person;

class PersonFile
{
	public:
	   PersonFile();
	   ~PersonFile();
	   int GetNumberOfPersons() const { return _numberPersons; }
	   int GetCurrentRecordNumber() const { return _currentRecordNumber; }
	   void SortBySSN();
	   Person SearchBySSN(const string & aSSN);
	   Person SearchByOLN(const string & aOLN);
	   Person SearchByRecordNumber(int inRecNum);
	   void AddPerson(Person & aPerson);
	   void UpdatePerson(Person & aPerson);

	private:
	   int _numberPersons;
	   int _recordSize;
	   int _currentRecordNumber;
	   fstream _personFile;

};
