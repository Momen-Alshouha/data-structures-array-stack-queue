#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<> arr;
	arr.InsertBegin(1);
	arr.InsertBegin(2);
	arr.InsertBegin(3);
	arr.Print();
	cout << arr.size << endl;
	cout << arr.capacity<< endl;
}
