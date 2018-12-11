#include <iostream>
#include <fstream>
#include <string>

#include "game.h"

void game ()
{
    std::fstream file("test.txt");
    std::string output;

    getline(file, output);
    std::cout << "game" << std::endl << output << std::endl;
}
