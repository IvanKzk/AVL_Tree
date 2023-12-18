# AVL_Tree

# Google Tests Results

![Alt text](https://github.com/IvanKzk/AVL_Tree/blob/dev/tests/coverage/screenshot1.png?raw=true)

![Alt text](https://github.com/IvanKzk/AVL_Tree/blob/dev/tests/coverage/screenshot2.png?raw=true)

# Tests Run Instructions

cd cmake

cmake CMakeLists.txt

make init

make gcov

./tree_gtest

move .gcda and .gcno files from CMakeFiles/tree_gtest.dir/... to CMakeFiles/tree_gtest.dir

make gcov

geninfo CMakeFiles/tree_gtest.dir/src.gcda -o coverage.info

genhtml coverage.info -o coverage

# Report generation

cd latex\ report

pdflatex --file-line-error --synctex=1 --shell-escape Tree\ report.tex 
