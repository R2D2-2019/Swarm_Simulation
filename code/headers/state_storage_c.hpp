//
// Created by thomas on 20-5-2019.
//
#pragma once

#include <iostream>
#include <string>
#include <map>



namespace r2d2::state_storage{
    template <typename value_type>
    class state_storage_c {
    private:

        std::map <std::string, std::map<std::string, value_type>> storage;

        bool check_in_dict(std::string);


    public:
        state_storage_c(std::map <std::string, std::map<std::string, value_type>> &storage ):storage(storage){}


        /* @name: write
         * @description: write a map data to the storage. if the write is complete a true will be return
         * @return: bool
         */
        bool write(const std::string &key, const std::map<std::string, value_type> &value){
            //this->storage[key][] = value;
            this->storage[key].insert(value);
            return true;
        }
        /* @name: write singel value
         * @description: write a singel value to one place in the storage.
         * it returns if the write is compeet  with a bool.
         * @return: bool
         */
        bool write_singel_value(const std::string &key_one, const std::string &key_two, value_type &value ){
            this->storage[key_one][key_two] = value;
            return true;
        }
        /* @name: rewirte storage
         * @description: re write the full storage of the simulatate robot
         * @return: bool
         */
        bool rewrite_storage(const std::map <std::string, std::map<std::string, value_type>> & new_storage){
            this->storage = new_storage;
            return true;
        }
        /* @name: read
         * @description: read a part out a part of the storage. and get the map back of the requested storage
         * @input: string
         * @return: bool
         */
        const std::map<std::string, value_type>&  read(const std::string & key){

            return this->storage[key];
        }


    };
}

