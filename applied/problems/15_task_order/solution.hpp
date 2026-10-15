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

inline std::optional<std::vector<int>> task_order(std::size_t n, const std::vector<std::pair<int, int>> & edges) {
    std::vector<std::vector<int>> adj(n);
    std::vector<int> indegree(n, 0);
    for (auto [a, b] : edges) {
        if (a < 0 || b < 0 || static_cast<std::size_t> (a) >= n || static_cast<std::size_t> (b) >= n) throw std::invalid_argument("edge");
        adj[a].push_back(b);
        ++indegree[b];
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> ready;
    for (std::size_t i = 0; i < n; ++i) if (indegree[i] == 0) ready.push(static_cast<int> (i));
    std::vector<int> out;
    while (!ready.empty()) {
        int u = ready.top();
        ready.pop();
        out.push_back(u);
        for (int v : adj[u]) if (--indegree[v] == 0) ready.push(v);
    }
    if (out.size() != n) return std::nullopt;
    return out;
}
