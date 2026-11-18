# Chương trình Quản lý Thư viện (C++)

Đồ án Tin học – Trường Đại học Công nghệ Sài Gòn (STU)

- Sinh viên: Huỳnh Anh Minh
- MSSV: DH52400642
- Lớp: D24_TH02
- Giảng viên hướng dẫn: Lương An Vinh

## 1. Giới thiệu

Chương trình quản lý thư viện chạy trên màn hình console, viết bằng C++ và sử dụng các cấu trúc dữ liệu tự cài đặt. Dữ liệu sách và độc giả được lưu bằng file nhị phân trong thư mục `data/`.

## 2. Cấu trúc thư mục

```text
QuanLyThuVien/
├── data/           # File dữ liệu chạy chương trình (.dat)
├── docs/           # Tài liệu SRS, thiết kế và hình ảnh
├── include/        # File khai báo .h
├── src/            # Mã nguồn .cpp
├── tests/          # Khu vực đặt các bài kiểm thử
├── .gitignore
├── Makefile
└── README.md
```

Các file Solution/Project của Visual Studio (`.sln`, `.vcxproj`, `.vcxproj.filters`, `.vcxproj.user`) được giữ trong thư mục trên máy để mở và chạy bằng Visual Studio. Các file này được `.gitignore` bỏ qua để repository trên GitHub giữ cấu trúc gọn theo mẫu.

## 3. Các phần đã có trong mã nguồn

- **Quản lý sách:** thêm sách, tìm theo ISBN bằng cây AVL, in danh mục theo ISBN bằng AVL và in theo tên bằng BST.
- **Quản lý độc giả:** thêm, xóa và tìm độc giả theo CMND bằng bảng băm.
- **Lưu dữ liệu:** đọc và ghi danh sách sách (`data/sach.dat`) và độc giả (`data/docgia.dat`) bằng file nhị phân.
- **Cấu trúc hỗ trợ:** Linked List cho phiếu mượn, Dynamic Array cho lịch sử giao dịch, cùng các module Graph và Trie.

Một số lựa chọn trên menu như sửa sách, nghiệp vụ mượn-trả, thống kê và gợi ý nâng cao hiện vẫn đang được phát triển; chưa nên xem là chức năng hoàn tất.

## 4. Chạy bằng Visual Studio trên Windows

1. Mở file `Huỳnh Anh Minh_DH52400642_Đồ Án Tin Học.sln` ở thư mục gốc.
2. Chọn cấu hình `Debug | x64`.
3. Nhấn `Ctrl + Shift + B` để Build.
4. Nhấn `Ctrl + F5` để chạy không cần Debug.

Working Directory được đặt về thư mục project để chương trình đọc/ghi đúng các đường dẫn tương đối `data/sach.dat` và `data/docgia.dat`.

## 5. Build bằng Makefile

Cần có `g++` và `make`:

```bash
make        # Biên dịch chương trình
make run    # Biên dịch và chạy
make clean  # Xóa thư mục obj/ và bin/
```

## 6. Dữ liệu và kiểm thử

Các file `.dat` được tạo hoặc cập nhật khi chạy chương trình. `.gitignore` bỏ qua các file dữ liệu chạy cục bộ để tránh đưa dữ liệu thử nghiệm cá nhân lên GitHub. Thư mục `tests/` hiện mới có file khung, phần kiểm thử tự động sẽ được bổ sung sau.
