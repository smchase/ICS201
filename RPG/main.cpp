#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    std::fstream file("levels.txt");
    std::string output;

    std::getline(file, output);

    std::cout << output << std::endl;
}
