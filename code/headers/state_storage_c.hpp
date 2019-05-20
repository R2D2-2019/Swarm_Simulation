//
// Created by thomas on 20-5-2019.
//
#ifndef R2D2_BUILD_STATE_STORAGE_HPP
#define R2D2_BUILD_STATE_STORAGE_C_HPP

#include <state_storage_c.hpp>



namespace r2d2::state_storage{
    class state_storage_c {
    private:

        std::map <std::string, std::map<std::string, std::string>> storage;

        bool check_in_dict(std::string);


    public:
        /* @name: write
         * @description: write a map data to the storage. if the write is complete a true will be return
         * @return: bool
         */
        bool write(std::string, std::map);
        /* @name: write singel value
         * @description: write a singel value to one place in the storage.
         * it returns if the write is compeet  with a bool.
         * @return: bool
         */
        bool write_singel_value(std::string, std::string, templateding );
        /* @name: rewirte storage
         * @description: re write the full storage of the simulatate robot
         * @return: bool
         */
        bool rewrite_storage(std::map <std::string, std::map<std::string, std::string>>);
        /* @name: read
         * @description: read a part out a part of the storage. and get the map back of the requested storage
         * @input: string
         * @return: bool
         */
        std::map read(std::string);


    };
}

#endif //R2D2_BUILD_STATE_STORAGE_HPP
