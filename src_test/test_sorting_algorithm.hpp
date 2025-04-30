#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

namespace SortLibrary {

TEST(TestSorting, TestBubbleSort)
    {
        std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
        BubbleSort<int>(v);
        std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
        EXPECT_EQ(v, sortedV);
    }
    
TEST(TestSorting, TestHeapSort)
    {
        std::vector<int> v = {19, 113, 5, 10, 1, 7, 9, 4, 7, 12};
        HeapSort<int>(v,v.size());
        std::vector<int> sortedV = {1, 4, 5, 7, 7, 9, 10, 12 , 19 ,113};
        EXPECT_EQ(v, sortedV);
    }

}
