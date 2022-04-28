#include <iostream>
#include <string>
#include <cstring>
#include "Person.h"
#include "PersonFile.h"

using namespace std;

string SSNHyphens(const string &);
string SSNNoHyphens(const string &);
string ZipHyphens(const string &);
string ZipNoHyphens(const string &);

const int RECORDSIZE = 111;

PersonFile::PersonFile() : _recordSize(RECORDSIZE)
{
	const char PERSONFILE[] = "person.db";
	int initZero;

	initZero = 0;
	fstream person1(PERSONFILE, ios::in | ios::out | ios::binary);
	if(!person1.is_open())
	  { 
	     ofstream person2(PERSONFILE);
	     person2.seekp(0);
	     person2.write((char *) &initZero, sizeof(initZero));
	     person2.close();
	  }
	else
	     person1.close();
	     _personFile.open(PERSONFILE, ios::in | ios::out | ios::binary);
        if(!_personFile)
	       cerr << "Error opening file " << PERSONFILE << endl;
	else
	  {
	     _personFile.seekg(0);
	     _personFile.read((char*)&_numberPersons, sizeof(_numberPersons));
	  }
}

PersonFile::~PersonFile()
{  _personFile.close(); }

void PersonFile::SortBySSN()
{
	bool sorted;
	char input1[RECORDSIZE];
	char input2[RECORDSIZE];
	int pass;
	int i;

	pass = 1;
	sorted = false;
	while(!sorted)
	 {
	   sorted = true;
	   for(i=1; i <= _numberPersons - pass; ++i)
	    {
	      _personFile.seekg(i * _recordSize);
	      _personFile.read(input1, _recordSize);
	      _personFile.seekg((i + 1) * _recordSize);
	      _personFile.read(input2, _recordSize);
	    if(strncmp(input1, input2, 9) < 0)
	     continue;
	    _personFile.seekp(i * _recordSize);
	    _personFile.write(input2, _recordSize);
	    _personFile.seekp((i + 1) * _recordSize);
            _personFile.write(input1, _recordSize);
	    sorted = false;
	    }
	  ++pass;
	 }
}

Person PersonFile::SearchBySSN(const string & aSSN)
{
  int first;
  int last;
  int midpoint;
  int icompare;
  char dataRecord[RECORDSIZE];
  string ssnSearch;
  Person foundPerson;

  foundPerson.SetFound(false);
  ssnSearch = SSNNoHyphens(aSSN);
  first=1;
  last=_numberPersons;

  while(true)
  {
    if(first > last) return foundPerson;
    midpoint=(first+last)/2;
    _personFile.seekg(midpoint*RECORDSIZE);
    _personFile.read(dataRecord,RECORDSIZE);
    icompare =  strncmp(ssnSearch.c_str(),dataRecord,9);
    if(icompare < 0) last=midpoint-1;
    if(icompare > 0) first=midpoint+1;
    if(icompare == 0)
    {
      _currentRecordNumber=midpoint+1;
      foundPerson.MakePerson(dataRecord);
      if(foundPerson.IsDeleted())
        foundPerson.SetFound(false);
      return foundPerson;
    }
  }
}

Person PersonFile::SearchByOLN(const string & aOLN)
{
  int icompare;
  char dataRecord[RECORDSIZE];
  string olnSearch;
  Person foundPerson;

  foundPerson.SetFound(false);
  olnSearch = aOLN;

  for(int i = 1; i <= _numberPersons; ++i)        
  {
    _personFile.seekg(i*RECORDSIZE);
    _personFile.read(dataRecord,RECORDSIZE);
    icompare =  strncmp(olnSearch.c_str(),(dataRecord+9),olnSearch.length());
    if(icompare == 0)
    {
      _currentRecordNumber= i+1;
      foundPerson.MakePerson(dataRecord);
      if(foundPerson.IsDeleted())
        foundPerson.SetFound(false);
      return foundPerson;
    }
  }
  return foundPerson;
} 

Person PersonFile::SearchByRecordNumber(int inRecNum)
{
  Person foundPerson;
  char dataRecord[RECORDSIZE];
  _currentRecordNumber = inRecNum+1;

   if(inRecNum > 0 && inRecNum <= _numberPersons)
      {
         _personFile.seekg(inRecNum*RECORDSIZE);
         _personFile.read(dataRecord,RECORDSIZE);
	 foundPerson.MakePerson(dataRecord);
         if(foundPerson.IsDeleted())
           foundPerson.SetFound(false);
	 return foundPerson;
      }
   else
	return foundPerson;
}	

void PersonFile::UpdatePerson(Person & aPerson)
{
	string record = aPerson.UnMakePerson();
	_personFile.seekp((_currentRecordNumber-1)*RECORDSIZE);
	_personFile.write(record.c_str(), RECORDSIZE);
}

void PersonFile::AddPerson(Person & aPerson)
{
	++_numberPersons;
	_currentRecordNumber = _numberPersons+1;
	_personFile.seekp(0);
	_personFile.write((char*)&_numberPersons, sizeof(_numberPersons));
	UpdatePerson(aPerson);
	SortBySSN();
}
