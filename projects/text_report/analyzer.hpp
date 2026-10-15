#pragma once
#include <cstddef>
#include <istream>

struct Report {
    std::size_t lines = 0;
    std::size_t words = 0;
    std::size_t bytes = 0;
};

// Read from the current position to EOF. See README for the exact contract.
Report analyze(std::istream& input);
