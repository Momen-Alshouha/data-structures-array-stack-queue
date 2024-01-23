#pragma once
#include "Array.h"

template<typename T>
class Stack
{
private:
	Array<T> stack;

public:

	Stack() = default;

	Stack(size_t initialCapacity) : stack(initialCapacity) {}

	size_t Size() {
		return stack.size;
	}

	T Top() {
		if (IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		return stack.At(0);
	}

	T Bottom() {
		if (IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		return stack.At(stack.size-1);
	}

	T Peek() {
		return Top();
	}

	void push(T value) {
		if (IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		stack.InsertBegin(value);
	}

	void pop() {
		if (IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		stack.RemoveAtIndex(0);
	}

	bool IsEmpty() {
		return this->IsEmpty();
	}

	size_t Capacity() {
		return stack.capacity;
	}

	void print() {
		cout << "Stack from top to bottom : ";
		stack.Print();
	}

};
