#include "comp6771/word_ladder.hpp"
#include <iostream>

// Please note: it's not good practice to test your code via a main function that does
//  printing. Instead, you should be using your test folder. This file should only really
//  be used for more "primitive" debugging as we know that playing solely with test
//  frameplays might be overwhelming for some.

auto main() -> int {
    auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/enggg.txt");
	auto const ladders = word_ladder::generate("at", "it", english_lexicon);
	for (auto i = 0u; i < ladders.size(); i++) {
		for (auto j = 0u; j < ladders[i].size(); j++) {
			std::cout << ladders[i][j] << " ";
		}
		std::cout << '\n';
	}
	// debug here
}
