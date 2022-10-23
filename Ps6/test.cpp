#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "RandWriter.h"

BOOST_AUTO_TEST_CASE(Consturctor){
	BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 2));
	BOOST_REQUIRE_THROW(RandWriter("", 3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(kOrder){
	RandWriter mm("gagggagaggcgagaaa", 2);
	RandWriter m2("gagggagaggcgagaaa", 5);
	
	BOOST_REQUIRE(mm.orderK() == 2);
	BOOST_REQUIRE(m2.orderK() == 5);
	
}

BOOST_AUTO_TEST_CASE(freq){
	RandWriter mm("gagggagaggcgagaaa", 2);
	
	BOOST_REQUIRE(mm.freq("ga") == 5);
	BOOST_REQUIRE(mm.freq("aa") == 2);
	
	BOOST_REQUIRE_THROW(mm.freq("www"), std::runtime_error);
	BOOST_REQUIRE_THROW(mm.freq("rwv"), std::runtime_error);
	
	BOOST_REQUIRE_THROW(mm.freq("www", 'c') != 1, std::runtime_error);
	BOOST_REQUIRE_THROW(mm.freq("gag", 'c') != 1, std::runtime_error);
}

BOOST_AUTO_TEST_CASE(kRand){
	RandWriter mm("gaggaggaggaggagagagagagagaggagaggcgagaaa", 2);
	RandWriter m2("gaaaagaaaagaaaag", 5);
	
	BOOST_REQUIRE(mm.kRand("ga") == 'g');
	BOOST_REQUIRE(m2.kRand("gaaaa") == 'g');
	
	BOOST_REQUIRE_THROW(mm.kRand("ggg") == 'a', std::runtime_error);
	BOOST_REQUIRE_THROW(m2.kRand("burp") != 'g', std::runtime_error);
}

BOOST_AUTO_TEST_CASE(OTHERS){
	RandWriter mm("gagggagaggcgagaaa", 2);
	BOOST_REQUIRE(mm.orderK() == 2);
}
