#include <iostream>
#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

string FileReader::readFile(const string& filename)
{
    std::ifstream inputFile(filename);
    if(!inputFile)
    {
        throw std::runtime_error("Can't open file!");
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();

    return buffer.str();
}