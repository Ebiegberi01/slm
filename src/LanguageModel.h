#pragma once
#include <string>
#include <map>
#include <vector>

using string = std::string;

class LanguageModel
{
    private:
        int k;
        double alpha;
        std::map<string, int> gramCount;
        std::map<string, std::map<char, int>> transitions;
        std::vector<char> alphabet;

    public:
        LanguageModel(int kValue, double alphaValue);
        void train(const string& text);
        void printFrequencies();
        void printTransitions();
        string generate(int length);
};