// Trường hợp A: nums[current_index] == 0
// Bạn sẽ tăng current_index, write_index, hay cả hai? -> current_index
// Trường hợp B: nums[current_index] != 0
// Bạn sẽ làm gì với nums[write_index]? switch nums[write_index]
// Sau đó biến nào cần tăng? -> write_index

// current_index = 0
// write_index = 0
// nums = []
// WHILE current < nums.size()

//     IF nums[current_index] != 0:
//         nums[write_index] = nums[current_index]
//         write_index + 1
//         current_index + 1
//     ELSE:
//         current_index++

// 0 0 1 4 5
// cur = 0 -> cur + 1 = 1
// cur = 1 -> cur + 1 = 2
// cur = 2 -> 1 0 0 4 5, wri + 1 = 1, cur + 1 = 3
// cur = 3 -> 1 4 0 0 5, wri + 1 = 2, cur + 1 = 4
// cur = 4 -> 1 4 5 0 0, wri + 1 = 3, cur + 1 = 5 -> end

#include <iostream>
#include <vector>

int main() {
    int current_index = 0;
    int write_index = 0;
    std::vector<int> nums;
    int x;
    while (std::cin >> x) {
        nums.push_back(x);
    }
    while (current_index < nums.size()){
        if (nums[current_index] != 0){
            int c = nums[current_index];
            nums[current_index] = nums[write_index];
            nums[write_index] = c;
            write_index++;
            current_index++;
        }
        else{
            current_index++;
        }
    for (int num: nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    }
    return 0;
}
