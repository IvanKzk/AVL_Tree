#include <gtest/gtest.h>
#include "AVL_Tree.h"
#include "tests/node_test.cpp"
#include "tests/avl_tree_test.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}