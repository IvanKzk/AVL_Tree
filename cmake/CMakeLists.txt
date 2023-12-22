cmake_minimum_required(VERSION 3.14)
project(AVL_Tree)

SET(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS
"${CMAKE_CXX_FLAGS} -Wall -pedantic-errors -fsanitize=undefined --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/tree_gtest.dir/src)
message("-- Object files will be output to: ${OBJECT_DIR}")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#enable_testing()

add_executable(
  tree_gtest
  ../gtest.cpp
)
target_link_libraries(
  tree_gtest
  GTest::gtest_main
)

include(GoogleTest)

add_custom_target(init
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )


add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    #COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source diretorie: ${CMAKE_SOURCE_DIR}/src/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
    )
add_dependencies(gcov tree_gtest)

gtest_discover_tests(tree_gtest)