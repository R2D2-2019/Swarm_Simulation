//
// Created by thomas on 20-5-2019.
//
#pragma once

#include <iostream>
#include <string>
#include <map>



namespace r2d2::state_storage{
    template <typename value_map>
    class state_storage_c {
    private:

        std::map <std::string, std::map<std::string, value_map>> storage;

        bool check_in_dict(std::string);


    public:
        state_storage_c();


        /* @name: write
         * @description: write a map data to the storage. if the write is complete a true will be return
         * @return: bool
         */
        bool write(std::string, std::map<std::string, value_map>);
        /* @name: write singel value
         * @description: write a singel value to one place in the storage.
         * it returns if the write is compeet  with a bool.
         * @return: bool
         */
        bool write_singel_value(std::string, std::string, value_map );
        /* @name: rewirte storage
         * @description: re write the full storage of the simulatate robot
         * @return: bool
         */
        bool rewrite_storage(std::map <std::string, std::map<std::string, value_map>>);
        /* @name: read
         * @description: read a part out a part of the storage. and get the map back of the requested storage
         * @input: string
         * @return: bool
         */
        std::map<std::string, value_map>  read(std::string);


    };
}

