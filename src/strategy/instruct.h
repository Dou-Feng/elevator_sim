#pragma once

#include <utility>

class instruct_base {
public:
    instruct_base(int move_d, int target_floor) 
        : move_d_(move_d), target_floor_(target_floor) {}

    std::pair<int, int> instruct() {
        return std::make_pair(move_d_, target_floor_);
    }
private:
    int move_d_;
    int target_floor_;
};

class simple_instruct : public instruct_base {
public:
    simple_instruct(int move_d, int target_floor) 
        : instruct_base(move_d, target_floor) {}
};