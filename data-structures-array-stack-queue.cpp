#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<> arr;
	arr.Add(1);
	arr.Add(1);
	arr.Add(1);
	arr.Print();
	Array<> arr2(arr);
	arr2.Print();
}
