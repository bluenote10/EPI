#define BOOST_TEST_MODULE TestExample
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(ExampleOfFailTest)
{
  BOOST_CHECK_EQUAL(1,0);
}

/*
int main(int argc, char** argv) {
  return 0;
}
*/

