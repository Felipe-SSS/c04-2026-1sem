#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct TreeNode;

struct Coordinates
{
    float x; // First Letter
    float y; // Number of characters
    float z; // Synonyms
};

struct Word
{
    string word;
    list<string> translations;
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
    TreeNode* alphabetRoot;
    TreeNode* sizeRoot;

    Dictionary()
    {
        alphabetRoot = NULL;
        sizeRoot = NULL;
    }
};

#endif // STRUCTS_H
