#include <gtest/gtest.h>

using namespace std;
using namespace AVL_Tree;

TEST(AVL_Tree_Node, Node_Functional) {
    Node<int> n;

    ASSERT_TRUE(n.getHeight() == 1);
    ASSERT_TRUE(n.getLeft() == nullptr);
    ASSERT_TRUE(n.getRight() == nullptr);
    ASSERT_TRUE(n.getParent() == nullptr);

    int i = 1;
    Node<int> new_n = Node<int>(i);
    ASSERT_TRUE(new_n.getData() == i);

    n.setHeight(2);
    ASSERT_TRUE(n.getHeight() == 2);
    ASSERT_TRUE(n.getLeft() == nullptr);
    ASSERT_TRUE(n.getRight() == nullptr);
    ASSERT_TRUE(n.getParent() == nullptr);

    n.setParent(&new_n);
    ASSERT_TRUE(n.getHeight() == 2);
    ASSERT_TRUE(n.getLeft() == nullptr);
    ASSERT_TRUE(n.getRight() == nullptr);
    ASSERT_TRUE(n.getParent() == &new_n);

    n.setLeft(&new_n);
    ASSERT_TRUE(n.getHeight() == 2);
    ASSERT_TRUE(n.getLeft() == &new_n);
    ASSERT_TRUE(n.getRight() == nullptr);
    ASSERT_TRUE(n.getParent() == &new_n);

    n.setRight(&new_n);
    ASSERT_TRUE(n.getHeight() == 2);
    ASSERT_TRUE(n.getLeft() == &new_n);
    ASSERT_TRUE(n.getRight() == &new_n);
    ASSERT_TRUE(n.getParent() == &new_n);

    n.setData(i);
    ASSERT_TRUE(n.getData() == i);
}