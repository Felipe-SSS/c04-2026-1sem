#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "structs.h"

using namespace std;

Word* findWordPointer(const string& word, Dictionary& dictionary) {
    for (list<Word>::iterator it = dictionary.words.begin(); it != dictionary.words.end(); ++it) {
        if (it->word == word) {
            return &(*it);
        }
    }

    return nullptr; // Return nullptr if the word is not found
}

double calculateSimilarity(const Word& word1, const Word& word2) {
    double similarity = 0.0;
    const double maxFirstLetterScore = 33.3;
    const int maxAlphabetDistance = 25;
    int firstLetterDistance = word1.coordinates.x - word2.coordinates.x;

    if (firstLetterDistance < 0) {
        firstLetterDistance = -firstLetterDistance;
    }

    if (firstLetterDistance > maxAlphabetDistance) {
        firstLetterDistance = maxAlphabetDistance;
    }

    double firstLetterSimilarity =
        (static_cast<double>(maxAlphabetDistance - firstLetterDistance) / maxAlphabetDistance) * maxFirstLetterScore;

    if  (firstLetterDistance == 0) {
        firstLetterSimilarity = maxFirstLetterScore;
    }

    similarity += firstLetterSimilarity;

    return similarity;
}
