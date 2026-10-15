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

enum class State {
    Idle, Running, Emergency
};
enum class Event {
    Start, Stop, Fault, Reset
};
class Controller {
public:
    State state() const {
        throw std::logic_error("TODO state");
    }
    void handle(Event) {
        throw std::logic_error("TODO handle");
    }
};
