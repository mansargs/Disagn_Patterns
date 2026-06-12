#include "Collection.hpp"
#include "ConcreteIterator.hpp"

void BinaryTree::insertNode(Node*& node, int value) {
	if (node == nullptr) {
		node = new Node(value);
	} else if (value < node->value) {
		insertNode(node->left, value);
	} else {
		insertNode(node->right, value);
	}
}

void BinaryTree::insert(int value) {
	insertNode(root, value);
}

Iterator* BinaryTree::createIterator() const {
	return new InorderIterator(root);
}
