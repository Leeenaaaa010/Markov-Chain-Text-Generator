#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

int main() {
    srand(time(0));

    string filename;
    int order;
    int numWords;

    // Declare large arrays to hold the data
    static string words[100000];
    static string prefixes[100000];
    static string suffixes[100000];

    //user input
    cout << "Enter input filename: ";
    cin >> filename;
    cout << "Enter order (1, 2, or 3): ";
    cin >> order;
    cout << "Enter number of words to generate: ";
    cin >> numWords;

    // 5. Read words from the file
    int wordCount = readWordsFromFile(filename, words, 100000);

    if (wordCount == -1) {
        cout << "Error: Could not open file '" << filename << "'" << endl;
        return 1;
    }

    if (wordCount <= order) {
        cout << "Error: File too short to build a chain of order " << order << endl;
        return 1;
    }

    //Build Markov Chain
    int chainSize = buildMarkovChain(words, wordCount, order, prefixes, suffixes, 100000);

    //Generate text
    cout << "\nGenerated text:" << endl;
    string generatedText = generateText(prefixes, suffixes, chainSize, order, numWords);
    
    if (generatedText == "") {
        cout << "Error: Could not generate text." << endl;
    } else {
        cout << generatedText << endl;
    }

    return 0;
}