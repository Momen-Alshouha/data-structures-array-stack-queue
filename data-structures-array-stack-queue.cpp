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
	cout <<"Size : " << arr.size << endl;
	cout << "Capacity : " << arr.capacity << endl;

	Array<> arr2(arr);
	arr2.Print();
	
	Array<> arr3 = arr2;
	arr3.Print();

	cout << "Element At index 0 : " << arr[0] << endl;
	arr.InsertAtIndex(1, 99);
	cout << arr.size << endl;
	cout << arr.capacity<< endl;
	arr.Shrink();
	cout << arr.capacity << endl;
	arr.Print();
	cout << "After remove element : " << endl;
	arr.RemoveAtIndex(2);
	arr.Print();
	cout << arr.size << endl;
	cout << "\n----------------------------------\n\n";
	Array<string> names;

	names.InsertBegin("Ahmad");
	names.InsertBegin("samer");
	names.InsertBegin("rami");
	names.InsertBegin("nader");

	names.Print();
	names.Reverse();
	names.Print();
}
