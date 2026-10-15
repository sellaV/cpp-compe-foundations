#include <iostream>
#include <vector>

void increment_copy(int x) {
    ++x;
}

void increment_original(int& x) {
    ++x;
}

struct SearchResult {
    bool found;
    int value;
};

SearchResult first_negative(const std::vector<int>& values) {
    for (int value : values) {
        if (value < 0) {
            return {true, value};
        }
    }
    return {false, 0};
}

int main() {
    int number = 5;
    increment_copy(number);
    std::cout << "After copy: " << number << '\n';
    increment_original(number);
    std::cout << "After reference: " << number << '\n';

    std::vector<int> values{4, -2, 0};
    SearchResult result = first_negative(values);
    if (result.found) {
        std::cout << "First negative: " << result.value << '\n';
    } else {
        std::cout << "No negative value\n";
    }

    SearchResult zero{true, 0};
    if (zero.found) {
        std::cout << "Result contains: " << zero.value << '\n';
    }
}
