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

class Inventory {
    std::map<std::string,int> items_;
    static void validate(const std::string& name,int quantity) {
        if (name.empty() || quantity<=0) throw std::invalid_argument("item");
    }
    public:
        int count(const std::string& name) const {
            auto it=items_.find(name);return it==items_.end()?0:it->second;
        }
        void add(std::string name,int quantity) {
            validate(name,quantity);
            int old=count(name);
            if (quantity>INT_MAX-old) throw std::overflow_error("stock");
            items_[std::move(name)]=old+quantity;
        }
        bool remove(const std::string& name,int quantity) {
            validate(name,quantity);
            auto it=items_.find(name);
            if (it==items_.end() || it->second<quantity) return false;
            it->second-=quantity;return true;
        }
};
