#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cmath>
#include "structs.h"

using namespace std;

Word* findWordPointer(const string& word, Dictionary& dictionary) {
    for (list<Word>::iterator it = dictionary.words.begin(); it != dictionary.words.end(); ++it) {
        if (it->word == word) {
            return &(*it);
        }
    }

    return NULL; // Return NULL if the word is not found
}

double calculateSimilarity(const Word& word1, const Word& word2) {
    double dx = word1.coordinates.x - word2.coordinates.x;
    double dy = word1.coordinates.y - word2.coordinates.y;
    double dz = word1.coordinates.z - word2.coordinates.z;

    double distance = sqrt(dx * dx + dy * dy + dz * dz);

    return 100.0 / (1.0 + distance);
}
