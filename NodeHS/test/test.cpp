#include "NodeHS.h"
#include "gtest/gtest.h"

TEST(NodeHS, constructor) {
	NodeHS testNode;
	EXPECT_EQ(true, testNode.isEmpty());
	cout<<"Success!\n";
}

