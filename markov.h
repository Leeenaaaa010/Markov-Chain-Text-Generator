#ifndef MARKOV_H
#define MARKOV_H

#include <string>

// 1
std::string joinWords(const std::string words[], int startIndex, int count);

// 2
int readWordsFromFile(std::string filename, std::string words[], int maxWords);

// 3
int buildMarkovChain(const std::string words[], int numWords, int order,
                     std::string prefixes[], std::string suffixes[], int maxChainSize);

// 4
std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
                            int chainSize, std::string currentPrefix);

// 5
std::string getRandomPrefix(const std::string prefixes[], int chainSize);

// 6
std::string generateText(const std::string prefixes[], const std::string suffixes[], int chainSize, int order, int numWords);

#endif
