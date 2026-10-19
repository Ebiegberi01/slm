#pragma once
#include <string>

using string = std::string;
class FileReader
{
    public:
        static string readFile(const string& filename);
}; //just declared readfile and used static to allows us call it with creating/initialising an object