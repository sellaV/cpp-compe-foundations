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
    State state_ = State::Idle;
public:
    State state() const {
        return state_;
    }
    void handle(Event e) {
        if (e == Event::Fault) {
            state_ = State::Emergency;
            return;
        }
        switch (state_) {
            case State::Idle : if (e == Event::Start) state_ = State::Running;
            break;
            case State::Running : if (e == Event::Stop) state_ = State::Idle;
            break;
            case State::Emergency : if (e == Event::Reset) state_ = State::Idle;
            break;
        }
    }
};
