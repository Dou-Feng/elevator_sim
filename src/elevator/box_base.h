#pragma once

#include <vector>

namespace eleva {
template<typename Passager>
class box_base {
public:
    using button_t = elevator_button;
    using button_set_t = std::vector<button_t>;
    using passager_t = Passager;

    box_base(double max_load_cap, double max_volume_cap) 
        : max_load_cap_(max_load_cap), max_volume_cap_(max_volume_cap) {}

    double max_load_cap() { return max_load_cap_; }
    double max_volume_cap() { return max_volume_cap_; }
    button_set_t& get_buttons() { return buttons; }

    bool push(int no) {
        assert(no < buttons.size());
        buttons[no].push();
        return true;
    }

    bool long_push(int no) {
        assert(no < buttons.size());
        buttons[no].long_push();
        return true;
    }

    bool add_passager(const passager& psg) {
        if (psg.volume() + cur_volume_ > max_volume_cap_ ||
            psg.weight() + cur_load_ > max_load_cap_) return false;
        
        passagers_.push_back(psg);
        cur_volume_ += psg.volume();
        cur_load_ += psg.weight();
        return true;
    }

    bool rm_passager(int psg_id) {
        auto it = std::find_if(passager_t.begin(), passager_t.end(), [&](auto& psg) {
            return psg_id == psg.id();
        });
        if (it == passager_t.end()) return false;

        cur_load_ -= it->weight();
        cur_volume_ -= it->volume();
        passager_t.erase(it);
        return passager_t;
    }

    bool door_open() { return door_open_; }

    void set_door(bool open) {
        return door_open_ = open;
    }
private:
    double max_load_cap_; // unit is kg
    double max_volume_cap_; // unit is m^2
    button_set_t buttons;

    double cur_load_ = 0.; // the weight of the passagers.
    double cur_volume_ = 0.; // the volume that passagers take.
    std::vector<passager_t> passagers_;

    bool door_open_ = false;
};

}