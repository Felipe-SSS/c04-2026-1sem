#include <iostream>
#include "btree.h"

using namespace std;

static int compareAlphabetic(const string& leftWord, const string& rightWord)
{
	if (leftWord < rightWord) {
		return -1;
	}
    if (leftWord > rightWord) {
		return 1;
	}
    return 0;
}

static int compareBySize(const Word* leftWord, const Word* rightWord)
{
	if (leftWord->word.length() < rightWord->word.length()) {
		return -1;
	}
    if (leftWord->word.length() > rightWord->word.length()) {
		return 1;
	}
    return compareAlphabetic(leftWord->word, rightWord->word);
}

static TreeNode* find_less_save_right(TreeNode*& current)
{
	if (current->left != NULL) {
		return find_less_save_right(current->left);
	} else {
		TreeNode* copy = current;
		current = current->right;
		return copy;
	}
}

void insert(TreeNode*& current, Word* data, int option)
{
	if (current == NULL) {
		current = new TreeNode;
		current->data = data;
		current->left = NULL;
		current->right = NULL;
	} else if (option == 0) {
		if (compareAlphabetic(data->word, current->data->word) < 0) {
			insert(current->left, data, option);
		} else {
			insert(current->right, data, option);
		}
	} else {
		if (compareBySize(data, current->data) < 0) {
			insert(current->left, data, option);
		} else {
			insert(current->right, data, option);
		}
	}
}

bool remove(TreeNode*& current, const string& data, int option)
{
	if (current == NULL) {
		return false;
	} else if (data == current->data->word) {
		TreeNode* temp = current;
		if (current->right == NULL) {
			current = current->left;
		} else if (current->left == NULL) {
			current = current->right;
		} else {
			temp = find_less_save_right(current->right);
			current->data = temp->data;
		}
		delete(temp);
		return true;
	} else {
		if (option == 0) {
			if (data < current->data->word) {
				return remove(current->left, data, option);
			} else {
				return remove(current->right, data, option);
			}
		} else {
			Word probe;
			probe.word = data;
			if (compareBySize(&probe, current->data) < 0) {
				return remove(current->left, data, option);
			} else {
				return remove(current->right, data, option);
			}
		}
	}
}

void show_in_order(TreeNode* current)
{
	if (current != NULL) {
		if (current->left != NULL) {
			show_in_order(current->left);
		}
		cout << current->data->word << " - " << current->data->translation << endl;
		if (current->right != NULL) {
			show_in_order(current->right);
		}
	}
}

void destruct(TreeNode*& current)
{
	if (current != NULL) {
		if (current->left != NULL) {
			destruct(current->left);
		}
		if (current->right != NULL) {
			destruct(current->right);
		}
		delete(current);
		current = NULL;
	}
}
