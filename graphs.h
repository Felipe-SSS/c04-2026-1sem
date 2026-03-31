#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "structs.h"

Word* findWordPointer(const string& word, Dictionary& dictionary);
double calculateSimilarity(const Word& word1, const Word& word2);

#endif // GRAPHS_H
