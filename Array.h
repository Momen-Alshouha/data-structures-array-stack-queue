#pragma once
#include "Element.h"
#include <iostream>
using namespace std;

template<typename T = int>
class Array
{
public:
    static const size_t DEFAULT_CAPACITY = 10;

    // consrtuctor with edfault capacity
    Array() : _ptrToFirstElement(new Element<T>[DEFAULT_CAPACITY]), _currentSize(0), _capacity(DEFAULT_CAPACITY) { }

    // constructor as initial capacity
    Array(size_t initialCapacity) : _ptrToFirstElement(new Element<T>[initialCapacity]), _currentSize(0), _capacity(initialCapacity) { }

    // copy constructor
    Array(const Array& source) : _ptrToFirstElement(new Element<T>[source._capacity]), _currentSize(source._currentSize), _capacity(source._capacity)
    {
        for (size_t i = 0; i < _currentSize; ++i)
        {
            _ptrToFirstElement[i] = source._ptrToFirstElement[i];
        }
    }

    // copy assignment operator overload
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _ptrToFirstElement;
            _currentSize = other._currentSize;
            _capacity = other._capacity;
            _ptrToFirstElement = new Element<T>[_capacity];

            for (size_t i = 0; i < _currentSize; ++i)
            {
                _ptrToFirstElement[i] = other._ptrToFirstElement[i];
            }
        }
        return *this;
    }

    
    /*
    * move constructor
    * This is the move constructor. It is used when you want to transfer the resources
    * (ownership of the dynamically allocated array in this case) from one object to another 
    */

    Array(Array&& other) noexcept : _ptrToFirstElement(other._ptrToFirstElement), _currentSize(other._currentSize), _capacity(other._capacity)
    {
        other._ptrToFirstElement = nullptr;
        other._currentSize = 0;
        other._capacity = 0;
    }

    Array& operator=(Array&& other) noexcept
    {
        if (this != &other)
        {
            delete[] _ptrToFirstElement;
            _ptrToFirstElement = other._ptrToFirstElement;
            _currentSize = other._currentSize;
            _capacity = other._capacity;

            other._ptrToFirstElement = nullptr;
            other._currentSize = 0;
            other._capacity = 0;
        }
        return *this;
    }

    // Access an element using the subscript operator []
    T& operator[](size_t index) {
        if (index >= _currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return _ptrToFirstElement[index].data;
    }

    // Access an element using the subscript operator [] (const version for read-only access)
    const T operator[](size_t index) const {
        if (index >= _currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return _ptrToFirstElement[index].data;
    }

    bool IsExist(T value) {
        for (size_t i = 0; i < _currentSize; i++)
        {
            if (_ptrToFirstElement[i].data == value)
            {
                return true;
            }
        }
        return false;
    }

    T At(size_t index) {
        if (index>=_currentSize)
        {
            throw out_of_range("Index out of range");
        }
        return _ptrToFirstElement[index].data;
    }

    bool isEmpty() {
        return (_currentSize == 0);
    }

    void RemoveDuplicates() {
        if (!isEmpty() && _currentSize>1)
        {
            Array temp;
            for (size_t i = 0; i < _currentSize; i++)
            {
                if (!temp.IsExist(_ptrToFirstElement[i].data))
                {
                    temp.InsertEnd(_ptrToFirstElement[i].data);
                }
            }
            *this = temp;
        }
    }

    void InsertEnd(T data)
    {
        _ptrToFirstElement[_currentSize].data = data;
        ++_currentSize;
    }

    void InsertBegin(T data)
    {
        if (_currentSize >= _capacity)
        {
            Resize(_capacity * 2);
        }

        // Shift existing elements to make place for the new element at the beginning
        for (size_t i = _currentSize; i > 0; --i)
        {
            _ptrToFirstElement[i] = _ptrToFirstElement[i - 1];
        }

        // Insert the new element at the beginning
        _ptrToFirstElement[0].data = data;
        ++_currentSize;
    }

    void InsertAtIndex(short index, T value) {
        if (index < 0 || index > _currentSize) {
            throw std::out_of_range("Index out of range");
        }

        if (_currentSize >= _capacity) {
            Resize(_capacity + 2);
        }

        Array temp = *this;
        short counter = 0;
        for (size_t i = 0; i <= _currentSize; ++i) {
            if (i == index) {
                _ptrToFirstElement[i] = value;
                continue;
            }
            _ptrToFirstElement[i] = temp[counter];
            counter++;
        }

        // Insert at the end if the index is equal to the current size
        if (index == _currentSize) {
            _ptrToFirstElement[_currentSize] = value;
        }

        // Increase the current size
        ++_currentSize;
    }

    void RemoveAtIndex(size_t index) {
        if (index >= _currentSize) {
            throw std::out_of_range("Index out of range");
        }

        // Move elements after the removed index one position to the left
        for (size_t i = index; i < _currentSize - 1; ++i) {
            _ptrToFirstElement[i].data = _ptrToFirstElement[i + 1].data;
        }

        --_currentSize;
    }

    void Reverse() {
        for (size_t i = 0; i < _currentSize/2; i++)
        {
            // swaps each element with its corresponding element in the second half
            T temp = _ptrToFirstElement[i].data; 
            _ptrToFirstElement[i].data = _ptrToFirstElement[_currentSize -1 - i].data;
            _ptrToFirstElement[_currentSize -1- i].data = temp;
        }
    }

    void Shrink() {
        //  reduce the capacity of the array to fit its current size.
        _capacity = _currentSize;
    }

    void Print() const
    {
        for (size_t i = 0; i < _currentSize; ++i)
        {
            cout << _ptrToFirstElement[i].GetDataValue() << " ";
        }
        cout << endl;
    }

    // Destructor to release memory
    ~Array()
    {
        delete[] _ptrToFirstElement;
    }

    size_t GetCapacity() {
        return _capacity;
    }

    size_t GetSize() {
        return _currentSize;
    }

    __declspec(property(get = GetCapacity)) size_t capacity;
    __declspec(property(get = GetSize)) size_t size;

private:
    Element<T>* _ptrToFirstElement;
    size_t _currentSize;
    size_t _capacity; // capacity refers to the maximum number of elements that the array can **currently** hold.

    void Resize(size_t newCapacity)
    {
        Element<T>* newPtr = new Element<T>[newCapacity];
        for (size_t i = 0; i < _currentSize; ++i)
        {
            newPtr[i] = _ptrToFirstElement[i];
        }
        delete[] _ptrToFirstElement;
        _ptrToFirstElement = newPtr;
        _capacity = newCapacity;
    }
};
