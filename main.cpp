#include <iostream>
#include "markov.h"

using namespace std;

int main()
{
    srand(time(0)); //random

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);

    string prefixes[10000], suffixes[10000];

    int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 10000);

    for (int i = 0; i < 5; i++){
        cout << getRandomPrefix(prefixes, chainSize) << endl;
    }

    return 0;
}
