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
    NutAVL* gocAVL = NULL;
    NutBST* gocBST = NULL;
    NutBam* bangDocGia[SO_BUCKET];
    khoiTaoBam(bangDocGia);
    NutPhieu* dauPhieu = NULL;
    NutPhieu* cuoiPhieu = NULL;
    MangDong lichSuGiaoDich;
    khoiTaoMang(lichSuGiaoDich);
    DoThi doThiTheLoai;
    khoiTaoDoThi(doThiTheLoai);
    NutTrie* gocTrie = taoNutTrie();

    bool dangChay = true;
    while (dangChay) {
        int chucNangChinh = hienThiMenuChinh();
        switch (chucNangChinh) {
        case 1: {
            bool oLaiMenuSach = true;
            while (oLaiMenuSach) {
                int luaChon = hienThiMenuQuanLySach();
                if (luaChon == 0) { oLaiMenuSach = false; break; }
                if (luaChon == 1) {
                    Sach s;
                    cout << "Nhap ISBN: ";
                    cin >> s.isbn;
                    cin.ignore();
                    cout << "Nhap ten sach: ";
                    getline(cin, s.tenSach);
                    cout << "Nhap tac gia: ";
                    getline(cin, s.tacGia);
                    cout << "Nhap the loai: ";
                    getline(cin, s.theLoai);
                    cout << "Nhap nam xuat ban: ";
                    cin >> s.namXuatBan;
                    cout << "Nhap so luong: ";
                    cin >> s.soLuong;
                    cin.ignore();
                    gocBST = themBST(gocBST, s);
                    gocAVL = themAVL(gocAVL, s);
                    cout << "Da them sach vao BST va AVL.\n";
                }
                else if (luaChon == 4) {
                    string isbn;
                    cout << "Nhap ISBN can tim: ";
                    cin >> isbn;
                    NutAVL* ketqua = timAVL(gocAVL, isbn);
                    if (ketqua != NULL) {
                        cout << "\nKhong tim thay sach trong AVL.";
                    } else {
                        cout << "Da tim thay sach trong AVL: " << ketqua->thongTin.tenSach << endl;
                    }
                }
                else if (luaChon == 5) {
                    inThuTuAVL(gocAVL);
                }
                else if (luaChon == 6) {
                    inThuTuBST(gocBST);
                }
                else {
                    cout << "[Dang phat trien]\n";
                }
            }
            break;
        }
            case 2: {
                bool oLaiMenuDocGia = true;
                while (oLaiMenuDocGia) {
                    int luaChon = hienThiMenuQuanLyDocGia();
                    if (luaChon == 0) { oLaiMenuDocGia = false; break; }
                    cout << "[Dang phat trien]\n";
                }
                break;
            }
            case 3: {
                bool oLaiMenuMuonTra = true;
                while (oLaiMenuMuonTra) {
                    int luaChon = hienThiMenuMuonTra();
                    if (luaChon == 0) { oLaiMenuMuonTra = false; break; }
                    cout << "[Dang phat trien]\n";
                }
                break;
            }
            case 4: {
                bool oLaiMenuThongKe = true;
                while (oLaiMenuThongKe) {
                    int luaChon = hienThiMenuThongKe();
                    if (luaChon == 0) { oLaiMenuThongKe = false; break; }
                    cout << "[Dang phat trien]\n";
                }
                break;
            }
            case 5: {
                bool oLaiMenuGoiY = true;
                while (oLaiMenuGoiY) {
                    int luaChon = hienThiMenuGoiYTimKiem();
                    if (luaChon == 0) { oLaiMenuGoiY = false; break; }
                    cout << "[Dang phat trien]\n";
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
    giaiPhongAVL(gocAVL);
    giaiPhongBST(gocBST);
    giaiPhongBam(bangDocGia);
    giaiPhongDanhSachPhieu(dauPhieu);
    giaiPhongMang(lichSuGiaoDich);
    giaiPhongTrie(gocTrie);

    return 0;
}

