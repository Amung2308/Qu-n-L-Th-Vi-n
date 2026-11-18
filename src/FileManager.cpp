#include "FileManager.h"
#include <fstream>
using namespace std;

void ghiChuoi(ofstream& f, string s) {
    int doDai = (int)s.length();
    f.write((char*)&doDai, sizeof(int));
    f.write(s.c_str(), doDai);
}

string docChuoi(ifstream& f) {
    int doDai;
    f.read((char*)&doDai, sizeof(int));
    char* buf = new char[doDai + 1];
    f.read(buf, doDai);
    buf[doDai] = '\0';
    string ketQua = buf;
    delete[] buf;
    return ketQua;
}

void ghiMotSach(ofstream& f, Sach s) {
    ghiChuoi(f, s.isbn);
    ghiChuoi(f, s.tenSach);
    ghiChuoi(f, s.tacGia);
    ghiChuoi(f, s.theLoai);
    f.write((char*)&s.namXuatBan, sizeof(int));
    f.write((char*)&s.soLuong, sizeof(int));
}

Sach docMotSach(ifstream& f) {
    Sach s;
    s.isbn = docChuoi(f);
    s.tenSach = docChuoi(f);
    s.tacGia = docChuoi(f);
    s.theLoai = docChuoi(f);
    f.read((char*)&s.namXuatBan, sizeof(int));
    f.read((char*)&s.soLuong, sizeof(int));
    return s;
}

void ghiMotDocGia(ofstream& f, DocGia d) {
    ghiChuoi(f, d.cmnd);
    ghiChuoi(f, d.hoTen);
    ghiChuoi(f, d.email);
    ghiChuoi(f, d.sdt);
    int loai = (int)d.loaiThe;
    f.write((char*)&loai, sizeof(int));
}

DocGia docMotDocGia(ifstream& f) {
    DocGia d;
    d.cmnd = docChuoi(f);
    d.hoTen = docChuoi(f);
    d.email = docChuoi(f);
    d.sdt = docChuoi(f);
    int loai;
    f.read((char*)&loai, sizeof(int));
    d.loaiThe = (LoaiThe)loai;
    return d;
}

void ghiMotPhieu(ofstream& f, PhieuMuon p) {
    ghiChuoi(f, p.maPhieu);
    ghiChuoi(f, p.cmndDocGia);
    ghiChuoi(f, p.isbnSach);
    ghiChuoi(f, p.ngayMuon);
    ghiChuoi(f, p.ngayHenTra);
    ghiChuoi(f, p.ngayTra);
    int trangThai = (int)p.trangThai;
    f.write((char*)&trangThai, sizeof(int));
    f.write((char*)&p.tienPhat, sizeof(double));
}

PhieuMuon docMotPhieu(ifstream& f) {
    PhieuMuon p;
    p.maPhieu = docChuoi(f);
    p.cmndDocGia = docChuoi(f);
    p.isbnSach = docChuoi(f);
    p.ngayMuon = docChuoi(f);
    p.ngayHenTra = docChuoi(f);
    p.ngayTra = docChuoi(f);
    int trangThai;
    f.read((char*)&trangThai, sizeof(int));
    p.trangThai = (TrangThaiMuon)trangThai;
    f.read((char*)&p.tienPhat, sizeof(double));
    return p;
}

bool docDanhSachSach(string duongDan, Sach ds[], int& soLuong, int soLuongToiDa) {
    ifstream f(duongDan.c_str(), ios::binary);
    if (!f.is_open()) return false;
    f.read((char*)&soLuong, sizeof(int));
    if (soLuong > soLuongToiDa) soLuong = soLuongToiDa;
    for (int i = 0; i < soLuong; i++) {
        ds[i] = docMotSach(f);
    }
    return true;
}

bool ghiDanhSachSach(string duongDan, Sach ds[], int soLuong) {
    ofstream f(duongDan.c_str(), ios::binary);
    if (!f.is_open()) return false;
    f.write((char*)&soLuong, sizeof(int));
    for (int i = 0; i < soLuong; i++) {
        ghiMotSach(f, ds[i]);
    }
    return true;
}

bool docDanhSachDocGia(string duongDan, DocGia ds[], int& soLuong, int soLuongToiDa) {
    ifstream f(duongDan.c_str(), ios::binary);
    if (!f.is_open()) return false;
    f.read((char*)&soLuong, sizeof(int));
    if (soLuong > soLuongToiDa) soLuong = soLuongToiDa;
    for (int i = 0; i < soLuong; i++) {
        ds[i] = docMotDocGia(f);
    }
    return true;
}

bool ghiDanhSachDocGia(string duongDan, DocGia ds[], int soLuong) {
    ofstream f(duongDan.c_str(), ios::binary);
    if (!f.is_open()) return false;
    f.write((char*)&soLuong, sizeof(int));
    for (int i = 0; i < soLuong; i++) {
        ghiMotDocGia(f, ds[i]);
    }
    return true;
}

bool docDanhSachPhieu(string duongDan, PhieuMuon ds[], int& soLuong, int soLuongToiDa) {
    ifstream f(duongDan.c_str(), ios::binary);
    if (!f.is_open()) return false;
    f.read((char*)&soLuong, sizeof(int));
    if (soLuong > soLuongToiDa) soLuong = soLuongToiDa;
    for (int i = 0; i < soLuong; i++) {
        ds[i] = docMotPhieu(f);
    }
    return true;
}

bool ghiDanhSachPhieu(string duongDan, PhieuMuon ds[], int soLuong) {
    ofstream f(duongDan.c_str(), ios::binary);
    if (!f.is_open()) return false;
    f.write((char*)&soLuong, sizeof(int));
    for (int i = 0; i < soLuong; i++) {
        ghiMotPhieu(f, ds[i]);
    }
    return true;
}

bool xuatBaoCaoVanBan(string duongDan, string noiDung) {
    ofstream f(duongDan.c_str());
    if (!f.is_open()) return false;
    f << noiDung;
    return true;
}

bool xuatDanhMucSachCSV(string duongDan, Sach ds[], int soLuong) {
    return false;
}

bool saoLuuTheoNgay(string thuMucData, string ngayHienTai) {
    return false;
}