#include <gtest/gtest.h>
#include <boost/rational.hpp>
#include "../node.h"

TEST(test_node, test_node){
    rational<int> rn1(1, 3);
    rational<int> rn2(1, 7);

    node_t n1;
    node_t n2(0, 1);
    node_t n3(rn1, rn2);
    node_t n5;

    ASSERT_NE(n1, n2);
    ASSERT_THROW(n1==n5, nodeexception);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

