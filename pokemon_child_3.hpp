#pragma once
#include <string>
#include "pokemon.hpp"

class Pokemon_3 : public Pokemon{

    protected:

    std::string special_attack = "Throwing rocks";
    std::string special_defense = "Battle regeneration";

    public:

    Pokemon_3();

    void set_special_attack(std::string in_special_attack);
    void set_special_defense(std::string in_special_defense);

    std::string get_special_attack();
    std::string get_special_defense();

    std::string write_info(char in_filename[]);
    void add_info(char in_filename[]);

};