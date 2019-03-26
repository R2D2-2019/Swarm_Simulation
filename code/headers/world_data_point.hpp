#pragma once

namespace r2d2::simulator {

    /**
     * Struct to combine all world data in a neat package
     */
    struct world_data_point_s {
        float x, y, z;
    };

    /**
     * This function interpolates between 2 world data points. For now a linear interpolation is used, but better interpolation techniques could be used.
     *
     * @param point0 first point
     * @param point1 second point
     * @param weight value between 0 and 1, when 0 the funnction will return point0, when 1 the function will return point 1
     * @return interpolated point
     */
    world_data_point_s interpolate_world_data_point(const world_data_point_s &point0, const world_data_point_s &point1, float weight) {
        world_data_point_s interpolated_point;
        interpolated_point.x = (1 - weight) * point0.x + weight * point1.x;
        interpolated_point.y = (1 - weight) * point0.y + weight * point1.y;
        interpolated_point.z = (1 - weight) * point0.z + weight * point1.z;
    }

    world_data_point_s empty_world_data_point{0, 0, 0};

}