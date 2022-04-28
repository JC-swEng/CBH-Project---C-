#include <iostream>
#include "Vmake.h"

using namespace std;

int main()
{
	Vmake * pVmake = new Vmake;
	cout << "Vmake minCode: " << pVmake->GetMinCode() << endl;
	cout << "Vmake maxCode: " << pVmake->GetMaxCode() << endl;
	cout << "Vmake length: " << pVmake->GetLength() << endl;
	cout << "Number of Vehicle Makes: " << pVmake->GetNumberOfVmakes() << endl;
 	cout.write(pVmake->GetVmakes(), pVmake->GetNumberOfVmakes()* pVmake->GetLength());
	cout << endl;
	cout << pVmake->GetVmake(456) << endl;
	cout << pVmake->GetVmake(221) << endl;
	cout << pVmake->GetVmake(0) << endl;
	cout << pVmake->GetVmake(1) << endl;
	cout << pVmake->GetVmake(7) << endl;
	cout << pVmake->GetVmake(51) << endl;
	cout << pVmake->GetVmake(771) << endl;
	pVmake->DisplayVmakes();
	delete pVmake;
	return 0;
}

