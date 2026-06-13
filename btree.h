#ifndef BTREE_H
#define BTREE_H

#include <string>
#include "structs.h"

struct TreeNode
{
	Word* data;
	TreeNode* left;
	TreeNode* right;
};

void insert(TreeNode*& current, Word* data, int option);
bool remove(TreeNode*& current, const std::string& data, int option);
void printTranslations(const list<string>& translations);
void show_in_order(TreeNode* current);
void destruct(TreeNode*& current);

#endif // BTREE_H