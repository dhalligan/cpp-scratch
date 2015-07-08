/*
 * This is an example unit test that doesn't really do anything useful.
 * It is here as a reference for you when creating additional unit tests.
 * For additional reference information, see the "test.h" header.
 */

// #include "test.h" // Brings in the UnitTest++ framework

#include <catch.hpp>

#include "Recursion.h"

TEST_CASE("one equals one", "[one]") {
  int one = 1;
  REQUIRE( one == 1 );
}

TEST_CASE( "Phone number letters 1", "[phone_number_1]" ) {
  vector<string> result {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  PhoneNumber pn;
  REQUIRE( pn.compute("23") == result );
}

TEST_CASE( "Word search", "[word_search]") {
  WordSearch ws;
  vector<vector<char> > board {{'A', 'B', 'C', 'D'}, {'E', 'F', 'G', 'H'}, {'I', 'J', 'K', 'L'}, {'M', 'N', 'O', 'P'}};
  REQUIRE( ws.search(board, "ABFJN") == true );
}

TEST_CASE( "Fibonacci", "[fibonacci]") {
  Fibonacci fib;
  REQUIRE( fib.compute_dp(50) == fib.compute(50) );
}

TEST_CASE( "Factorial", "[factorial]") {
  Factorial f;
  REQUIRE( f.compute(50) == f.compute_recursive(50) );
  REQUIRE( f.compute_recursive(50) == f.compute_tail_recursive(50) );
  REQUIRE( f.compute(50) == Fact<50>::value );
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
