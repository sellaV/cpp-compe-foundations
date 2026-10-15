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

struct Node {
    int value;
    std::unique_ptr<Node> next;
};
inline std::vector<int> chain_values(const Node * head) {
    std::vector<int> out;
    for (auto p = head; p != nullptr; p = p->next.get()) out.push_back(p->value);
    return out;
}
