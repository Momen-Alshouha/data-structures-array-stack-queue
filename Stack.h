#pragma once
#include "Array.h"

template<typename T>
class Stack
{
private:
	Array<T> stack;

public:

	size_t Size() {
		return stack.size;
	}

	T Top() {
		return stack.At(0);
	}

	T Bottom() {
		return stack.At(stack.size-1);
	}

	T Peek() {
		return Top()
	}

	void push(T value) {
		stack.InsertBegin(value);
	}

	void pop() {
		stack.RemoveAtIndex(0);
	}

	bool IsEmpty() {
		return this->IsEmpty();
	}

	void print() {
		cout << "Stack from top to bottom : ";
		stack.Print();
	}

};
