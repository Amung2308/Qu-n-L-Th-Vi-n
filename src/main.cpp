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
const int SO_LUONG_TOI_DA = 1000;
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
    Sach dsSachNap[SO_LUONG_TOI_DA];
    int soLuongSachNap = 0;
    if (docDanhSachSach("data/sach.dat", dsSachNap, soLuongSachNap, SO_LUONG_TOI_DA)) {
        for (int i = 0; i < soLuongSachNap; i++) {
            gocAVL = themAVL(gocAVL, dsSachNap[i]);
            gocBST = themBST(gocBST, dsSachNap[i]);
        }
        cout << "Da nap " << soLuongSachNap << " sach tu file.\n";
    }

    DocGia dsDocGiaNap[SO_LUONG_TOI_DA];
    int soLuongDocGiaNap = 0;
    if (docDanhSachDocGia("data/docgia.dat", dsDocGiaNap, soLuongDocGiaNap, SO_LUONG_TOI_DA)) {
        for (int i = 0; i < soLuongDocGiaNap; i++) {
            themBam(bangDocGia, dsDocGiaNap[i]);
        }
        cout << "Da nap " << soLuongDocGiaNap << " doc gia tu file.\n";
    }
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
                    cout << "\nDa them sach ";
                }
                else if (luaChon == 4) {
                    string isbn;
                    cout << "Nhap ISBN can tim: ";
                    cin >> isbn;
                    NutAVL* ketqua = timAVL(gocAVL, isbn);
                    if (ketqua == NULL) {
                        cout << "\nKhong tim thay sach ";
                    }
                    else {
                        cout << "\nDa tim thay sach: " << ketqua->thongTin.tenSach << endl;
                    }
                }
                else if (luaChon == 5) {
                    inThuTuAVL(gocAVL);
                }
                else if (luaChon == 6) {
                    inThuTuBST(gocBST);
                }
                else {
                    cout << "\n[Dang phat trien]";
                }
            }
            break;
        }
        case 2: {
            bool oLaiMenuDocGia = true;
            while (oLaiMenuDocGia) {
                int luaChon = hienThiMenuQuanLyDocGia();
                if (luaChon == 0) { oLaiMenuDocGia = false; break; }
                if (luaChon == 1) {
                    DocGia dg;
                    cout << "Nhap CMND: ";
                    cin >> dg.cmnd;
                    cin.ignore();
                    cout << "Nhap ho ten: ";
                    getline(cin, dg.hoTen);
                    cout << "Nhap email: ";
                    getline(cin, dg.email);
                    cout << "Nhap SDT: ";
                    getline(cin, dg.sdt);
                    cout << "Nhap loai the (0=Sinh vien, 1=Giang vien, 2=VIP): ";
                    int loai;
                    cin >> loai;
                    cin.ignore();
                    dg.loaiThe = (LoaiThe)loai;
                    themBam(bangDocGia, dg);
                    cout << "\nDa them doc gia ";
                }
                else if (luaChon == 2) {
                    string cmndCanXoa;
                    cout << "Nhap CMND can xoa: ";
                    cin >> cmndCanXoa;
                    if (xoaBam(bangDocGia, cmndCanXoa)) cout << "\nDa xoa ";
                    else cout << "\nKhong tim thay CMND nay ";
                }
                else if (luaChon == 4) {
                    string cmndCanTim;
                    cout << "Nhap CMND can tim: ";
                    cin >> cmndCanTim;
                    DocGia ketQua;
                    if (timBam(bangDocGia, cmndCanTim, ketQua)) {
                        cout << "Tim thay: " << ketQua.cmnd << " - " << ketQua.hoTen << " - " << ketQua.email << "\n";
                    }
                    else {
                        cout << "\nKhong tim thay doc gia co CMND nay ";
                    }
                }
                else {
                    cout << "\n[Dang phat trien]";
                }
            }
            break;
        }
            case 3: {
                bool oLaiMenuMuonTra = true;
                while (oLaiMenuMuonTra) {
                    int luaChon = hienThiMenuMuonTra();
                    if (luaChon == 0) { oLaiMenuMuonTra = false; break; }
                    cout << "\n[Dang phat trien]";
                }
                break;
            }
            case 4: {
                bool oLaiMenuThongKe = true;
                while (oLaiMenuThongKe) {
                    int luaChon = hienThiMenuThongKe();
                    if (luaChon == 0) { oLaiMenuThongKe = false; break; }
                    cout << "\n[Dang phat trien]";
                }
                break;
            }
            case 5: {
                bool oLaiMenuGoiY = true;
                while (oLaiMenuGoiY) {
                    int luaChon = hienThiMenuGoiYTimKiem();
                    if (luaChon == 0) { oLaiMenuGoiY = false; break; }
                    cout << "\n[Dang phat trien]";
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
        Sach dsSachLuu[SO_LUONG_TOI_DA];
        int soLuongSachLuu = 0;
        layTatCaSachAVL(gocAVL, dsSachLuu, soLuongSachLuu);
        ghiDanhSachSach("data/sach.dat", dsSachLuu, soLuongSachLuu);

        DocGia dsDocGiaLuu[SO_LUONG_TOI_DA];
        int soLuongDocGiaLuu = 0;
        layTatCaDocGiaBam(bangDocGia, dsDocGiaLuu, soLuongDocGiaLuu);
        ghiDanhSachDocGia("data/docgia.dat", dsDocGiaLuu, soLuongDocGiaLuu);

        cout << "Da luu " << soLuongSachLuu << " sach va " << soLuongDocGiaLuu << " doc gia ra file.\n";
    }

    giaiPhongAVL(gocAVL);
    giaiPhongBST(gocBST);
    giaiPhongBam(bangDocGia);
    giaiPhongDanhSachPhieu(dauPhieu);
    giaiPhongMang(lichSuGiaoDich);
    giaiPhongTrie(gocTrie);

    return 0;
}

