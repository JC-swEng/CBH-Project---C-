#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "State.h"

using namespace std;

const int MINCODE = 1;
const int MAXCODE = 51;
const int LENGTH = 22;

State::State() : _minCode(MINCODE), _maxCode(MAXCODE), _length(LENGTH)
 {
    char INFILE[] = "state.db";
    ifstream inputFile;

   inputFile.open(INFILE);
   if(!inputFile)
    {
      cerr << "Problem opening input file: " << INFILE << endl;
    }
   else 
    {
	inputFile.seekg(0);
	inputFile.read((char *) & _numberStates, sizeof(_numberStates));
	_pStates = new char[_numberStates * _length];
	inputFile.seekg(_length);
	inputFile.read(_pStates, _numberStates * _length);
	inputFile.close();
	_pState = new char[_length + 1];
    }
 }

State::~State() 
 {
    delete[] _pStates;
    delete[] _pState;
 }

char * State::GetState(int inStateCode) const
{
 	_pState[_length] = '\0';
	memset(_pState, '*', _length);
	if(inStateCode < _minCode || inStateCode > _maxCode)
	   return _pState;
	strncpy(_pState, _pStates + ((inStateCode - _minCode)*_length), _length);
	return _pState;
}

void State::DisplayStates() const
{
	const int NUMBERROWS = 17;
	const int COLUMNWIDTH = 30;
	const int BUFFERWIDTH = 100;

	char outputBuffer[NUMBERROWS][BUFFERWIDTH];
	char singleData[_length + 1];
	int columnPosition;
	int currentColumn;
	int currentRow;
	int i;
	const int codeLength = 2;
	const int _abbrLength = 2;

	if(_numberStates <= 0)
	{ 
	   cerr << "Error! No States to Display!" << endl;
	     return;
	}

	currentRow = 0;
	currentColumn = 0;
	memset(outputBuffer, 0x20, sizeof(outputBuffer));

	for(i = 0; i < _numberStates; i++)
	 {
	    columnPosition = currentColumn * COLUMNWIDTH;
	    snprintf(outputBuffer[currentRow] + columnPosition, codeLength + 1, "%02d", i + _minCode);
	    outputBuffer[currentRow][columnPosition + codeLength] = ' ';
	    strncpy(singleData, GetState(i + _minCode), _length);
	    strncpy(outputBuffer[currentRow] + (columnPosition + (codeLength + 1)),singleData, _abbrLength);
	    strncpy(outputBuffer[currentRow] + (columnPosition + ( (codeLength + 1)+(_abbrLength + 1) )), singleData + _abbrLength, _length - _abbrLength);
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
