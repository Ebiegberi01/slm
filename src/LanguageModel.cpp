#include <iostream>
#include "LanguageModel.h"
#include <set>
#include <random>

LanguageModel::LanguageModel(int kValue, double alphaValue) : k(kValue), alpha(alphaValue) {}

void LanguageModel::train(const string& text)
{
    std::set<char> chars;
    for(char c : text)
    {
        chars.insert(c);
    }

    alphabet.assign(chars.begin(), chars.end());
    for(size_t i=0; i+k <= text.size(); i++)
    {
        string gram = text.substr(i, k);
        gramCount[gram]++;

        if(i + k< text.size())
        {
            char nextChar = text[i+k];
            transitions[gram][nextChar]++;
        }
    }
}

void LanguageModel::printFrequencies()
{
    int total = 0;
    for(auto pair: gramCount)
    {
        total += pair.second;
    }

    std::cout << "\nK-Gram Frequencies\n";
    for(auto pair: gramCount)
    {
        double frequenct = static_cast<double>(pair.second)/total;
        std::cout << pair.first << " : " << frequenct << std::endl;
    }
}

void LanguageModel::printTransitions()
{
    std::cout <<"\nTransition Probabilities\n";
    
    for(auto gram : transitions)
    {
        std::cout << "\n" << gram.first <<std::endl;
        int totalTransition = 0;

        for(auto count : gram.second)
        {
           totalTransition += count.second;
        }

         for(char symbol : alphabet)
        {
           int currentCount = 0;

           if(gram.second. count(symbol))
           {
                currentCount = gram.second.at(symbol);
           }

           double prob = (currentCount + alpha) / (totalTransition + alpha * alphabet.size());
           std::cout << symbol << " ->" << prob <<std::endl;
        }
    }
}

string LanguageModel::generate(int length)
{
    if(gramCount.empty())
    {
        return "";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<string> grams;
    
    for(auto pair : gramCount)
    {
        grams.push_back(pair.first);
    }

    std::uniform_int_distribution<>start(0, grams.size() -1);
    string currentGram = grams[start(gen)];
    string result = currentGram;

    while(result.size() < length)
    {
        if(!transitions.count(currentGram))
        {
            break;
        }

        std::vector <char> letters;
        std::vector<double> weights;

        for(char c : alphabet)
        {
            letters.push_back(c);
            weights.push_back(transitions[currentGram][c] + alpha);
        }

        std::discrete_distribution<>dist(weights.begin(), weights.end());
        char nextChar = letters[dist(gen)];

        result += nextChar;

        currentGram = currentGram.substr(1) + nextChar;
    }

    return result;
}