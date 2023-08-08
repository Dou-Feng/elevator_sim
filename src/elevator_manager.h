#pragma once

#include <vector>

template <typename elvator>
class elevator_manager {
    using elvator_holder_t = std::vector<elvator>;

    elevator_holder_t elvators;

};