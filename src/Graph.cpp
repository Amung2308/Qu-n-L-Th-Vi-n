#include "Graph.h"
#include <queue>
#include <set>

void Graph::themDinh(const std::string& dinh) {
    // dam bao dinh ton tai trong map ke ca khi chua co canh nao
    if (danhSachKe.find(dinh) == danhSachKe.end()) {
        danhSachKe[dinh] = std::vector<std::string>();
    }
}

void Graph::themCanh(const std::string& dinh1, const std::string& dinh2) {
    // TODO (Tuan 7): them dinh1 vao danh sach ke cua dinh2 va nguoc lai (do thi vo huong),
    // nho goi themDinh() truoc neu dinh chua ton tai, va tranh them canh trung lap.
    (void)dinh1;
    (void)dinh2;
}

std::vector<std::string> Graph::bfs(const std::string& dinhBatDau) const {
    // TODO (Tuan 7): dung std::queue + std::set (hoac map<string,bool>) de danh dau
    // da tham, duyet rong tu dinhBatDau, tra ve thu tu cac dinh da tham.
    std::vector<std::string> ketQua;
    (void)dinhBatDau;
    return ketQua;
}

std::vector<std::string> Graph::dfs(const std::string& dinhBatDau) const {
    // TODO (Tuan 7): dung de quy hoac std::stack, danh dau da tham, tra ve thu tu tham.
    std::vector<std::string> ketQua;
    (void)dinhBatDau;
    return ketQua;
}

bool Graph::coDinh(const std::string& dinh) const {
    return danhSachKe.find(dinh) != danhSachKe.end();
}
