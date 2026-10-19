#include <iostream>
#include "FileReader.h"
#include "LanguageModel.h"
LanguageModel* test;
#include <string>
#include <stdexcept>

int main(int argc, char* argv[])
{
    try
    {
        double alpha = 0;
        int fir_arg = 1;
        if(argc < 4)
        {
            throw std::runtime_error("Argument not enough");
        }
        if(string(argv[1]) == "-a")
        {
            alpha = std::stod(argv[2]);
            fir_arg = 3;
        }

        int k = std::stoi(argv[fir_arg]);
        string filename = argv[fir_arg + 1];
        int outputlength = std::stoi(argv[fir_arg + 2]);
        string text = FileReader::readFile(filename);

        if(text.size() < static_cast<size_t>(k))
        {
            throw std::runtime_error("Text is longer than: " + std::to_string(k));

        }

        LanguageModel model(k, alpha);
        model.train(text);
        model.printFrequencies();
        //model.printTransitions();
        std::cout << "\nGenerated Text: \n" <<std::endl;
        std::cout << model.generate(outputlength) << std::endl; 
    }

    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() <<std::endl;
    }
    std::cin.get();
}
