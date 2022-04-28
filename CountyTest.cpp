#include <iostream>
#include "County.h"

using namespace std;

int main()
{
	County * pCounty = new County;
	cout << "County minCode: " << pCounty->GetMinCode() << endl;
	cout << "County maxCode: " << pCounty->GetMaxCode() << endl;
	cout << "County length: " << pCounty->GetLength() << endl;
	cout << "Number of Counties: " << pCounty->GetNumberOfCountys() << endl;
 	cout.write(pCounty->GetCountys(), pCounty->GetNumberOfCountys()* pCounty->GetLength());
	cout << endl;
	cout << pCounty->GetCounty(456) << endl;
	cout << pCounty->GetCounty(221) << endl;
	cout << pCounty->GetCounty(0) << endl;
	cout << pCounty->GetCounty(1) << endl;
	cout << pCounty->GetCounty(7) << endl;
	cout << pCounty->GetCounty(67) << endl;
	cout << pCounty->GetCounty(771) << endl;
	pCounty->DisplayCountys();
	delete pCounty;
	return 0;
}

