#include "markov.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// 1
string joinWords(const string words[], int startIndex, int count)
{
    return "";
}

// 2
int readWordsFromFile(string filename, string words[], int maxWords)
{
    return 0;
}

// 3
int buildMarkovChain(const string words[], int numWords, int order,
                     string prefixes[], string suffixes[], int maxChainSize)
{
    return 0;
}

// 4
string getRandomSuffix(const string prefixes[], const string suffixes[],
                       int chainSize, string currentPrefix)
{
    return "";
}

// 5
string getRandomPrefix(const string prefixes[], int chainSize)
{
    return "";
}

// 6
string generateText(const string prefixes[], const string suffixes[],
                    int chainSize, int order, int numWords)
{
    return "";
}
