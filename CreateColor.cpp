#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

const int CodeLen = 2; 
const int DataLen = 25;
const int MinCode = 1;
const int MaxCode = 31;

int main()
{
	char InFile[] = "color.data";
 	char OutFile[] = "color.db";
	char inBuffer[80];
	char outBuffer[(MaxCode - MinCode + 1)*DataLen];
	char charCode[CodeLen + 1];
	int intCode;
	int numValid;
	int numInvalid;
	ifstream inputFile;
	ofstream outputFile;

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
	numValid = 0;
	numInvalid = 0;
	memset(outBuffer, ' ', sizeof(outBuffer));
	while(true)
          {
	     memset(inBuffer, ' ', sizeof(inBuffer));
	     inputFile.getline(inBuffer, sizeof(inBuffer));
	     if(inputFile.eof())
               break;
             strncpy(charCode, inBuffer, CodeLen);
             charCode[CodeLen] = '\0';
             intCode = atoi(charCode);
             if(intCode < MinCode || intCode > MaxCode)
              {
                 ++numInvalid;
                 continue;
               }
	       int copyLength = strlen(inBuffer) - CodeLen < DataLen ?
                                strlen(inBuffer) - CodeLen : DataLen;
		strncpy(outBuffer + ((intCode - MinCode)*DataLen), inBuffer + CodeLen, copyLength);
		++numValid;
	   } 
	outputFile.seekp(0);
	outputFile.write((char*) &numValid, sizeof(numValid));
	outputFile.seekp(DataLen);
 	outputFile.write(outBuffer, sizeof(outBuffer));

	inputFile.close();
	outputFile.close();

	cout << "Number of valid records: " << numValid << endl;
	cout << "Number of invalid records: " << numInvalid << endl;
	return 0;
}


