#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
using vectorType = std::vector<int>;

vectorType::iterator partition(vectorType& A, vectorType::iterator lo, vectorType::iterator hi)
{
    int pivot = *hi;
    auto i = lo;

    for (auto j = lo; lo <= hi - 1; j++)
    {
        if (*j < pivot)
        {
            std::swap(*i, *j);
            ++i;
        }
        std::swap(*i, *hi);
    }

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

bool isVectorSorted(const vectorType& A)
{
    if(A.empty() || A.size() == 1)
    {
        return true;
    }

    for (auto i = A.begin() + 1; i < A.end(); i++)
    {
        if (*(i - 1) > *i)
        {
            return false;
        }
    }

    return true;
}

TEST_CASE("Basic Functionality")
{
    std::vector<int> data1{};
    quicksort(data1, data1.begin(), data1.end());
    REQUIRE(isVectorSorted(data1));
    REQUIRE(isVectorSorted(vectorType{1,2,3,4}));
    REQUIRE(!isVectorSorted(vectorType{1,3,2,4}));

    vectorType data2{3};
    REQUIRE(isVectorSorted(data2));
}

TEST_CASE("Small Sizes")
{
    vectorType data3{2,124,45,3,34,32,1};
    quicksort(data3, data3.begin(), data3.end());
    REQUIRE(isVectorSorted(data3));
}
