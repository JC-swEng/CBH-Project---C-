#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "Color.h"

using namespace std;

const int MINCODE = 1;
const int MAXCODE = 31;
const int LENGTH = 25;

Color::Color() : _minCode(MINCODE), _maxCode(MAXCODE), _length(LENGTH)
 {
    char INFILE[] = "color.db";
    ifstream inputFile;

   inputFile.open(INFILE);
   if(!inputFile)
    {
      cerr << "Problem opening input file: " << INFILE << endl;
    }
   else 
    {
	inputFile.seekg(0);
	inputFile.read((char *) & _numberColors, sizeof(_numberColors));
	_pColors = new char[_numberColors * _length];
	inputFile.seekg(_length);
	inputFile.read(_pColors, _numberColors * _length);
	inputFile.close();
	_pColor = new char[_length + 1];
    }
 }

Color::~Color() 
 {
    delete[] _pColors;
    delete[] _pColor;
 }

char * Color::GetColor(int inColorCode) const
{
 	_pColor[_length] = '\0';
	memset(_pColor, '*', _length);
	if(inColorCode < _minCode || inColorCode > _maxCode)
	   return _pColor;
	strncpy(_pColor, _pColors + ((inColorCode - _minCode)*_length), _length);
	return _pColor;
}

void Color::DisplayColors() const
{
	const int NUMBERROWS = 16;
	const int COLUMNWIDTH = 27;
	const int BUFFERWIDTH = 100;

	char outputBuffer[NUMBERROWS][BUFFERWIDTH];
	char singleData[_length + 1];
	int columnPosition;
	int currentColumn;
	int currentRow;
	int i;
	const int codeLength = 2;
	const int _abbrLength = 3;

	if(_numberColors <= 0)
	{ 
	   cerr << "Error! No Colors to Display!" << endl;
	     return;
	}

	currentRow = 0;
	currentColumn = 0;
	memset(outputBuffer, 0x20, sizeof(outputBuffer));

	for(i = 0; i < _numberColors; i++)
	 {
	    columnPosition = currentColumn * COLUMNWIDTH;
	    snprintf(outputBuffer[currentRow] + columnPosition, codeLength + 1, "%02d", i + _minCode);
	    outputBuffer[currentRow][columnPosition + codeLength] = ' ';
	    strncpy(singleData, GetColor(i + _minCode), _length);
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
	    cout << endl;
	 }
}
