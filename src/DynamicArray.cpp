#include "DynamicArray.h"

void DynamicArray::growIfNeeded() {
    
}

void DynamicArray::pushBack(const GiaoDich& giaoDich) {
    
    (void)giaoDich;
}

GiaoDich& DynamicArray::at(int index) {
    if (index < 0 || index >= soLuong) {
        throw std::out_of_range("DynamicArray::at - chi so ngoai pham vi");
    }
    return data[index];
}

const GiaoDich& DynamicArray::at(int index) const {
    if (index < 0 || index >= soLuong) {
        throw std::out_of_range("DynamicArray::at - chi so ngoai pham vi");
    }
    return data[index];
}
