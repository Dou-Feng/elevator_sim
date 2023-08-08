#pragma once


namespace eleva {

enum class direction_type {
    down = 0,
    up = 1,
};

enum class request_type {
    down = 0,
    up = 1,
    none = 2
};

enum class event_type {
    ELE_MOVE_FINISHED,
};

}