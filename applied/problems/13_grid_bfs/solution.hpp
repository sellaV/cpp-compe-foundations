#pragma once
#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

inline int shortest_grid_path(const std::vector<std::vector<int>> & grid) {
    if (grid.empty()) return - 1;
    const int h = static_cast<int> (grid.size()), w = static_cast<int> (grid[0].size());
    for (const auto & row : grid) if (static_cast<int> (row.size()) != w) throw std::invalid_argument("ragged");
    if (w == 0 || grid[0] [0] != 0 || grid[h - 1] [w - 1] != 0) return - 1;
    std::vector<std::vector<int>> d(h, std::vector<int> (w, - 1));
    std::queue < std::pair<int, int>> q;
    q.push({
        0, 0
    });
    d[0] [0] = 0;
    const int dr[] = {
        1, - 1, 0, 0
    }, dc[] = {
        0, 0, 1, - 1
    };
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == h - 1 && c == w - 1) return d[r] [c];
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr] [nc] == 0 && d[nr] [nc] < 0) {
                d[nr] [nc] = d[r] [c] + 1;
                q.push({
                    nr, nc
                });
            }
        }
    }
    return - 1;
}
