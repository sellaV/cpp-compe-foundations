#include <iostream>
#include <optional>
#include <vector>

// x is a copy: changing it does not change the caller's int.
void increment_copy(int x) {
    ++x;
}

// x refers to the caller's int: changing it changes that int.
void increment_original(int& x) {
    ++x;
}

// Read an existing vector without copying it into a parameter.
// Return an int when found, or an empty optional when absent.
std::optional<int> first_negative(const std::vector<int>& values) {
    for (int value : values) {
        if (value < 0) {
            return value;
        }
    }
    return std::nullopt;
}

int main() {
    int number = 5;
    increment_copy(number);
    std::cout << "After copy: " << number << '\n';
    increment_original(number);
    std::cout << "After reference: " << number << '\n';

    std::vector<int> values{4, -2, 0};
    std::optional<int> result = first_negative(values);
    if (result) {
        std::cout << "First negative: " << *result << '\n';
    } else {
        std::cout << "No negative value\n";
    }

    std::optional<int> zero = 0;
    if (zero) {
        std::cout << "Optional contains: " << *zero << '\n';
    }
}
