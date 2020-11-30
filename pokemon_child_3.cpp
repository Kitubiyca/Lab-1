#include "pokemon_child_3.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <ctime>

Pokemon_3::Pokemon_3(){}

void Pokemon_3::set_special_attack(std::string in_special_attack){special_attack=in_special_attack;}
void Pokemon_3::set_special_defense(std::string in_special_defense){special_defense=in_special_defense;}

std::string Pokemon_3::get_special_attack(){return special_attack;}
std::string Pokemon_3::get_special_defense(){return special_defense;}

std::string Pokemon_3::write_info(char in_filename[]){
    std::string filename=in_filename;
    std::ifstream file(filename);
    if (file.is_open()){
        char timet[80];
        const time_t timer = time(NULL);
        strftime(timet, 80, "%d.%m.%Y %H.%M.%S.json",localtime(&timer));
        filename=timet;
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
    F << "\t\t\t\"special attack\": \"" << special_attack << "\",\n";
    F << "\t\t\t\"special defense\": \"" << special_defense << "\"\n";
    F << "\t\t}\n";
    F << "\t]\n";
    F << "}\n";
    F.close();
    std::cout << "Data was saved to file \"" << filename << "\""<< std::endl;
    return filename;
}

void Pokemon_3::add_info(char in_filename[]){
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
    F << "\t\t\t\"speed\": " << speed << ",\n";
    F << "\t\t\t\"special attack\": \"" << special_attack << "\",\n";
    F << "\t\t\t\"special defense\": \"" << special_defense << "\"\n";
    F << "\t\t}\n";
    F << "\t]\n";
    F << "}\n";
    F.close();}
    return;
}