#include "comp6771/word_ladder.hpp"

#include <string>
#include <vector>

#include "catch2/catch.hpp"

// No ladder exists for this case either
TEST_CASE("humans -> mutant") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
	auto const ladders = word_ladder::generate("humans", "mutant", english_lexicon);

	CHECK(std::size(ladders) == 0);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"humans", "mutant"}) == 0);
}