# Chương Trình Quản Lý Thư Viện (C++)

Đồ án Tin học – Học kỳ I (2026-2027) · Giảng viên: Lương An Vinh
Sinh viên thực hiện: Huỳnh Anh Minh · MSSV: _______ (điền sau) · Hình thức: Cá nhân

## Mô tả

Chương trình quản lý thư viện chạy trên console (C++11+), lưu dữ liệu bằng file
nhị phân/văn bản — **không dùng CSDL** theo đúng yêu cầu đề cương.

## Cấu trúc thư mục

```
LibraryManagement/
├── include/        # Khai báo lớp (.h) — struct dữ liệu + các CTDL
├── src/            # Cài đặt (.cpp)
├── data/           # File dữ liệu (.dat/.txt) — sinh ra khi chạy chương trình
├── docs/           # SRS, thiết kế, báo cáo
├── tests/          # Test case đơn giản (assert, không dùng framework ngoài)
├── Makefile
└── README.md
```

## Ánh xạ CTDL bắt buộc → Chức năng

| # | CTDL | File | Áp dụng cho | Trạng thái |
|---|------|------|-------------|------------|
| 1 | AVL Tree | `AVLTree.h` | Quản lý sách theo ISBN | Khung sườn — cài Tuần 3 |
| 2 | BST | `BSTree.h` | In danh mục sách theo tên (in-order) | Khung sườn — cài Tuần 3 |
| 3 | Hash Table (separate chaining) | `HashTable.h` | Quản lý độc giả theo CMND | Khung sườn — cài Tuần 4 |
| 4 | Danh sách liên kết đơn | `LinkedList.h` | Danh sách phiếu mượn | Khung sườn — cài Tuần 5 |
| 5 | Mảng động (tự cài) | `DynamicArray.h` | Lịch sử giao dịch | Khung sườn — cài Tuần 5 |
| 6 | Đồ thị (danh sách kề) | `Graph.h/.cpp` | Gợi ý sách cùng thể loại (BFS/DFS) | Khung sườn — cài Tuần 7 |
| 7 | **Trie** (CTDL tự tìm hiểu) | `Trie.h/.cpp` | Autocomplete tên sách theo tiền tố | Khung sườn — cài Tuần 8 |
| 8 | Đọc/ghi file nhị phân | `FileManager.h/.cpp` | Lưu trữ toàn bộ dữ liệu | Khung sườn — cài Tuần 5 |

> Giai đoạn hiện tại (Tuần 1) chỉ dựng **giao diện lớp + menu console**, chưa cài
> thuật toán. Mỗi hàm còn thiếu đều có comment `TODO (Tuần X): ...` ghi rõ việc cần làm
> và tuần tương ứng theo tiến độ 10 tuần của đề cương.

## Build & chạy

```bash
make        # biên dịch, sinh ra bin/QuanLyThuVien
make run    # biên dịch rồi chạy luôn
make clean  # xoá file build (obj/, bin/)
```

Trên Windows (Dev-C++ / Code::Blocks): tạo project console mới, add toàn bộ
`src/*.cpp`, set thêm `include/` vào Additional Include Directories.

## Checklist theo tuần (theo đề cương, mục 11)

- [x] Tuần 1 — Repo Git, SRS.pdf, cấu trúc thư mục
- [ ] Tuần 2 — Design.pdf (sơ đồ lớp, định nghĩa struct)
- [ ] Tuần 3 — AVL, BST, test quản lý sách
- [ ] Tuần 4 — Hash Table, test quản lý độc giả
- [ ] Tuần 5 — LinkedList, DynamicArray, File I/O
- [ ] Tuần 6 — Mượn sách, trả sách, tính phạt
- [ ] Tuần 7 — Graph, BFS/DFS, thống kê top 10
- [ ] Tuần 8 — Trie, tích hợp autocomplete, demo
- [ ] Tuần 9 — Unit test, bảng so sánh hiệu năng, user manual
- [ ] Tuần 10 — Báo cáo, video, slide, nộp + ký

## Ghi chú thiết kế

- CTDL tự tìm hiểu đã chọn: **Trie**, áp dụng cho autocomplete tên sách (mục 3.5).
- Các lớp CTDL tổng quát (AVLTree, BSTree, HashTable, LinkedList, DynamicArray) viết
  dạng template `<Key, Value>` hoặc `<T>` để tái sử dụng được cho nhiều kiểu dữ liệu.
- Chuỗi tiếng Việt trong code/console được viết không dấu để tránh lỗi hiển thị trên
  Console Windows (cmd.exe mặc định không hỗ trợ tốt UTF-8 có dấu).
