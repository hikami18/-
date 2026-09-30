#pragma once

class DynamicArray
{
private:
    int* ptr;
    int size;

public:
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    void Input();
    void Output() const;

    int GetSize() const;
    int* GetPtr() const;

    void ReSize(int newSize);
    void Sort();
    int Search(int a) const;
    void Reverse();

    DynamicArray operator+(int n) const;
    DynamicArray operator-(int n) const;
    DynamicArray operator*(int n) const;
    DynamicArray operator+(const DynamicArray& b) const;

    DynamicArray& operator++();
    DynamicArray& operator--();

    DynamicArray& operator=(const DynamicArray& other);
};
