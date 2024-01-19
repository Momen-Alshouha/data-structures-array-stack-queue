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
	Array<> arr2(arr);
	arr2.Print();
}
