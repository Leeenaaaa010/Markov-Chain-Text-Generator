#include <iostream>
#include "markov.h"

using namespace std;

int main()
{
    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);

    string prefixes[10000], suffixes[10000];

    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 10000);

    for (int i = 0; i < 20 && i < chainSize; i++)
    {
        cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    return 0;
}
