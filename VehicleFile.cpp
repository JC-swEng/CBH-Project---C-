#include <iostream>
#include <string>
#include <cstring>
#include "Vehicle.h"
#include "VehicleFile.h"

using namespace std;

string SSNHyphens(const string &);
string SSNNoHyphens(const string &);

const int RECORDSIZE = 25;

VehicleFile::VehicleFile() : _recordSize(RECORDSIZE)
{
	const char VEHICLEFILE[] = "vehicle.db";
	int initZero;

	initZero = 0;
	fstream vehicle1(VEHICLEFILE, ios::in | ios::out | ios::binary);
	if(!vehicle1.is_open())
	  { 
	     ofstream vehicle2(VEHICLEFILE);
	     vehicle2.seekp(0);
	     vehicle2.write((char *) &initZero, sizeof(initZero));
	     vehicle2.close();
	  }
	else
	     vehicle1.close();
	     _vehicleFile.open(VEHICLEFILE, ios::in | ios::out | ios::binary);
        if(!_vehicleFile)
	       cerr << "Error opening file " << VEHICLEFILE << endl;
	else
	  {
	     _vehicleFile.seekg(0);
	     _vehicleFile.read((char*)&_numberVehicles, sizeof(_numberVehicles));
	  }
}

VehicleFile::~VehicleFile()
{  _vehicleFile.close(); }

void VehicleFile::SortBySSN()
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
	   for(i=1; i <= _numberVehicles - pass; ++i)
	    {
	      _vehicleFile.seekg(i * _recordSize);
	      _vehicleFile.read(input1, _recordSize);
	      _vehicleFile.seekg((i + 1) * _recordSize);
	      _vehicleFile.read(input2, _recordSize);
	    if(strncmp(input1, input2, 9) < 0)
	     continue;
	    _vehicleFile.seekp(i * _recordSize);
	    _vehicleFile.write(input2, _recordSize);
	    _vehicleFile.seekp((i + 1) * _recordSize);
            _vehicleFile.write(input1, _recordSize);
	    sorted = false;
	    }
	  ++pass;
	 }
}

Vehicle VehicleFile::VSearchBySSN(const string & aSSN)
{
  int first;
  int last;
  int midpoint;
  int icompare;
  char dataRecord[RECORDSIZE];
  string ssnSearch;
  Vehicle foundVehicle;

  foundVehicle.SetFound(false);
  ssnSearch = SSNNoHyphens(aSSN);
  first=1;
  last=_numberVehicles;

  while(true)
  {
    if(first > last) return foundVehicle;
    midpoint=(first+last)/2;
    _vehicleFile.seekg(midpoint*RECORDSIZE);
    _vehicleFile.read(dataRecord,RECORDSIZE);
    icompare =  strncmp(ssnSearch.c_str(),dataRecord,9);
    if(icompare < 0) last=midpoint-1;
    if(icompare > 0) first=midpoint+1;
    if(icompare == 0)
    {
      _currentRecordNumber=midpoint+1;
      foundVehicle.MakeVehicle(dataRecord);
      if(foundVehicle.IsDeleted())
        foundVehicle.SetFound(false);
      return foundVehicle;
    }
  }
}

Vehicle VehicleFile::SearchByRecordNumber(int inRecNum)
{
  Vehicle foundVehicle;
  char dataRecord[RECORDSIZE];
  _currentRecordNumber = inRecNum+1;

   if(inRecNum > 0 && inRecNum < _numberVehicles)
      {
         _vehicleFile.seekg(inRecNum*RECORDSIZE);
         _vehicleFile.read(dataRecord,RECORDSIZE);
	 foundVehicle.MakeVehicle(dataRecord);
         if(foundVehicle.IsDeleted())
           foundVehicle.SetFound(false);
	 return foundVehicle;
      }
   else
	return foundVehicle;
}	

void VehicleFile::UpdateVehicle(Vehicle & aVehicle)
{
	string record = aVehicle.UnMakeVehicle();
	_vehicleFile.seekp((_currentRecordNumber-1)*RECORDSIZE);
	_vehicleFile.write(record.c_str(), RECORDSIZE);
}

void VehicleFile::AddVehicle(Vehicle & aVehicle)
{
	++_numberVehicles;
	_currentRecordNumber = _numberVehicles+1;
	_vehicleFile.seekp(0);
	_vehicleFile.write((char*)&_numberVehicles, sizeof(_numberVehicles));
	UpdateVehicle(aVehicle);
	SortBySSN();
}
