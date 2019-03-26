#include "virtual_world.hpp"
#include <cmath>

namespace r2d2::simulator {

    virtual_world_c::virtual_world_c(int width_in_meters, int length_in_meters, int width_data_point_count,
                                     int length_data_point_count):
        data_points(new world_data_point_s[width_data_point_count * length_data_point_count]), world_width(width_in_meters), world_length(length_in_meters), width_point_count(width_data_point_count), length_point_count(length_data_point_count)
    {}

    world_data_point_s virtual_world_c::get_data_at_position(const float &x, const float &z) {
        if (x < 0 || x > world_width || z < 0 || z > world_length) {
            return empty_world_data_point;
        }

        float grid_x_size = world_width / dynamic_cast<float>(width_point_count - 1);
        float grid_z_size = world_length / dynamic_cast<float>(length_point_count - 1);

        int grid_x = floor(x / grid_x_size);
        int grid_z = floor(x / grid_z_size);

        float coord_inside_grid_x = (x % grid_x_size) / grid_x_size;
        float coord_inside_grid_z = (z % grid_z_size) / grid_z_size;

        world_data_point_s top_datapoint_interpolation = interpolate_world_data_point(get_data_at_array_position(grid_x, grid_z), get_data_at_array_position(grid_x + 1, grid_z), coord_inside_grid_x);
        world_data_point_s bottom_datapoint_interpolation = interpolate_world_data_point(get_data_at_array_position(grid_x, grid_z + 1), get_data_at_array_position(grid_x + 1, grid_z + 1), coord_inside_grid_x);

        return interpolate_world_data_point(top_datapoint_interpolation, bottom_datapoint_interpolation, coord_inside_grid_z);
    }

    world_data_point_s virtual_world_c::get_data_at_array_position(const int &x, const int &z) {
        if (x < 0 || x >= width_point_count || z < 0 || z >= length_point_count) {
            return empty_world_data_point;
        }
        return data_points[x + z * length_point_count];
    }

    bool virtual_world_c::is_point_below_terrain(const r2d2::simulator::world_data_point_s &point) {
        world_data_point_s terrain_point = get_data_at_position(point.x, point.z);
        return terrain_point.y > point.y;
    }

}