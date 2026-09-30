#include <iostream>
#include <algorithm>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray()
{
    ptr = nullptr;
    size = 0;
}

DynamicArray::DynamicArray(int size)
{
    this->size = size;
    if (size > 0)
    {
        ptr = new int[size]();
    }
    else
    {
        ptr = nullptr;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    size = other.size;
    if (size > 0)
    {
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }
    else
    {
        ptr = nullptr;
    }
}

DynamicArray::~DynamicArray()
{
    delete[] ptr;
}

void DynamicArray::Input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}

void DynamicArray::Output() const
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl;
}

int DynamicArray::GetSize() const
{
    return size;
}

int* DynamicArray::GetPtr() const
{
    return ptr;
}

void DynamicArray::ReSize(int newSize)
{
    if (newSize <= 0)
    {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
        return;
    }

    int* temp = new int[newSize]();
    int minSize = (newSize < size) ? newSize : size;

    for (int i = 0; i < minSize; i++)
    {
        temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
    size = newSize;
}

void DynamicArray::Sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }
}

int DynamicArray::Search(int a) const
{
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == a)
        {
            return i;
        }
    }
    return -1;
}

void DynamicArray::Reverse()
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(ptr[i], ptr[size - 1 - i]);
    }
}

DynamicArray DynamicArray::operator+(int n) const
{
    DynamicArray temp(size + n);
    for (int i = 0; i < size; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    return temp;
}

DynamicArray DynamicArray::operator-(int n) const
{
    if (size <= n)
    {
        return *this;
    }

    DynamicArray temp(size - n);
    for (int i = 0; i < temp.size; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    return temp;
}

DynamicArray DynamicArray::operator*(int n) const
{
    DynamicArray temp(size);
    for (int i = 0; i < size; i++)
    {
        temp.ptr[i] = ptr[i] * n;
    }
    return temp;
}

DynamicArray DynamicArray::operator+(const DynamicArray& b) const
{
    DynamicArray temp(size + b.size);
    for (int i = 0; i < size; i++)
    {
        temp.ptr[i] = ptr[i];
    }
    for (int i = 0; i < b.size; i++)
    {
        temp.ptr[size + i] = b.ptr[i];
    }
    return temp;
}

DynamicArray& DynamicArray::operator++()
{
    ReSize(size + 1);
    return *this;
}

DynamicArray& DynamicArray::operator--()
{
    if (size > 0)
    {
        ReSize(size - 1);
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] ptr;
    size = other.size;

    if (size > 0)
    {
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }
    else
    {
        ptr = nullptr;
    }

    return *this;
}
