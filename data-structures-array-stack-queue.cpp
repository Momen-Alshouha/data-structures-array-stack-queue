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
