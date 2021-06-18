#include "comp6771/word_ladder.hpp"

#include <string>
#include <vector>

#include "catch2/catch.hpp"

// there should be 2 simple ladders from the new text file.
TEST_CASE("at -> it") {
	auto const english_lexicon = word_ladder::read_lexicon("./enggg.txt");
	auto const ladders = word_ladder::generate("at", "it", english_lexicon);

	CHECK(std::size(ladders) == 2);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"at", "it"}) == 1);
}