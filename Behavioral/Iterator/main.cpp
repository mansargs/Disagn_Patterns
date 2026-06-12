#include <iostream>
#include <gtest/gtest.h>
#include "Collection.hpp"
#include "Iterator.hpp"

TEST(InorderIteratorTest, EmptyTree) {
	BinaryTree tree;
	Iterator* it = tree.createIterator();
	EXPECT_FALSE(it->hasNext());
	delete it;
}

TEST(InorderIteratorTest, SingleElement) {
	BinaryTree tree;
	tree.insert(42);

	Iterator* it = tree.createIterator();

	ASSERT_TRUE(it->hasNext());
	EXPECT_EQ(it->next(), 42);
	EXPECT_FALSE(it->hasNext());

	delete it;
}

TEST(InorderIteratorTest, LeftSkewedTree) {
	BinaryTree tree;

	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);

	Iterator* it = tree.createIterator();

	std::vector<int> result;
	while (it->hasNext()) {
		result.push_back(it->next());
	}

	delete it;

	std::vector<int> expected = {1, 2, 3, 4, 5};
	EXPECT_EQ(result, expected);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
