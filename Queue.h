#pragma once
#include "Array.h"

template<typename T>
class Queue {
private:
    Array<T> queue;

public:
    Queue() = default;

    explicit Queue(size_t initialCapacity) : queue(initialCapacity) {}
    
    void Enqueue(T value) {
        queue.InsertEnd(value);
    }

    void Dequeue() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        queue.RemoveAtIndex(0);
    }

    T Front() {
        if (IsEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return queue[0];
    }

    bool IsEmpty() {
        return queue.isEmpty();
    }

    size_t Size() {
        return queue.GetSize();
    }

    size_t Capacity() {
        return queue.GetCapacity();
    }

    void Clear() {
        queue.Clear();
    }

    void Print() {
        cout << "Queue from front to back: ";
        queue.Print();
    }
};
