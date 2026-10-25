#pragma once
#include <vector>
#include <climits>

// stdexcept only supports the unfinished TODO placeholder; remove it when solved.
#include <stdexcept>
struct NumberResult { bool found; int value; };
inline NumberResult second_largest(const std::vector<int>& values) {
    // TODO: implement the contract using core language features.
    int first = INT_MIN;
    int second = INT_MIN;
    bool found_first = false;
    bool found_second = false;
    for (int current: values){
        if (!found_first){
            first = current;
            found_first = true;
        }
        if (current > first){
            second = first;
            first = current;
            found_second = true;
        }
        else if (current < first){
            if (current > second || !found_second){
                second = current;
                found_second = true;
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }
    if (found_second){
        return{true, second};
    }
    else {
        return{false, 0};
    }
}
// 8 5 8 3 false false
// false true
// first, second = INT_MIN
// if current > first -> second = first, first = current
// if current < first -> check (if current > second -> second = current else pass)
// if current = first -> pass
// found_first, found_second false
// FOR each current:
//     IF current > first OR found_first false:
//         IF found_second true: second = first, first = current
//         ELSE: first = current, found_first = true
//     ELSE IF current < first:
//         IF current > second
//             IF found_second false: second = current, found_second true
//             ELSE: second = current
//         ELSE: pass

//     ELSE:
//         PASS