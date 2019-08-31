#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
using vectorType = std::vector<int>;

vectorType::iterator partition(vectorType& A, vectorType::iterator lo, vectorType::iterator hi)
{
    if (hi == A.end())
    {
        --hi;
    }

    int pivot = *hi;
    auto i = lo;

    for (auto j = lo; j <= hi; j++)
    {
        if (*j < pivot)
        {
            std::swap(*i, *j);
            ++i;
        }
    }

    std::swap(*i, *hi);
    return i;
}

void quicksort(vectorType& A, vectorType::iterator lo, vectorType::iterator hi)
{
    if (lo < hi)
    {
        auto p = partition(A, lo, hi);
        quicksort(A, lo, p - 1);
        quicksort(A, p + 1, hi);
    }
}

TEST_CASE("Basic Functionality")
{
    std::vector<int> data1{};
    quicksort(data1, data1.begin(), data1.end());
    REQUIRE(data1.empty());

    vectorType data2{3};
    quicksort(data2, data2.begin(), data2.end());
    REQUIRE(data2 == vectorType{3});
}

TEST_CASE("Small Sizes")
{
    vectorType data3{2,124,45,3,34,32,1};
    quicksort(data3, data3.begin(), data3.end());
    REQUIRE(data3 == vectorType{1,2,3,32,34,45,124});

    vectorType data4{4,4,4,4,4,4,4};
    quicksort(data4, data4.begin(), data4.end());
    REQUIRE(data4 == vectorType{4,4,4,4,4,4,4});

    vectorType data5{4,5,4,5,4,5,4};
    quicksort(data5, data5.begin(), data5.end());
    REQUIRE(data5 == vectorType{4,4,4,4,5,5,5});
}

TEST_CASE("Nearly-Sorted Data")
{
    vectorType data6{1,2,3,4,6,5,7,8};
    quicksort(data6, data6.begin(), data6.end());
    REQUIRE(data6 == vectorType{1,2,3,4,5,6,7,8});
}
