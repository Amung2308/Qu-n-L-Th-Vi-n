#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>
#include "GiaoDich.h"
class DynamicArray {
private:
    GiaoDich* data;
    int soLuong;   
    int sucChua;   
    void growIfNeeded();
public:
    DynamicArray() : data(nullptr), soLuong(0), sucChua(0) {}
    ~DynamicArray() { delete[] data; }
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;
    void pushBack(const GiaoDich& giaoDich);
    GiaoDich& at(int index);
    const GiaoDich& at(int index) const;
    int size() const { return soLuong; }
    bool empty() const { return soLuong == 0; }
};
