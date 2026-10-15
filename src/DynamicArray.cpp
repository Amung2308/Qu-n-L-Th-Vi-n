#include "DynamicArray.h"

void DynamicArray::growIfNeeded() {
    // TODO (Tuan 5): khi soLuong == sucChua, cap phat mang moi kich thuoc gap doi
    // (hoac vai phan tu ban dau neu sucChua == 0), sao chep du lieu cu sang mang
    // moi, roi giai phong mang cu (delete[] mang cu).
}

void DynamicArray::pushBack(const GiaoDich& giaoDich) {
    // TODO (Tuan 5): goi growIfNeeded() truoc, roi gan data[soLuong] = giaoDich;
    // soLuong++;
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
