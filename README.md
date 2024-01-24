# Array, Stack, and Queue Implementation in C++

This repository contains C++ implementations of a dynamic array (`Array`), stack (`Stack`), and queue (`Queue`) using Object-Oriented Programming principles.

## Overview

### Classes
- **Array**: Represents a dynamic array and includes functionalities for insertion, removal, resizing, and more.
- **Stack**: Implements a basic stack using the `Array` class for storage.
- **Queue**: Implements a basic queue using the `Array` class for storage.

## Classes and Functionality

### Array Class (`Array.h`)
The `Array` class provides the following functionalities:
- Dynamic array implementation with insertion, removal, resizing, and other operations.
- Features a template type to store elements of any data type.
- Methods for accessing, inserting, and removing elements.
- Functionality to check if the array is empty, get its size and capacity, and more.

### Stack Class (`Stack.h`)
The `Stack` class utilizes the `Array` class for storage and implements the following stack operations:
- Push: Adds an element to the top of the stack.
- Pop: Removes the element from the top of the stack.
- Top: Retrieves the top element without removing it.
- Additional operations to get the size, check if the stack is empty, and print its elements.

### Queue Class (`Queue.h`)
The `Queue` class also uses the `Array` class for storage and provides basic queue operations:
- Enqueue: Adds an element to the back of the queue.
- Dequeue: Removes the front element from the queue.
- Front: Retrieves the front element without removing it.
- Additional operations for checking if the queue is empty, getting its size, and printing its elements.

## Usage

To use this implementation, follow these steps:
1. Clone the repository.
2. Include the necessary header files in your C++ code: `Array.h`, `Stack.h`, and `Queue.h`.
3. Create objects of `Array`, `Stack`, or `Queue` as needed and utilize their functionalities based on your requirements.

## Example

```cpp
#include "Array.h"
#include "Stack.h"
#include "Queue.h"

int main() {
    // Example usage of the Array class with integers
    Array<int> intArray;

    // Insert elements
    intArray.InsertEnd(10);
    intArray.InsertEnd(20);
    intArray.InsertEnd(30);

    // Print array
    cout << "Array (int): ";
    intArray.Print();

    // Access elements
    cout << "Element at index 1: " << intArray[1] << endl;

    // Other operations
    cout << "Array size: " << intArray.size << endl;
    cout << "Is array empty? " << (intArray.isEmpty() ? "Yes" : "No") << endl;

    // Example usage of the Stack class with strings
    Stack<string> strStack;

    // Push elements
    strStack.push("apple");
    strStack.push("banana");
    strStack.push("orange");

    // Print stack
    cout << "\nStack (string): ";
    strStack.print();

    // Pop element
    strStack.pop();

    // Peek at the top element
    cout << "Top element: " << strStack.Top() << endl;

    // Example usage of the Queue class with floats
    Queue<float> floatQueue;

    // Enqueue elements
    floatQueue.Enqueue(3.14f);
    floatQueue.Enqueue(2.5f);
    floatQueue.Enqueue(1.0f);

    // Print queue
    cout << "\nQueue (float): ";
    floatQueue.Print();

    // Dequeue element
    floatQueue.Dequeue();

    // Front element
    cout << "Front element: " << floatQueue.Front() << endl;

    return 0;
}
