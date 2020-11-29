#include <iostream>
#include <cstring>
#include <fstream>
#include "pokemon.hpp"
#include "pokemon_children.hpp"

int main(){
    Pokemon_1 pokemon;
    std::cout << "Enter file name with extension\n";
    std::string filename;
    std::cin >> filename;
    char filename_out[40];
    strcpy(filename_out,filename.c_str());
    pokemon.add_info(filename_out); //Adds info into file, if exists
    filename=pokemon.write_info(filename_out); //Creates new file for info
    strcpy(filename_out,filename.c_str());
    pokemon.add_info(filename_out); //Adds info into previously created file
    Pokemon_2 pokemon_2;
    pokemon_2.add_info(filename_out); //Adds info into previously created file
    Pokemon pokemon_basic;
    pokemon_basic.add_info(filename_out); //Adds info into previously created file
    pokemon_basic.add_info(filename_out); //Adds info into previously created file
    return 0;
}