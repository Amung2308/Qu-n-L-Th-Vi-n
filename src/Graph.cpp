#include "Graph.h"
#include <queue>
#include <set>

void Graph::themDinh(const std::string& dinh) {
    if (danhSachKe.find(dinh) == danhSachKe.end()) {
        danhSachKe[dinh] = std::vector<std::string>();
    }
}

void Graph::themCanh(const std::string& dinh1, const std::string& dinh2) {
    (void)dinh1;
    (void)dinh2;
}

std::vector<std::string> Graph::bfs(const std::string& dinhBatDau) const {
    std::vector<std::string> ketQua;
    (void)dinhBatDau;
    return ketQua;
}

std::vector<std::string> Graph::dfs(const std::string& dinhBatDau) const {
    std::vector<std::string> ketQua;
    (void)dinhBatDau;
    return ketQua;
}

bool Graph::coDinh(const std::string& dinh) const {
    return danhSachKe.find(dinh) != danhSachKe.end();
}
