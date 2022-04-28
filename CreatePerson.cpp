#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "PersonFile.h"

using namespace std;

const int DATALENGTH = 111;

int main()
{
	char InFile[] = "person.data";
 	char OutFile[] = "person.db";
	char inBuffer[150];
	int numberRecords;
	ifstream inputFile;
	ofstream outputFile;

 	numberRecords = 0;	

   inputFile.open(InFile);
   if(!inputFile)
     {
       cerr << "Problem opening input file: " << InFile << endl;
       return 1; 
     }

   outputFile.open(OutFile);
   if(!outputFile)
     {
       cerr << "Problem opening output file: " << OutFile << endl;
       inputFile.close();
       return 2; 
     }
	while(true)
          {
	     memset(inBuffer, ' ', sizeof(inBuffer));
	     inputFile.getline(inBuffer, sizeof(inBuffer));
	     if(inputFile.eof())
               break;
	     outputFile.seekp((numberRecords+1)*DATALENGTH);
	     outputFile.write(inBuffer, DATALENGTH);
	     ++numberRecords;
	   } 

	outputFile.seekp(0);
	outputFile.write((char*) &numberRecords, sizeof(numberRecords));

	inputFile.close();
	outputFile.close();

	PersonFile * pPersonFile = new PersonFile;
	pPersonFile->SortBySSN();
	delete pPersonFile;

	cout << "Number of records: " << numberRecords << endl;
	cout << "Sorting..." << endl;
	return 0;
}


