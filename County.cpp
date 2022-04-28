#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "County.h"

using namespace std;

const int MINCODE = 0;
const int MAXCODE = 67;
const int LENGTH = 12;

County::County() : _minCode(MINCODE), _maxCode(MAXCODE), _length(LENGTH)
 {
    char INFILE[] = "county.db";
    ifstream inputFile;

   inputFile.open(INFILE);
   if(!inputFile)
    {
      cerr << "Problem opening input file: " << INFILE << endl;
    }
   else 
    {
	inputFile.seekg(0);
	inputFile.read((char *) & _numberCountys, sizeof(_numberCountys));
	_pCountys = new char[_numberCountys * _length];
	inputFile.seekg(_length);
	inputFile.read(_pCountys, _numberCountys * _length);
	inputFile.close();
	_pCounty = new char[_length + 1];
    }
 }

County::~County() 
 {
    delete[] _pCountys;
    delete[] _pCounty;
 }

char * County::GetCounty(int inCountyCode) const
{
 	_pCounty[_length] = '\0';
	memset(_pCounty, '*', _length);
	if(inCountyCode < _minCode || inCountyCode > _maxCode)
	   return _pCounty;
	strncpy(_pCounty, _pCountys + ((inCountyCode - _minCode)*_length), _length);
	return _pCounty;
}

void County::DisplayCountys() const
{
	const int NUMBERROWS = 17;
	const int COLUMNWIDTH = 24;
	const int BUFFERWIDTH = 90;
	const int codeLength = 2;

	char outputBuffer[NUMBERROWS][BUFFERWIDTH];
	char singleData[_length + 1];
	int columnPosition;
	int currentColumn;
	int currentRow;
	int i;

	if(_numberCountys <= 0)
	{ 
	   cerr << "Error! No Counties to Display!" << endl;
	     return;
	}

	currentRow = 0;
	currentColumn = 0;
	memset(outputBuffer, 0x20, sizeof(outputBuffer));

	for(i = 0; i < _numberCountys; i++)
	 {
	    columnPosition = currentColumn * COLUMNWIDTH;
	    snprintf(outputBuffer[currentRow] + columnPosition, codeLength + 1, "%02d", i + _minCode);
	    outputBuffer[currentRow][columnPosition + codeLength] = ' ';
	    strncpy(singleData, GetCounty(i + _minCode), _length);
	    strncpy(outputBuffer[currentRow] + (columnPosition + (codeLength + 1)),singleData, _length);
	    ++currentRow;
	    if (currentRow >= NUMBERROWS)
	     { 
	        currentRow = 0;
	        currentColumn++;
		continue;
	     }
	 }
	for(i = 0; i < NUMBERROWS; i++)
	 {
	    cout.write(outputBuffer[i], BUFFERWIDTH);
	    cout << "\n";
	 }
}
