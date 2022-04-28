#include <iostream>
#include "Vtype.h"

using namespace std;

int main()
{
	Vtype * pVtype = new Vtype;
	cout << "Vtype minCode: " << pVtype->GetMinCode() << endl;
	cout << "Vtype maxCode: " << pVtype->GetMaxCode() << endl;
	cout << "Vtype length: " << pVtype->GetLength() << endl;
	cout << "Number of Vehicle Types: " << pVtype->GetNumberOfVtypes() << endl;
 	cout.write(pVtype->GetVtypes(), pVtype->GetNumberOfVtypes()* pVtype->GetLength());
	cout << endl;
	cout << pVtype->GetVtype(456) << endl;
	cout << pVtype->GetVtype(221) << endl;
	cout << pVtype->GetVtype(0) << endl;
	cout << pVtype->GetVtype(1) << endl;
	cout << pVtype->GetVtype(7) << endl;
	cout << pVtype->GetVtype(15) << endl;
	cout << pVtype->GetVtype(771) << endl;
	pVtype->DisplayVtypes();
	delete pVtype;
	return 0;
}

