#pragma once
#include <algorithm>
#include <array>
#include <charconv>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

struct Node { int value=0; std::unique_ptr<Node> next; };
inline void insert_sorted(std::unique_ptr<Node>& head,int value) {
    auto* link=&head;
    while (*link && (*link)->value<=value) link=&((*link)->next);
    auto node=std::make_unique<Node>();
    node->value=value;
    node->next=std::move(*link);
    *link=std::move(node);
}
