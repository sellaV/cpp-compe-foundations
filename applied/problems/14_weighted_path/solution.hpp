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

using Graph = std::vector<std::vector<std::pair<int, int>>>;
inline std::vector<std::int64_t> shortest_costs(const Graph & graph, int source) {
    int n = static_cast<int> (graph.size());
    if (source < 0 || source >= n) throw std::invalid_argument("source");
    for (const auto & edges : graph) for (auto [v, w] : edges) if (v < 0 || v >= n || w < 0) throw std::invalid_argument("edge");
    using Entry = std::pair<std::int64_t, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> q;
    std::vector<std::int64_t> d(n, std::numeric_limits<std::int64_t>::max());
    d[source] = 0;
    q.push({
        0, source
    });
    while (!q.empty()) {
        auto [cost, u] = q.top();
        q.pop();
        if (cost != d[u]) continue;
        for (auto [v, w] : graph[u]) if (cost + w < d[v]) {
            d[v] = cost + w;
            q.push({
                d[v], v
            });
        }
    }
    return d;
}
