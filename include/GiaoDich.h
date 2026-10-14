#ifndef GIAODICH_H
#define GIAODICH_H

#include <string>

// Mot ban ghi lich su giao dich (muon hoac tra) - phan tu cua mang dong
// luu lich su giao dich (muc 4, dong 5).
struct GiaoDich {
    std::string maPhieu;
    std::string loaiGiaoDich;  // "MUON" hoac "TRA"
    std::string ngayThucHien;
};

#endif // GIAODICH_H
