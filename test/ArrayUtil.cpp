/*
 * This is an example unit test that doesn't really do anything useful.
 * It is here as a reference for you when creating additional unit tests.
 * For additional reference information, see the "test.h" header.
 */

// #include "test.h" // Brings in the UnitTest++ framework

#include <catch.hpp>

#include "ArrayUtil.h"

TEST_CASE("Maximum subarray", "[maximum_subarray]") {
  vector<int> v {-1, -2, -3, 1, 2, 3, -4, 5, -6};
  REQUIRE( maximum_subarray(v) == 7 );
}

TEST_CASE("Majority element", "[majority_element]") {
  vector<int> v {1, 2, 3, 1, 0, 1, 4, 5, 1, 2};
  REQUIRE( majority_element(v) == 1 );
}

/*
 TEST(sanity_check) // Declares a test named "sanity_check"
 {
    CHECK(true); // We certainly hope that true is true
    CHECK_EQUAL(2,1+1); // The value 1+1 should equal 2

    int x[] = {1,2,3};
    int y[] = {1,2,3};
    CHECK_ARRAY_EQUAL(x,y,3); // These arrays of length 3 are equal

    double a = 1.51;
    double b = 1.52;
    CHECK_CLOSE(a,b,0.1); // These equal within 0.1
}
*/
