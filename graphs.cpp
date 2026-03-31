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

    return NULL; // Return NULL if the word is not found
}

double calculateSimilarity(const Word& word1, const Word& word2) {
    double similarity = 0.0;
    const double maxFirstLetterScore = 30.0;
    const double maxCharCountScore = 20.0;
    const double maxSynonymScore = 50.0;
    const int maxAlphabetDistance = 25;
    
    // First Letter (coordinate x)
    int firstLetterDistance = word1.coordinates.x - word2.coordinates.x;
    if (firstLetterDistance < 0) {
        firstLetterDistance = -firstLetterDistance;
    }
    if (firstLetterDistance > maxAlphabetDistance) {
        firstLetterDistance = maxAlphabetDistance;
    }
    double firstLetterSimilarity = ((double)(maxAlphabetDistance - firstLetterDistance) / maxAlphabetDistance) * maxFirstLetterScore;
    similarity += firstLetterSimilarity;
    
    // Character Count (coordinate y)
    int charCountDistance = word1.coordinates.y - word2.coordinates.y;
    if (charCountDistance < 0) {
        charCountDistance = -charCountDistance;
    }
    double charCountSimilarity = 0.0;
    if (charCountDistance == 0) {
        charCountSimilarity = maxCharCountScore;
    } else {
        charCountSimilarity = maxCharCountScore / (1.0 + charCountDistance);
    }
    similarity += charCountSimilarity;
    
    // Synonyms (coordinate z)
    int synonymDistance = word1.coordinates.z - word2.coordinates.z;
    if (synonymDistance < 0) {
        synonymDistance = -synonymDistance;
    }
    double synonymSimilarity = 0.0;
    if (synonymDistance == 0) {
        synonymSimilarity = maxSynonymScore;
    } else {
        synonymSimilarity = maxSynonymScore / (1.0 + synonymDistance);
    }
    similarity += synonymSimilarity;

    return similarity;
}
