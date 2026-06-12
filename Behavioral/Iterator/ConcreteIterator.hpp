#pragma once

#include "Iterator.hpp"
#include <stack>
#include "Collection.hpp"

class InorderIterator : public Iterator {
	private:
		Node* curr;
		std::stack<Node*> st;
	public:
		InorderIterator(Node* root) : curr(root) {}

		bool hasNext() const override {
			return curr != nullptr || !st.empty();
		}

		int next() override {
			while (curr) {
				st.push(curr);
				curr = curr->left;
			}
			Node* t = st.top();
			st.pop();
			int value = t->value;
			curr = t->right;
			return value;
		}
};
