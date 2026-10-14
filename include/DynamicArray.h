#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <cstddef>
#include <stdexcept>

// Mang dong (danh sach dac) tu cai dat - KHONG dung std::vector o day,
// vi day chinh la CTDL bat buoc can tu lam (muc 4, dong 5: luu lich su giao dich).
// std::vector van duoc dung o CAC CTDL KHAC (AVL/BST/HashTable/Graph/Trie) de tra ve
// ket qua duyet - chi rieng lop nay la phai tu cai dat co che cap phat/mo rong mang.
template <typename T>
class DynamicArray {
private:
    T* data;
    int soLuong;   // so phan tu dang co
    int sucChua;   // dung luong da cap phat

    void growIfNeeded();

public:
    DynamicArray() : data(nullptr), soLuong(0), sucChua(0) {}
    ~DynamicArray() { delete[] data; }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void pushBack(const T& value);
    T& at(int index);
    const T& at(int index) const;
    int size() const { return soLuong; }
    bool empty() const { return soLuong == 0; }
};

template <typename T>
void DynamicArray<T>::growIfNeeded() {
    // TODO (Tuan 5): khi soLuong == sucChua, cap phat mang moi kich thuoc gap doi
    // (hoac sucChua == 0 thi cap phat vai phan tu ban dau), sao chep du lieu cu sang,
    // roi giai phong mang cu.
}

template <typename T>
void DynamicArray<T>::pushBack(const T& value) {
    // TODO (Tuan 5): goi growIfNeeded() truoc, roi gan data[soLuong] = value; soLuong++;
    (void)value;
}

template <typename T>
T& DynamicArray<T>::at(int index) {
    if (index < 0 || index >= soLuong) {
        throw std::out_of_range("DynamicArray::at - chi so ngoai pham vi");
    }
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::at(int index) const {
    if (index < 0 || index >= soLuong) {
        throw std::out_of_range("DynamicArray::at - chi so ngoai pham vi");
    }
    return data[index];
}

#endif // DYNAMICARRAY_H
