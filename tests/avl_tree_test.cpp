#include <gtest/gtest.h>

using namespace std;
using namespace AVL_Tree;

TEST(AVL_Tree, Contstructor_Destructor_Empty) {
    Tree<int> tree;
    ASSERT_TRUE(tree.getRoot() == nullptr);
}

TEST(AVL_Tree, Contstructor_Destructor_Node_AddUtils) {
    Tree<int> tree;
    ASSERT_TRUE(tree.getRoot() == nullptr);

    tree.Add(1);

    ASSERT_FALSE(tree.getRoot() == nullptr);

    Node<int>* min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 1));

    Node<int>* max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 1));

    tree.Add(2);

    ASSERT_FALSE(tree.getRoot() == nullptr);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 1));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 2));

    tree.Add(3);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 1));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 3));

    tree.Add(-1);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -1));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 3));

    Tree<int> tree2(tree);
    ASSERT_FALSE(tree2.getRoot() == nullptr);

    min = tree2.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -1));

    max = tree2.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 3));

    Tree<int> tree3;
    tree3 = tree;
    ASSERT_FALSE(tree3.getRoot() == nullptr);

    min = tree3.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -1));

    max = tree3.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 3));
}

TEST(AVL_Tree, Initializer_list_find_remove) {
    Tree<int> tree({1,-1,-2,-3,-4,2,3,4});
    ASSERT_FALSE(tree.getRoot() == nullptr);

    Node<int>* min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -4));

    Node<int>* max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 4));

    Node<int>* findResult = tree.Find(-3, tree.getRoot());
    ASSERT_TRUE(findResult != nullptr);

    tree.Remove(-3);

    findResult = tree.Find(-3, tree.getRoot());
    ASSERT_TRUE(findResult == nullptr);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -4));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 4));

    tree.Remove(-3);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -4));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 4));

    tree.Remove(4);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -4));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 3));

    tree.Remove(-4);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -2));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 3));

    tree.Remove(3);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -2));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 2));

    tree.Remove(2);

    min = tree.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == -2));

    max = tree.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 1));
}

TEST(AVL_Tree, All_bfactors_add_remove) {
    //case 1a

    Tree<int> tree1({4, 20});
    ASSERT_FALSE(tree1.getRoot() == nullptr);

    tree1.Add(15);

    Node<int>* min = tree1.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 4));

    Node<int>* max = tree1.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 20));


    Tree<int> tree2({3, 4, 9, 20, 26});
    ASSERT_FALSE(tree2.getRoot() == nullptr);

    tree2.Add(15);

    min = tree2.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 3));

    max = tree2.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 26));

    Tree<int> tree3({2, 3, 4, 7, 9, 11, 20, 21, 26, 30});
    ASSERT_FALSE(tree3.getRoot() == nullptr);

    tree3.Add(15);

    min = tree3.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 2));

    max = tree3.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 30));



    //case 1b

    Tree<int> tree4({4, 20});
    ASSERT_FALSE(tree4.getRoot() == nullptr);

    tree4.Add(8);

    min = tree4.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 4));

    max = tree4.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 20));

    Tree<int> tree5({3, 4, 9, 20, 26});
    ASSERT_FALSE(tree5.getRoot() == nullptr);

    tree5.Add(8);

    min = tree5.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 3));

    max = tree5.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 26));

    Tree<int> tree6({2, 3, 4, 7, 9, 11, 20, 21, 26, 30});
    ASSERT_FALSE(tree6.getRoot() == nullptr);

    tree6.Add(8);

    min = tree6.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 2));

    max = tree6.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 30));


    //remove

    Tree<int> tree7({1, 2, 3, 4, 5});

    tree7.Remove(1);

    min = tree7.Min();
    //ASSERT_TRUE((min != nullptr) && (min->getData() == 2));

    max = tree7.Max();
    //ASSERT_TRUE((max != nullptr) && (max->getData() == 5));

    Tree<int> tree8({1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    tree8.Remove(1);

    min = tree8.Min();
    ASSERT_TRUE((min != nullptr) && (min->getData() == 2));

    max = tree8.Max();
    ASSERT_TRUE((max != nullptr) && (max->getData() == 9));
}

TEST(AVL_Tree, index_output) {
    Tree<int> tree({3, 4, 9, 20, 26});
    ASSERT_FALSE(tree.getRoot() == nullptr);
    
    Node<int>* indexResult = tree[0];
    ASSERT_TRUE(indexResult && indexResult->getData() == 3);
    indexResult = tree[4];
    ASSERT_TRUE(indexResult && indexResult->getData() == 26);

    tree.InOrder(tree.getRoot(), cout);
    tree.PostOrder(tree.getRoot(), cout);
    tree.PreOrder(tree.getRoot(), cout);
    tree.AdvOutput(tree.getRoot(), cout);
    for (const auto& el : tree) {
        cout << el.getData() << ' ';
    }
}