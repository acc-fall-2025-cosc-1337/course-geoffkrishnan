#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <func.h>

TEST_CASE("Test get_dna_complement", "hw05") {
    // Normal cases
    REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
    REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
    
    // Single character
    REQUIRE(get_dna_complement("A") == "T");
    REQUIRE(get_dna_complement("T") == "A");
    REQUIRE(get_dna_complement("G") == "C");
    REQUIRE(get_dna_complement("C") == "G");
    
    // Two characters
    REQUIRE(get_dna_complement("AT") == "AT");
    
    // All same character
    REQUIRE(get_dna_complement("AAAA") == "TTTT");
    REQUIRE(get_dna_complement("GGGG") == "CCCC");
    
    // Edge cases - empty string
    REQUIRE_THROWS_AS(get_dna_complement(""), std::invalid_argument);
    
    // Invalid characters
    REQUIRE_THROWS_AS(get_dna_complement("ATCX"), std::invalid_argument);
    REQUIRE_THROWS_AS(get_dna_complement("123"), std::invalid_argument);
    REQUIRE_THROWS_AS(get_dna_complement("HELLO"), std::invalid_argument);
    REQUIRE_THROWS_AS(get_dna_complement("atcg"), std::invalid_argument);
}

TEST_CASE("Test reverse_string", "hw05") {
    // Normal cases
    REQUIRE(reverse_string("AGCTATAG") == "GATATCGA");
    REQUIRE(reverse_string("CGCTATAG") == "GATATCGC");
    
    // Single character
    REQUIRE(reverse_string("A") == "A");
    
    // Two characters
    REQUIRE(reverse_string("AT") == "TA");
    
    // Odd length strings
    REQUIRE(reverse_string("ATC") == "CTA");
    REQUIRE(reverse_string("ATCGA") == "AGCTA");
    
    // Palindromes
    REQUIRE(reverse_string("ATA") == "ATA");
    REQUIRE(reverse_string("GCGC") == "CGCG");
    
    // All same character
    REQUIRE(reverse_string("AAAA") == "AAAA");
    
    // Empty string
    REQUIRE(reverse_string("") == "");
}

TEST_CASE("Test get_gc_content", "hw05") {
    // Normal cases
    REQUIRE(get_gc_content("AGCTATAG") == Approx(0.375).margin(0.001));
    REQUIRE(get_gc_content("CGCTATAG") == Approx(0.50).margin(0.001));
    
    // Single character
    REQUIRE(get_gc_content("G") == Approx(1.0).margin(0.001));
    REQUIRE(get_gc_content("C") == Approx(1.0).margin(0.001));
    REQUIRE(get_gc_content("A") == Approx(0.0).margin(0.001));
    REQUIRE(get_gc_content("T") == Approx(0.0).margin(0.001));
    
    // 100/0 GC content
    REQUIRE(get_gc_content("GGGGCCCC") == Approx(1.0).margin(0.001));  // 100% GC
    REQUIRE(get_gc_content("AAAATTTT") == Approx(0.0).margin(0.001));  // 0% GC
    REQUIRE(get_gc_content("GCGC") == Approx(1.0).margin(0.001));
    REQUIRE(get_gc_content("ATAT") == Approx(0.0).margin(0.001));
    
    // Edge cases - empty string
    REQUIRE_THROWS_AS(get_gc_content(""), std::invalid_argument);
    
    // Invalid characters
    REQUIRE_THROWS_AS(get_gc_content("ATCX"), std::invalid_argument);
    REQUIRE_THROWS_AS(get_gc_content("123"), std::invalid_argument);
}