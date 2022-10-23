#include <iostream>
#include <string>
#include <sstream>
#include "CircularBuffer.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test1){
	BOOST_REQUIRE_THROW(CircularBuffer c(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test2){
	CircularBuffer c(12);
	BOOST_REQUIRE(c.isEmpty() == true);
	BOOST_REQUIRE(c.isFull() == false);
}

BOOST_AUTO_TEST_CASE(test3){
	CircularBuffer c(3);
	c.enqueue(1);
	c.enqueue(2);
	c.enqueue(3);
	BOOST_REQUIRE_THROW(c.enqueue(4), std::runtime_error);
	BOOST_REQUIRE(c.dequeue()== 1);
	BOOST_REQUIRE_NO_THROW(c.peek()==2);
	BOOST_REQUIRE(c.dequeue()==2);
	BOOST_REQUIRE(c.dequeue()==3);
	BOOST_REQUIRE_THROW(c.peek(), std::runtime_error);
	
}
