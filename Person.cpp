#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Person.h"
#include "State.h"
#include "County.h"

using namespace std;

void Upper(string & aString);
string Trim(string aString);

const unsigned int SSNLENGTH = 9;
const unsigned int OLNLENGTH = 9;
const unsigned int STATECODELENGTH = 2;
const unsigned int COUNTYCODELENGTH = 2;
const unsigned int LASTNAMELENGTH = 17;
const unsigned int FIRSTNAMELENGTH = 12;
const unsigned int MIDDLEINITIALLENGTH = 1;
const unsigned int STREETLENGTH = 30;
const unsigned int CITYLENGTH = 19;
const unsigned int ZIPLENGTH = 9;
const int RECORDSIZE = 111;

Person::Person() : _found(false), _deleted(false), _length(RECORDSIZE)
{}

void Person::SetFirstName(const string & inFirstName)
{
	int len = inFirstName.length() < FIRSTNAMELENGTH ? inFirstName.length() : FIRSTNAMELENGTH;
	_firstName.assign(inFirstName, 0, len);
	Upper(_firstName);
}

void Person::SetMiddleInitial(const string & inMiddleInitial)
{
	int len = inMiddleInitial.length() < MIDDLEINITIALLENGTH ? inMiddleInitial.length() : MIDDLEINITIALLENGTH;
	_middleInitial.assign(inMiddleInitial, 0, len);
	Upper(_middleInitial);
}

void Person::SetLastName(const string & inLastName)
{
	int len = inLastName.length() < LASTNAMELENGTH ? inLastName.length() : LASTNAMELENGTH;
	_lastName.assign(inLastName, 0, len);
	Upper(_lastName);
}

void Person::SetStateCode(const string & inStateCode)
{
	_stateCode = "00";
	if(inStateCode.length() == 1)
	   _stateCode.replace(1, 1, inStateCode);
	else
	   _stateCode.replace(0, 2, inStateCode);
}

void Person::SetCountyCode(const string & inCountyCode)
{
	_countyCode = "00";
	if(inCountyCode.length() == 1)
	   _countyCode.replace(1, 1, inCountyCode);
	else
	   _countyCode.replace( 0 , 2, inCountyCode);
}

void Person::SetStreet(const string & inStreet)
{
	_street.assign(inStreet, 0, STREETLENGTH);
}

void Person::SetCity(const string & inCity)
{
	_city.assign(inCity, 0, CITYLENGTH);
}

void Person::MakePerson(const string & inRecord)
{
	_found= true;
	_SSN = inRecord.substr(0, SSNLENGTH);
	_OLN = inRecord.substr(9, OLNLENGTH);
	_stateCode = inRecord.substr(18, STATECODELENGTH);
	_countyCode = inRecord.substr(20, COUNTYCODELENGTH);
	_lastName = inRecord.substr(22, LASTNAMELENGTH);
	_firstName = inRecord.substr(39, FIRSTNAMELENGTH);
	_middleInitial = inRecord.substr(51, MIDDLEINITIALLENGTH);
	_street = inRecord.substr(52, STREETLENGTH);
	_city = inRecord.substr(82, CITYLENGTH);
	_zip = inRecord.substr(101, ZIPLENGTH);
	_deleted = inRecord[110] == '1' ? true : false; 
}

string Person::UnMakePerson()
{
	string data;
	int len;
	
	data.assign(_length, ' ');
	
	len = _SSN.length() < SSNLENGTH ? _SSN.length() : SSNLENGTH;
	data.replace(0, len, _SSN);

	len = _OLN.length() < OLNLENGTH ? _OLN.length() : OLNLENGTH;
	data.replace(9, len, _OLN);

	len = _stateCode.length() < STATECODELENGTH ? _stateCode.length() : STATECODELENGTH;
	data.replace(18, len, _stateCode);

	len = _countyCode.length() < COUNTYCODELENGTH ? _countyCode.length() : COUNTYCODELENGTH;
	data.replace(20, len, _countyCode);

	len = _lastName.length() < LASTNAMELENGTH ? _lastName.length() : LASTNAMELENGTH;
	data.replace(22, len, _lastName);

	len = _firstName.length() < FIRSTNAMELENGTH ? _firstName.length() : FIRSTNAMELENGTH;
	data.replace(39, len, _firstName);

	len = _middleInitial.length() < MIDDLEINITIALLENGTH ? _middleInitial.length() : MIDDLEINITIALLENGTH;
	data.replace(51, len, _middleInitial);

	len = _street.length() < STREETLENGTH ? _street.length() : STREETLENGTH;
	data.replace(52, len, _street);

	len = _city.length() < CITYLENGTH ? _city.length() : CITYLENGTH;
	data.replace(82, len, _city);

	len = _zip.length() < ZIPLENGTH ? _zip.length() : ZIPLENGTH;
	data.replace(101, len, _zip);

	data[110] = _deleted ? '1' : '0';

	return data;
}

void Person::DisplayPerson() const
{
	string data;
	string fullName;
	int iCode;
	char outputLine[][82] = {

		"$$$-$$-$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      DL#: $$$$$$$$$   $$   ",  //00
		"     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$            Co: ($$) $$$$$$$$$$$$        ",  //01
		"   $$$$$$$$$$$$$$$$$$$    $$$$$-$$$$    St: ($$) $$ $$$$$$$$$$$$$$$$$$$$    "   //02 
	       //          1         2         3         4         5         6         7         8 
	      // 012345678901234567890123456789012345678901234567890123456789012345678901234567890
	};
	fullName.clear();
	fullName.append(Trim(_lastName));
	fullName.append(", ");
	fullName.append(Trim(_firstName));
	fullName.append(" ");
	if(_middleInitial != " ")
	 {
	  fullName.append(_middleInitial);
	  fullName.append(". ");
	 } 
	data.assign(34,' ');
	data.replace(0, fullName.length(), fullName);
	strncpy(outputLine[0]+14, data.c_str(), 34);

	data.clear();
	data.assign(11,' ');
	data.replace(0, SSNLENGTH, SSNHyphens(_SSN));
	strncpy(outputLine[0],data.c_str(),11);

	data.clear();
	data.assign(OLNLENGTH, ' ');
	data.replace(0, _OLN.length(), _OLN);
	strncpy(outputLine[0] + 59, data.c_str(), OLNLENGTH);

	data.clear();
	data.assign(STREETLENGTH, ' ');
	data.replace(0, _street.length(), _street);
	strncpy(outputLine[1] + 5, data.c_str(), STREETLENGTH);
	  
	data.clear();
	data.assign(CITYLENGTH, ' ');
	data.replace(0, _city.length(), _city);
	strncpy(outputLine[2] + 3, data.c_str(), CITYLENGTH);

	data.clear();
	data.assign(10, ' ');
	data.replace(0, _zip.length(),ZipHyphens(_zip));
	strncpy(outputLine[2] + 26, data.c_str(), ZIPLENGTH + 1);

	State * pState = new State;
	iCode = atoi(_stateCode.c_str());
	data.clear();
	data.assign(pState->GetState(iCode));
	strncpy(outputLine[0]+ 71, data.c_str(), 2);
	strncpy(outputLine[2]+ 49, data.c_str(), 2);
	strncpy(outputLine[2]+ 45, _stateCode.c_str(), 2);
	strncpy(outputLine[2]+ 52, (data.c_str())+2, pState->GetLength()- 2);
	delete pState;

	County * pCounty = new County;
	iCode = atoi(_countyCode.c_str());
	data.clear();
	data.assign(pCounty->GetCounty(iCode));
	strncpy(outputLine[1]+ 52, _countyCode.c_str(), 2);
	strncpy(outputLine[1]+ 56, data.c_str(), pCounty->GetLength());
	delete pCounty;
       
	cout << "\n\t\t\t\t________ Driver Information ________\n\n";
        for(int i =0; i < 3; i++)
        {
        cout << "\t" << outputLine[i] << "\n" << endl;
        }
}

void Person::PrintPerson() const
{
        string data;
        string fullName;
        int iCode;
        char outputLine[][87] = {

         "    $$$-$$-$$$$     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      DL#: $$$$$$$$$ $$    ",  //00
         " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$ $$ $$$$$-$$$$  ",  //01
        //          1         2         3         4         5         6         7         8
       // 0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
        };
        fullName.clear();
        fullName.append(Trim(_lastName));
        fullName.append(", ");
        fullName.append(Trim(_firstName));
        fullName.append(" ");
        if(_middleInitial != " ")
         {
          fullName.append(_middleInitial);
          fullName.append(". ");
         }
        data.assign(34,' ');
        data.replace(0, fullName.length(), fullName);
        strncpy(outputLine[0]+20, data.c_str(), 34);

        data.clear();
        data.assign(11,' ');
        data.replace(0, SSNLENGTH, SSNHyphens(_SSN));
        strncpy(outputLine[0]+4,data.c_str(),11);

        data.clear();
        data.assign(OLNLENGTH, ' ');
        data.replace(0, _OLN.length(), _OLN);
        strncpy(outputLine[0] + 65, data.c_str(), OLNLENGTH);

        data.clear();
        data.assign(STREETLENGTH, ' ');
        data.replace(0, _street.length(), _street);
        strncpy(outputLine[1] + 1, data.c_str(), STREETLENGTH);

        data.clear();
        data.assign(CITYLENGTH, ' ');
        data.replace(0, _city.length(), _city);
        strncpy(outputLine[1] + 34, data.c_str(), CITYLENGTH);

        data.clear();
        data.assign(10, ' ');
        data.replace(0, _zip.length(),ZipHyphens(_zip));
        strncpy(outputLine[1] + 72, data.c_str(), 10);

        State * pState = new State;
        iCode = atoi(_stateCode.c_str());
        data.clear();
        data.assign(pState->GetState(iCode));
        strncpy(outputLine[0]+ 75, data.c_str(), 2);
        strncpy(outputLine[1]+ 69, data.c_str(), 2);
        delete pState;

        County * pCounty = new County;
        iCode = atoi(_countyCode.c_str());
        data.clear();
        data.assign(pCounty->GetCounty(iCode));
        strncpy(outputLine[1]+ 56, data.c_str(), pCounty->GetLength());
        delete pCounty;

        for(int i =0; i < 3; i++)
        {
        cout << "\t" << outputLine[i] << endl;
        }
}

