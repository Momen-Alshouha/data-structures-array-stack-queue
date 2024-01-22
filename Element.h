#pragma once

template <typename T>
class Element
{
public:
    Element() {};
    Element(T data);

    T& GetDataValue() {
        return _data;
    }

    void SetDataValue(T& data) {
        _data = data;
    }

   __declspec(property(get = GetDataValue, put = SetDataValue)) T &data;

   friend std::ostream& operator<<(std::ostream& os,  Element<T>& element) // operator overloading
   {
       os << element.GetDataValue();
       return os;
   }

private:
    T _data;
};

template <typename T>
Element<T>::Element(T data) : _data(data) {};
