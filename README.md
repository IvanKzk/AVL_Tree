# AVL_Tree


cd cmake

cmake CMakeLists.txt

make init

make gcov

./tree_gtest

# move .gcda and .gcno files from CMakeFiles/tree_gtest.dir/... to CMakeFiles/tree_gtest.dir

# make gcov

geninfo CMakeFiles/tree_gtest.dir/src.gcda -o coverage.info

genhtml coverage.info -o coverage