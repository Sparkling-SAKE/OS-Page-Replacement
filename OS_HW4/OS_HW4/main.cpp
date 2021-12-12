
#include "Optimal.h"
#include "LRU.h"

#include <iostream>

using namespace std;

int main()
{
	Optimal op;
	op.Run();
	cout << "Optimal Page Replacement : " << op.GetPageFault() << " page faults" << endl;

	LRU lru;
	lru.Run();
	cout << "LRU Page Replacement : " << lru.GetPageFault() << " page faults" << endl;

	return 0;
}