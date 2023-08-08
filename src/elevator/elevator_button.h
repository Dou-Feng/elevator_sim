#pragma once

#include <string>

class elevator_button {
public:

    elevator_button(int id) : id_(id), literal_num_(std::to_string(id)), is_pushed_(false) {}

    void push() {
        is_pushed_ = 1;
    }

    void long_push() {
        is_pushed_ = 0;
    }

    bool is_pushed() { return is_pushed_; }
    bool id() { return id_; }
    std::string literal_num() { return literal_num_; }
private:
    int id_;
    std::string literal_num_;
    bool is_pushed_;
};