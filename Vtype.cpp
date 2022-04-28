#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "Vtype.h"

using namespace std;

const int MINCODE = 1;
const int MAXCODE = 15;
const int LENGTH = 15;

Vtype::Vtype() : _minCode(MINCODE), _maxCode(MAXCODE), _length(LENGTH)
 {
    char INFILE[] = "vtype.db";
    ifstream inputFile;

   inputFile.open(INFILE);
   if(!inputFile)
    {
      cerr << "Problem opening input file: " << INFILE << endl;
    }
   else 
    {
	inputFile.seekg(0);
	inputFile.read((char *) & _numberVtypes, sizeof(_numberVtypes));
	_pVtypes = new char[_numberVtypes * _length];
	inputFile.seekg(_length);
	inputFile.read(_pVtypes, _numberVtypes * _length);
	inputFile.close();
	_pVtype = new char[_length + 1];
    }
 }

Vtype::~Vtype() 
 {
    delete[] _pVtypes;
    delete[] _pVtype;
 }

char * Vtype::GetVtype(int inVtypeCode) const
{
 	_pVtype[_length] = '\0';
	memset(_pVtype, '*', _length);
	if(inVtypeCode < _minCode || inVtypeCode > _maxCode)
	   return _pVtype;
	strncpy(_pVtype, _pVtypes + ((inVtypeCode - _minCode)*_length), _length);
	return _pVtype;
}

void Vtype::DisplayVtypes() const
{
	const int NUMBERROWS = 15;
	const int COLUMNWIDTH = 22;
	const int BUFFERWIDTH = 100;
	const int codeLength = 2;
	char outputBuffer[NUMBERROWS][BUFFERWIDTH];
	char singleData[_length + 1];
	int columnPosition;
	int currentColumn;
	int currentRow;
	int i;

	if(_numberVtypes <= 0)
	{ 
	   cerr << "Error! No Vehicle types to Display!" << endl;
	     return;
	}

	currentRow = 0;
	currentColumn = 0;
	memset(outputBuffer, 0x20, sizeof(outputBuffer));

	for(i = 0; i < _numberVtypes; i++)
	 {
	    columnPosition = currentColumn * COLUMNWIDTH;
	    snprintf(outputBuffer[currentRow] + columnPosition, codeLength + 1, "%02d", i + _minCode);
	    outputBuffer[currentRow][columnPosition + codeLength] = ' ';
	    strncpy(singleData, GetVtype(i + _minCode), _length);
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
	    cout << endl;
	 }
}
