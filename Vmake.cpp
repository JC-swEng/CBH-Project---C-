#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "Vmake.h"

using namespace std;

const int MINCODE = 1;
const int MAXCODE = 51;
const int LENGTH = 11;

Vmake::Vmake() : _minCode(MINCODE), _maxCode(MAXCODE), _length(LENGTH)
 {
    char INFILE[] = "vmake.db";
    ifstream inputFile;

   inputFile.open(INFILE);
   if(!inputFile)
    {
      cerr << "Problem opening input file: " << INFILE << endl;
    }
   else 
    {
	inputFile.seekg(0);
	inputFile.read((char *) & _numberVmakes, sizeof(_numberVmakes));
	_pVmakes = new char[_numberVmakes * _length];
	inputFile.seekg(_length);
	inputFile.read(_pVmakes, _numberVmakes * _length);
	inputFile.close();
	_pVmake = new char[_length + 1];
    }
 }

Vmake::~Vmake() 
 {
    delete[] _pVmakes;
    delete[] _pVmake;
 }

char * Vmake::GetVmake(int inVmakeCode) const
{
 	_pVmake[_length] = '\0';
	memset(_pVmake, '*', _length);
	if(inVmakeCode < _minCode || inVmakeCode > _maxCode)
	   return _pVmake;
	strncpy(_pVmake, _pVmakes + ((inVmakeCode - _minCode)*_length), _length);
	return _pVmake;
}

void Vmake::DisplayVmakes() const
{
	const int NUMBERROWS = 13;
	const int COLUMNWIDTH = 20;
	const int BUFFERWIDTH = 90;
	const int codeLength = 2;

	char outputBuffer[NUMBERROWS][BUFFERWIDTH];
	char singleData[_length + 1];
	int columnPosition;
	int currentColumn;
	int currentRow;
	int i;

	if(_numberVmakes <= 0)
	{ 
	   cerr << "Error! No Vehicl makes to Display!" << endl;
	     return;
	}

	currentRow = 0;
	currentColumn = 0;
	memset(outputBuffer, 0x20, sizeof(outputBuffer));

	for(i = 0; i < _numberVmakes; i++)
	 {
	    columnPosition = currentColumn * COLUMNWIDTH;
	    snprintf(outputBuffer[currentRow] + columnPosition, codeLength + 1, "%02d", i + _minCode);
	    outputBuffer[currentRow][columnPosition + codeLength] = ' ';
	    strncpy(singleData, GetVmake(i + _minCode), _length);
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
