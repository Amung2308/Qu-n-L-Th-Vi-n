#include <iostream>
#include "Sach.h"
#include "DocGia.h"
#include "PhieuMuon.h"
#include "GiaoDich.h"
#include "AVLTree.h"
#include "BSTree.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Graph.h"
#include "Trie.h"
#include "FileManager.h"
#include "Menu.h"

using namespace std;

int main() {
   
    AVLTree quanLySachTheoISBN;     
    BSTree danhMucSachTheoTen;      
    HashTable quanLyDocGia;         
    LinkedList danhSachPhieuMuon;   
    DynamicArray lichSuGiaoDich;    
    Graph doThiTheLoai;             
    Trie trieTenSach;  
    bool dangChay = true;
    while (dangChay) {
        int chucNangChinh = Menu::hienThiMenuChinh();
        switch (chucNangChinh) {
            case 1: {
                bool oLaiMenuSach = true;
                while (oLaiMenuSach) {
                    int luaChon = Menu::hienThiMenuQuanLySach();
                    if (luaChon == 0) { oLaiMenuSach = false; break; }
                    cout << "[Dang phat trien - se cai dat tu Tuan 3]\n";
                }
                break;
            }
            case 2: {
                bool oLaiMenuDocGia = true;
                while (oLaiMenuDocGia) {
                    int luaChon = Menu::hienThiMenuQuanLyDocGia();
                    if (luaChon == 0) { oLaiMenuDocGia = false; break; }
                    cout << "[Dang phat trien - se cai dat tu Tuan 4]\n";
                }
                break;
            }
            case 3: {
                bool oLaiMenuMuonTra = true;
                while (oLaiMenuMuonTra) {
                    int luaChon = Menu::hienThiMenuMuonTra();
                    if (luaChon == 0) { oLaiMenuMuonTra = false; break; }
                    cout << "[Dang phat trien - se cai dat tu Tuan 5]\n";
                }
                break;
            }
            case 4: {
                bool oLaiMenuThongKe = true;
                while (oLaiMenuThongKe) {
                    int luaChon = Menu::hienThiMenuThongKe();
                    if (luaChon == 0) { oLaiMenuThongKe = false; break; }
                    cout << "[Dang phat trien - se cai dat tu Tuan 7]\n";
                }
                break;
            }
            case 5: {
                bool oLaiMenuGoiY = true;
                while (oLaiMenuGoiY) {
                    int luaChon = Menu::hienThiMenuGoiYTimKiem();
                    if (luaChon == 0) { oLaiMenuGoiY = false; break; }
                    cout << "[Dang phat trien - se cai dat tu Tuan 7-8]\n";
                }
                break;
            }
            case 0:
                dangChay = false;
                cout << "\nCam on da su dung chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le, vui long thu lai.\n";
                break;
        }
    }
    return 0;
}
