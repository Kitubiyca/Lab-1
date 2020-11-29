#pragma once
#include <string>

class Pokemon{

    protected:

    std::string name = "Chupacabra";
    int health = 100;
    int attack = 15;
    int armor = 5;
    int speed = 3;

    public:

    Pokemon();
    Pokemon(std::string in_name, int in_health, int in_attack, int in_armor, int in_speed);

    void set_name(std::string in_name);
    void set_health(int in_health);
    void set_attack(int in_attack);
    void set_armor(int in_armor);
    void set_speed(int in_speed);

    std::string get_name();
    int get_health();
    int get_attack();
    int get_armor();
    int get_speed();

    std::string write_info(char in_filename[]);
    void add_info(char in_filename[]);

};