#include <iostream>
#include "Color.h"

using namespace std;

int main()
{
	Color * pColor = new Color;
	cout << "Color minCode: " << pColor->GetMinCode() << endl;
	cout << "Color maxCode: " << pColor->GetMaxCode() << endl;
	cout << "Color length: " << pColor->GetLength() << endl;
	cout << "Number of Colors: " << pColor->GetNumberOfColors() << endl;
 	cout.write(pColor->GetColors(), pColor->GetNumberOfColors()* pColor->GetLength());
	cout << endl;
	cout << pColor->GetColor(456) << endl;
	cout << pColor->GetColor(221) << endl;
	cout << pColor->GetColor(0) << endl;
	cout << pColor->GetColor(1) << endl;
	cout << pColor->GetColor(7) << endl;
	cout << pColor->GetColor(51) << endl;
	cout << pColor->GetColor(771) << endl;
	pColor->DisplayColors();
	delete pColor;
	return 0;
}

