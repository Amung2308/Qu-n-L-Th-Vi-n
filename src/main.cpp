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
    // --- Khoi tao cac CTDL chinh cua chuong trinh ---
    AVLTree quanLySachTheoISBN;     // muc 4, dong 1
    BSTree danhMucSachTheoTen;      // muc 4, dong 2
    HashTable quanLyDocGia;         // muc 4, dong 3
    LinkedList danhSachPhieuMuon;   // muc 4, dong 4
    DynamicArray lichSuGiaoDich;    // muc 4, dong 5
    Graph doThiTheLoai;             // muc 4, dong 6
    Trie trieTenSach;               // muc 5 - CTDL tu tim hieu

    // TODO (Tuan 5): nap du lieu tu file khi khoi dong, vd:
    // vector<Sach> dsSach;
    // FileManager::docDanhSachSach("data/sach.dat", dsSach);
    // for (const auto& s : dsSach) quanLySachTheoISBN.insert(s);

    bool dangChay = true;
    while (dangChay) {
        int chucNangChinh = Menu::hienThiMenuChinh();
        switch (chucNangChinh) {
            case 1: {
                bool oLaiMenuSach = true;
                while (oLaiMenuSach) {
                    int luaChon = Menu::hienThiMenuQuanLySach();
                    if (luaChon == 0) { oLaiMenuSach = false; break; }
                    // TODO (Tuan 3+): goi quanLySachTheoISBN / danhMucSachTheoTen /
                    // trieTenSach tuong ung voi tung lua chon.
                    cout << "[Dang phat trien - se cai dat tu Tuan 3]\n";
                }
                break;
            }
            case 2: {
                bool oLaiMenuDocGia = true;
                while (oLaiMenuDocGia) {
                    int luaChon = Menu::hienThiMenuQuanLyDocGia();
                    if (luaChon == 0) { oLaiMenuDocGia = false; break; }
                    // TODO (Tuan 4+): goi quanLyDocGia tuong ung.
                    cout << "[Dang phat trien - se cai dat tu Tuan 4]\n";
                }
                break;
            }
            case 3: {
                bool oLaiMenuMuonTra = true;
                while (oLaiMenuMuonTra) {
                    int luaChon = Menu::hienThiMenuMuonTra();
                    if (luaChon == 0) { oLaiMenuMuonTra = false; break; }
                    // TODO (Tuan 5-6): goi danhSachPhieuMuon, kiem tra rang buoc, tinh phat.
                    cout << "[Dang phat trien - se cai dat tu Tuan 5]\n";
                }
                break;
            }
            case 4: {
                bool oLaiMenuThongKe = true;
                while (oLaiMenuThongKe) {
                    int luaChon = Menu::hienThiMenuThongKe();
                    if (luaChon == 0) { oLaiMenuThongKe = false; break; }
                    // TODO (Tuan 7+): goi lichSuGiaoDich / danhSachPhieuMuon de thong ke.
                    cout << "[Dang phat trien - se cai dat tu Tuan 7]\n";
                }
                break;
            }
            case 5: {
                bool oLaiMenuGoiY = true;
                while (oLaiMenuGoiY) {
                    int luaChon = Menu::hienThiMenuGoiYTimKiem();
                    if (luaChon == 0) { oLaiMenuGoiY = false; break; }
                    // TODO (Tuan 7-8): goi doThiTheLoai.bfs()/dfs() va trieTenSach.goiYTheoTienTo().
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

    // TODO (Tuan 5): ghi du lieu ra file truoc khi thoat, vd:
    // FileManager::ghiDanhSachSach("data/sach.dat", <danh sach sach hien tai>);

    return 0;
}
