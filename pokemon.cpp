#include "pokemon.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <ctime>

Pokemon::Pokemon(){}

Pokemon::Pokemon(std::string in_name, int in_health, int in_attack, int in_armor, int in_speed){
    name=in_name;
    health=in_health;
    attack=in_attack;
    armor=in_armor;
    speed=in_speed;}
    
void Pokemon::set_name(std::string in_name){name=in_name;}
void Pokemon::set_health(int in_health){health=in_health;}
void Pokemon::set_attack(int in_attack){attack=in_attack;}
void Pokemon::set_armor(int in_armor){armor=in_armor;}
void Pokemon::set_speed(int in_speed){speed=in_speed;}

std::string Pokemon::get_name(){return name;}
int Pokemon::get_health(){return health;}
int Pokemon::get_attack(){return attack;}
int Pokemon::get_armor(){return armor;}
int Pokemon::get_speed(){return speed;}

std::string Pokemon::write_info(char in_filename[]){ //Creates new file
    std::string filename=in_filename;
    std::ifstream file(filename);
    if (file.is_open()){ //Checks filename for existence
        char timet[80];
        const time_t timer = time(NULL);
        strftime(timet, 80, "%d.%m.%Y %H.%M.%S.json",localtime(&timer)); //Gets current date and time
        filename=timet; //Sets new filename from current date and time
        std::cout << "This file already exists, creating additional file..." << std::endl;
    }
    file.close();
    std::ofstream F;
    F.open (filename);
    F << "{\n";
    F << "\t\"pokemons\": [\n";
    F << "\t\t{\n";
    F << "\t\t\t\"name\": \"" << name << "\",\n";
    F << "\t\t\t\"HP\": " << health << ",\n";
    F << "\t\t\t\"attack\": " << attack << ",\n";
    F << "\t\t\t\"armor\": " << armor << ",\n";
    F << "\t\t\t\"speed\": " << speed << ",\n";
    F << "\t\t}\n";
    F << "\t]\n";
    F << "}\n";
    F.close();
    std::cout << "Data was saved to file \"" << filename << "\""<< std::endl;
    return filename;
}

void Pokemon::add_info(char in_filename[]){ //Adds info into created file
    bool file_check=0;
    FILE * FF = fopen(in_filename, "r+");
    fseek(FF, -9, SEEK_END);
    fputs(",        ", FF);
    fclose (FF);
    std::ofstream F;
    F.open (in_filename, std::ios::in);
    if(F.is_open()) file_check=1;
    F.close();
    if(file_check){
    F.open (in_filename, std::ios::app);
    F << "\n";
    F << "\t\t{\n";
    F << "\t\t\t\"name\": \"" << name << "\",\n";
    F << "\t\t\t\"HP\": " << health << ",\n";
    F << "\t\t\t\"attack\": " << attack << ",\n";
    F << "\t\t\t\"armor\": " << armor << ",\n";
    F << "\t\t\t\"speed\": " << speed << "\n";
    F << "\t\t}\n";
    F << "\t]\n";
    F << "}\n";
    F.close();}
    return;
}