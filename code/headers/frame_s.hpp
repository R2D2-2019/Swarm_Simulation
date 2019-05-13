#pragma once
#include <cstdint>
#include <cstddef>
namespace r2d2::swarm_simulation {
    struct frame_s {
        size_t data_size;
        uint8_t data[];
    };
}