#include <iostream>
#include <list>
#include <iomanip>
#include "structs.h"
#include "graphs.h"

using namespace std;

// TODO: Improve function to show the graph in a more visual way
void buildAndDisplayCompleteGraph(Dictionary& dictionary)
{
    if (dictionary.words.size() < 2) {
        cout << "\nNeed at least 2 words to build a complete graph." << endl;
        return;
    }

    cout << "\n=== COMPLETE GRAPH ===" << endl;
    int edgeCount = 0;

    for (list<Word>::iterator it1 = dictionary.words.begin(); it1 != dictionary.words.end(); ++it1) {
        list<Word>::iterator it2 = it1;
        ++it2;
        for (; it2 != dictionary.words.end(); ++it2) {
            double sim = calculateSimilarity(*it1, *it2);
            cout << it1->word << " -- " << it2->word
                 << " (similarity: " << fixed << setprecision(2) << sim << ")" << endl;
            edgeCount++;
        }
    }

    cout << "\nTotal edges: " << edgeCount << endl;
}
