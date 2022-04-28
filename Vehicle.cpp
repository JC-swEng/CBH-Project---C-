#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Vehicle.h"
#include "Vmake.h"
#include "Vtype.h"
#include "Color.h"

using namespace std;

void Upper(string & aString);
string Trim(string aString);

const unsigned int VTYPELENGTH = 15;
const unsigned int VTYPECODELENGTH = 2;
const unsigned int VMAKELENGTH = 11;
const unsigned int VMAKECODELENGTH = 2;
const unsigned int COLORLENGTH = 22;
const unsigned int COLORCODELENGTH = 2;
const unsigned int TAGLENGTH = 7;
const unsigned int SSNLENGTH = 9;

const int RECORDSIZE = 25;

Vehicle::Vehicle() : _found(false), _deleted(false), _length(RECORDSIZE)
{}

void Vehicle::SetVtypeCode(const string & inVtypeCode)
{
	_vtypeCode = "00";
	if(inVtypeCode.length() == 1)
	_vtypeCode.replace(1, 1, inVtypeCode);
	else
	_vtypeCode.replace(0, 2, inVtypeCode);
}

void Vehicle::SetVmakeCode(const string & inVmakeCode)
{
	_vmakeCode = "00";
	if(inVmakeCode.length() == 1)
	_vmakeCode.replace(1, 1, inVmakeCode);
	else
	_vmakeCode.replace(0, 2, inVmakeCode);
}

void Vehicle::SetTopColorCode(const string & inTcCode)
{
	_topColorCode = "00";
	if(inTcCode.length() == 1)
	_topColorCode.replace(1, 1, inTcCode);
	else
	_topColorCode.replace(0, 2, inTcCode);
}

void Vehicle::SetBottomColorCode(const string & inBcCode)
{
	_bottomColorCode = "00";
	if(inBcCode.length() == 1)
	_bottomColorCode.replace(1, 1, inBcCode);
	else
	_bottomColorCode.replace(0, 2, inBcCode);
}

void Vehicle::SetTag(const string & inTag)      
{
	_tag.assign(inTag, 0, TAGLENGTH);
}

void Vehicle::MakeVehicle(const string & inRecord)
{
	_found= true;
	_SSN = inRecord.substr(0, SSNLENGTH);
	_vtypeCode = inRecord.substr(9, VTYPECODELENGTH);
	_topColorCode = inRecord.substr(11, COLORCODELENGTH);	
	_vmakeCode = inRecord.substr(13, VMAKECODELENGTH);
	_bottomColorCode = inRecord.substr(15, COLORCODELENGTH);
	_tag = inRecord.substr(17, TAGLENGTH);
	_deleted = inRecord[24] == '1' ? true : false; 
}

string Vehicle::UnMakeVehicle()
{
	string data;
	int len;
	
	data.assign(_length, ' ');
	
	len = _SSN.length() < SSNLENGTH ? _SSN.length() : SSNLENGTH;
	data.replace(0, len, _SSN);

	len = _vtypeCode.length() < VTYPECODELENGTH ? _vtypeCode.length() : VTYPECODELENGTH;
	data.replace(9, len, _vtypeCode);

	len = _topColorCode.length() < COLORCODELENGTH ? _topColorCode.length() : COLORCODELENGTH;
	data.replace(11, len, _topColorCode);

	len = _vmakeCode.length() < VMAKECODELENGTH ? _vmakeCode.length() : VMAKECODELENGTH;
	data.replace(13, len, _vmakeCode);

	len = _bottomColorCode.length() < COLORCODELENGTH ? _bottomColorCode.length() : COLORCODELENGTH;
	data.replace(15, len, _bottomColorCode);

	len = _tag.length() < TAGLENGTH ? _tag.length() : TAGLENGTH;
	data.replace(17, len, _tag);

	data[24] = _deleted ? '1' : '0';

	return data;
}

void Vehicle::DisplayVehicle() const
{
	string data;
	int iCode;
	char outputLine[][89] = {

		" $$$-$$-$$$$     ($$) $$$$$$$$$$$      ($$) $$$$$$$$$$$$$$$       $$$$$$$      ",  //00
		"  Top Color:($$) $$$ $$$$$$$$$$$$$$$$$$$$$$  Bottom:($$) $$$ $$$$$$$$$$$$$$$$$$$$$$  ",  //01
	       //          1         2         3         4         5         6         7         8 
	      // 0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
	};

	data.clear();
	data.assign(11,' ');
	data.replace(0, SSNLENGTH, SSNHyphens(_SSN));
	strncpy(outputLine[0]+ 1,data.c_str(),11);

	data.clear();
	data.assign(TAGLENGTH, ' ');
	data.replace(0, _tag.length(), _tag);
	strncpy(outputLine[0] + 66, data.c_str(), TAGLENGTH);

	Vmake * pVmake = new Vmake;
	iCode = atoi(_vmakeCode.c_str());
	data.clear();
	data.assign(pVmake->GetVmake(iCode));
	strncpy(outputLine[0]+ 18, _vmakeCode.c_str(), 2);
	strncpy(outputLine[0]+ 22, data.c_str(), 11);
	delete pVmake;

	Vtype * pVtype = new Vtype;
	iCode = atoi(_vtypeCode.c_str());
	data.clear();
	data.assign(pVtype->GetVtype(iCode));
	strncpy(outputLine[0]+ 40, _vtypeCode.c_str(), 2);
	strncpy(outputLine[0]+ 44, data.c_str(), 15);
	delete pVtype;

	Color * pColor = new Color;
	iCode = atoi(_topColorCode.c_str());
	data.clear();
	data.assign(pColor->GetColor(iCode));
	strncpy(outputLine[1]+ 17, data.c_str(), 3);
	strncpy(outputLine[1]+ 13, _topColorCode.c_str(), 2);
	strncpy(outputLine[1]+ 21, (data.c_str())+3, pColor->GetLength()- 3);

	iCode = atoi(_bottomColorCode.c_str());
	data.clear();
	data.assign(pColor->GetColor(iCode));
	strncpy(outputLine[1]+ 57, data.c_str(), 3);
	strncpy(outputLine[1]+ 53, _bottomColorCode.c_str(), 2);
	strncpy(outputLine[1]+ 61, (data.c_str())+3, pColor->GetLength()- 3);
	delete pColor;

	cout << "\n\t\t\t\t________ Vehicle Information ________\n\n";
	for(int i =0; i < 2; i++)
	{
	cout << "\t" << outputLine[i] << "\n" << endl;
	}
}

void Vehicle::PrintVehicle() const
{
        string data;
        int iCode;
        char outputLine[][89] = {

                "           ($$) $$$$$$$$$$$      ($$) $$$$$$$$$$$$$$$       $$$$$$$                ",  //00
                "  Top Color:($$) $$$ $$$$$$$$$$$$$$$$$$$$$$  Bottom:($$) $$$ $$$$$$$$$$$$$$$$$$$$$$  ",  //01
               //          1         2         3         4         5         6         7         8
              // 0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567
        };

        data.clear();
        data.assign(TAGLENGTH, ' ');
        data.replace(0, _tag.length(), _tag);
        strncpy(outputLine[0] + 60, data.c_str(), TAGLENGTH);

        Vmake * pVmake = new Vmake;
        iCode = atoi(_vmakeCode.c_str());
        data.clear();
        data.assign(pVmake->GetVmake(iCode));
        strncpy(outputLine[0]+ 12, _vmakeCode.c_str(), 2);
        strncpy(outputLine[0]+ 16, data.c_str(), 11);
        delete pVmake;

        Vtype * pVtype = new Vtype;
        iCode = atoi(_vtypeCode.c_str());
        data.clear();
        data.assign(pVtype->GetVtype(iCode));
        strncpy(outputLine[0]+ 34, _vtypeCode.c_str(), 2);
        strncpy(outputLine[0]+ 38, data.c_str(), 15);
        delete pVtype;

        Color * pColor = new Color;
        iCode = atoi(_topColorCode.c_str());
        data.clear();
        data.assign(pColor->GetColor(iCode));
        strncpy(outputLine[1]+ 17, data.c_str(), 3);
        strncpy(outputLine[1]+ 13, _topColorCode.c_str(), 2);
        strncpy(outputLine[1]+ 21, (data.c_str())+3, pColor->GetLength()- 3);

        iCode = atoi(_bottomColorCode.c_str());
        data.clear();
        data.assign(pColor->GetColor(iCode));
        strncpy(outputLine[1]+ 57, data.c_str(), 3);
        strncpy(outputLine[1]+ 53, _bottomColorCode.c_str(), 2);
        strncpy(outputLine[1]+ 61, (data.c_str())+3, pColor->GetLength()- 3);
        delete pColor;

        for(int i =0; i < 2; i++)
        {
        cout << "\t" << outputLine[i] << "\n";
        }
}

