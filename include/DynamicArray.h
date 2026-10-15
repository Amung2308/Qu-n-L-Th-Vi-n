#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>
#include "GiaoDich.h"

// Mang dong (danh sach dac) tu cai dat - KHONG dung std::vector o day, vi day
// chinh la CTDL bat buoc can tu lam (muc 4, dong 5: luu lich su giao dich).
class DynamicArray {
private:
    GiaoDich* data;
    int soLuong;   // so phan tu dang co
    int sucChua;   // dung luong da cap phat

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

#endif // DYNAMICARRAY_H
