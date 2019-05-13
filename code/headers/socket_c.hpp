#pragma once

#include <cstddef>
#include <cstdint>

namespace r2d2::swarm_simulation {
    class socket_c {
    public:
        template<size_t ArraySize>
        void send_frame(const uint8_t data[ArraySize]) {
            this->send_frame(data, ArraySize);
        }
        template<typename FrameType>
        void send_frame(const FrameType& frame) {
            this->send_frame(reinterpret_cast<uint8[]>(frame), sizeof())
        }

        virtual void send_frame(const uint8_t data[], size_t size) = 0;
        virtual void listen() = 0;
    };
}