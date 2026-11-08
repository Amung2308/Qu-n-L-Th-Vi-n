// Noi dat cac unit test don gian (Tuan 9: "Kiem thu toan dien").
// Co the viet test bang assert() don gian, khong bat buoc dung framework ngoai
// (de dung voi yeu cau "khong dung CSDL / thu vien ngoai" cua de cuong).
//
// Vi du khung test cho sau nay:
//
// #include <cassert>
// #include "../include/AVLTree.h"
//
// void test_AVLTree_insert_search() {
//     AVLTree<int, int> cay;
//     cay.insert(5, 50);
//     int gt;
//     assert(cay.search(5, gt) == true);
//     assert(gt == 50);
// }
//
// int main() {
//     test_AVLTree_insert_search();
//     return 0;
// }
