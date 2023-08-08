#pragma once

#include <vector>
#include <elevator_button.h>
#include <cassert>
#include <queue>
#include <cmath>
#include <common.h>

namespace eleva {

template<typename Engine, typename Instruct, typename Passager, typename Timer>
class simple_elevator {
public:
    using engine_t = Engine;
    using instruct_t = Instruct;
    using box_t = box_base;

    simple_elevator(int max_floor, Timer& timer) 
        : max_floor_(max_floor), engine_(eng), timer_(timer), box_base(1200., 1.5) {
        abord_reqs().assign(max_floor, request::none);
    };

    void move(direction_type dir, int floor) {
        auto duration = engine_.move(dir, floor);
        timer_.add_event(timer_.get_time() + duration, event_type::ELE_MOVE_FINISHED);
        running_ = true;
    }

    bool running() { return running; }

private:
    

private:
    int max_floor_;
    box_t<Passager> box_;
    engine_t engine_;
    Timer& timer_;
    
    std::vector<request_type> aboard_reqs_;

    const static long WAIT_TIME = 10 * 1000;

    bool running_;
};

}