#pragma once

#include "Iterator.hpp"

struct Node {
	int value;
	Node* left;
	Node* right;

	Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
	private:
		Node* root;
		void insertNode(Node*& node, int value);

	public:
		BinaryTree() : root(nullptr) {}

		void insert(int value);
		Iterator* createIterator() const;
		Node* getRoot() const { return root; }
};
