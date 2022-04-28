#include <string>

using namespace std;

string Trim(string aString)
{
  int i;
  for(i = aString.size(); i > 0; --i)
  {
    if(aString[i-1] != ' ' && aString[i-1] != '\n')
      break;
  }
  aString.resize(i);
  return aString;
}
