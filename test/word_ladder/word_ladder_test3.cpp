#include "comp6771/word_ladder.hpp"

#include <string>
#include <vector>

#include "catch2/catch.hpp"

// No ladder exists case
TEST_CASE("airplane -> tricycle") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
	auto const ladders = word_ladder::generate("airplane", "tricycle", english_lexicon);

	CHECK(std::size(ladders) == 0);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"airplane", "tricycle"}) == 0);
}