#include <iostream>
#include <string>
#include <sstream>
#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}
//test1 with returing XOR bit
BOOST_AUTO_TEST_CASE(test1) {

  FibLFSR test1("1011011000110110");
  BOOST_REQUIRE(test1.step() == 0);
  BOOST_REQUIRE(test1.step() == 0);
  BOOST_REQUIRE(test1.step() == 0);
  BOOST_REQUIRE(test1.step() == 1);
  BOOST_REQUIRE(test1.step() == 1);
  BOOST_REQUIRE(test1.step() == 0);
  BOOST_REQUIRE(test1.step() == 0);
  BOOST_REQUIRE(test1.step() == 1);
}
//test2 with testing if the last 5 bits equal to the decimal representation
BOOST_AUTO_TEST_CASE(test2) {

  FibLFSR test2("1011011000110110");
  BOOST_REQUIRE(test2.generate(5) == 3);


}












