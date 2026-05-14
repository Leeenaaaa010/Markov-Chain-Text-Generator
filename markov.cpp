#include "markov.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// 1
string joinWords(const string words[], int startIndex, int count)
{
    string result = "";

    for (int i = 0; i < count; i++)
    {
        result = result + words[startIndex + i];

        if (i != count - 1){
            result = result + " ";
        }
    }

    return result;


}

// 2
int readWordsFromFile(string filename, string words[], int maxWords)
{
    ifstream inputFile;
    inputFile.open(filename);

    if(!inputFile.is_open()){
        return -1;
    }

    int count = 0;
    while (count < maxWords && inputFile >> words[count]){
        count++;
    }
    inputFile.close();
    return count;

}

// 3
int buildMarkovChain(const string words[], int numWords, int order,
                     string prefixes[], string suffixes[], int maxChainSize)
{
    int count = 0;

    for (int i = 0; i < numWords - order; i++){

        string prefix = joinWords(words, i, order);
        string suffix = words[i + order];

        prefixes[count] = prefix;
        suffixes[count] = suffix;

        count++;

        if (count >= maxChainSize){
        break;
        }
    }

    return count;
}

// 4
string getRandomSuffix(const string prefixes[], const string suffixes[],
                       int chainSize, string currentPrefix)
{
    int matchCount = 0;

    //count matches
    for (int i = 0; i < chainSize; i++){
        if (prefixes[i] == currentPrefix){
            matchCount++;
        }
    }

    if (matchCount == 0){
        return "";
    }

    //pick random index
    int pick = rand() % matchCount;

    //find the picked match
    int currentMatch = 0;

    for (int i = 0; i < chainSize; i++){
        if (prefixes[i] == currentPrefix){
            if (currentMatch == pick){
                return suffixes[i];
            }
            currentMatch++;
        }
    }

    return "";
}

// 5
string getRandomPrefix(const string prefixes[], int chainSize)
{
    int index = rand() % chainSize;
    return prefixes[index];

}

// 6
string generateText(const string prefixes[], const string suffixes[],
                    int chainSize, int order, int numWords)
{
    return "";
}
