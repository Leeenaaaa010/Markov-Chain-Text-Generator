#include <iostream>
#include "markov.h"

using namespace std;

int main()
{
    cout << "Hello" << endl;

    string testWords[] = {"the", "cat", "sat", "down"};

    cout << joinWords(testWords, 0, 2) << endl;  // the cat
    cout << joinWords(testWords, 1, 3) << endl;  // cat sat down

    return 0;
}
