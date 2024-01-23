#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main()
{
	Stack<int> stack(100);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);

	cout << stack.Capacity() << endl;

}
