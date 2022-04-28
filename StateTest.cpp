#include <iostream>
#include "State.h"

using namespace std;

int main()
{
	State * pState = new State;
	cout << "State minCode: " << pState->GetMinCode() << endl;
	cout << "State maxCode: " << pState->GetMaxCode() << endl;
	cout << "State length: " << pState->GetLength() << endl;
	cout << "Number of States: " << pState->GetNumberOfStates() << endl;
 	cout.write(pState->GetStates(), pState->GetNumberOfStates()* pState->GetLength());
	cout << endl;
	cout << pState->GetState(456) << endl;
	cout << pState->GetState(221) << endl;
	cout << pState->GetState(0) << endl;
	cout << pState->GetState(1) << endl;
	cout << pState->GetState(7) << endl;
	cout << pState->GetState(51) << endl;
	cout << pState->GetState(771) << endl;
	pState->DisplayStates();
	delete pState;
	return 0;
}

