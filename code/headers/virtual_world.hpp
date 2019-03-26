#pragma once

#include "world_data_point.hpp"

namespace r2d2::simulator {

    class virtual_world_c {
    public:
        virtual_world_c(int width_in_meters, int length_in_meters, int width_data_point_count, int length_data_point_count);
        world_data_point_s get_data_at_position(const float &x, const float &z);
        world_data_point_s get_data_at_array_position(const int &x, const int &z);
        bool is_point_below_terrain(const world_data_point_s &point);
    private:
        world_data_point_s *data_points;
        int world_width;
        int world_length;
        int width_point_count;
        int length_point_count;
    };

}