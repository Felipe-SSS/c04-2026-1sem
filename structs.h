#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Coordinates
{
    int x; // First Letter
    int y; // Number of characters
    int z; // Synonyms
};

struct Word
{
    string word;
    string translation;
    Coordinates coordinates;
};

struct Edge
{
    Word* source;
    Word* target;
    double similarity;
};

struct Dictionary
{
    list<Word> words;
    list<Edge> edges;
};

#endif // STRUCTS_H
