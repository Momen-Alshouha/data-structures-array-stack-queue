#pragma once
#include "Element.h"
#include <iostream>
using namespace std;

template<typename T = int>
class Array
{
public:
    static const size_t DEFAULT_CAPACITY = 10;

    Array() : _ptrToFirstElement(new Element<T>[DEFAULT_CAPACITY]), _currentSize(0), _capacity(DEFAULT_CAPACITY) { }

    Array(size_t initialCapacity) : _ptrToFirstElement(new Element<T>[initialCapacity]), _currentSize(0), _capacity(initialCapacity) { }

    Array(const Array& source) : _ptrToFirstElement(new Element<T>[source._capacity]), _currentSize(source._currentSize), _capacity(source._capacity)
    {
        for (size_t i = 0; i < _currentSize; ++i)
        {
            _ptrToFirstElement[i] = source._ptrToFirstElement[i];
        }
    }

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

    void Add(T data)
    {
        _ptrToFirstElement[_currentSize].SetDataValue(data);
        ++_currentSize;
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


private:
    Element<T>* _ptrToFirstElement;
    size_t _currentSize;
    size_t _capacity;

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
