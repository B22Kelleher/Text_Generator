// Copyright 2025 Brendan Kelleher
#define BOOST_TEST_MODULE NBodyTest
#include <sstream>
#include<string>
#include <boost/test/included/unit_test.hpp>
#include "./RandWriter.hpp"



BOOST_AUTO_TEST_SUITE(RandWriterTestSuite)

BOOST_AUTO_TEST_CASE(Constructor_ValidInput_BuildsModelCorrectly) {
    RandWriter rw("abcabc", 2);

    BOOST_CHECK_EQUAL(rw.orderK(), 2);
    BOOST_CHECK_EQUAL(rw.freq("ab"), 2);
    BOOST_CHECK_EQUAL(rw.freq("ab", 'c'), 2);
    BOOST_CHECK_EQUAL(rw.freq("bc", 'a'), 2);
}

BOOST_AUTO_TEST_CASE(Constructor_KTooLarge_Throws) {
    BOOST_CHECK_THROW(RandWriter("abc", 4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Freq_KgramNotFound_ReturnsZero) {
    RandWriter rw("aaaaa", 2);
    BOOST_CHECK_EQUAL(rw.freq("bb"), 0);
    BOOST_CHECK_EQUAL(rw.freq("aa", 'b'), 0);
}

BOOST_AUTO_TEST_CASE(Freq_KgramWrongLength_Throws) {
    RandWriter rw("aaaaa", 2);
    BOOST_CHECK_THROW(rw.freq("a"), std::invalid_argument);
    BOOST_CHECK_THROW(rw.freq("aaa", 'a'), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Freq_KIsZero_CountsCorrectly) {
    RandWriter rw("aabbab", 0);
    BOOST_CHECK_EQUAL(rw.freq("", 'a'), 3);
    BOOST_CHECK_EQUAL(rw.freq("", 'b'), 3);
    BOOST_CHECK_EQUAL(rw.freq("", 'c'), 0);
}

BOOST_AUTO_TEST_CASE(KRand_ValidInput_ReturnsExpectedChar) {
    RandWriter rw("abcabc", 2);

    std::string kgram = "ab";
    char result = rw.kRand(kgram);
    BOOST_CHECK(result == 'c');
}

BOOST_AUTO_TEST_CASE(KRand_InvalidKgram_Throws) {
    RandWriter rw("abcabc", 2);
    BOOST_CHECK_THROW(rw.kRand("zz"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(Generate_ValidInput_GeneratesCorrectLength) {
    RandWriter rw("abcabc", 2);
    std::string gen = rw.generate("ab", 10);
    BOOST_CHECK_EQUAL(gen.length(), 10);
    BOOST_CHECK_EQUAL(gen.substr(0, 2), "ab");
}

BOOST_AUTO_TEST_CASE(Generate_InvalidKgramLength_Throws) {
    RandWriter rw("abcabc", 2);
    BOOST_CHECK_THROW(rw.generate("a", 10), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
