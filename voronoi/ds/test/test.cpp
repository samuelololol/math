#include <gtest/gtest.h>
#include <boost/rational.hpp>
#include "../node.h"
#include "../line.h"

rational<int> rn1(1, 3);
rational<int> rn2(1, 7);
rational<int> rn3(-18, 8);

TEST(test_node, test_node){
    node_t n1;
    node_t n2(0, 1);
    node_t n3(rn1, rn2);
    node_t n4(n3);
    node_t n5;

    ASSERT_NE(n1, n2);
    ASSERT_EQ(n3, n4);
    ASSERT_THROW(n1==n5, nodeexception);
}

TEST(test_line, test_line){
    node_t n1;
    node_t n2(0, 1);
    node_t n3(rn1, rn2);

    line_t l1;
    line_t l2(n1, n2);
    line_t l3(n2, n3);
    line_t l4(false, rn3, n3);
    line_t l5;
    l5 = l4;
    line_t l6 = l4.normalline(n3);
    node_t nx = l6*l4;

    ASSERT_EQ(l6.ison(nx), true);
    ASSERT_EQ(l4.ison(nx), true);
    ASSERT_NE(l4.ison(n1), true);
    ASSERT_THROW(l1.getm(), lineexception);
    ASSERT_NE(l2, l3);
    ASSERT_EQ(l5, l4);
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

