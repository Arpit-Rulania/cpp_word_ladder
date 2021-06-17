#include "comp6771/word_ladder.hpp"
#include <vector>
#include <string>
#include <queue>
#include <utility>

// Write your implementation here
auto generate(std::string const& from, std::string const& to,
              std::unordered_set<std::string> const& lexicon)
	          -> std::vector<std::vector<std::string>> {

    // First create a vector of vectors that will contain all ladders.
    std::vector<std::vector<std::string>> ladders;
    // Next we need a queue so we can do a bfs on the lexicon.
    std::queue<std::vector<std::string>> lque;

    // Now we need to add the starting word to the queue as a vector.
    auto firstWord = std::vector<std::string>{from};
    lque.push(firstWord);

    // Now we perform the breadth first search.
    while(lque.empty() == false) {
        auto popLadder = lque.pop();
        // Now make sure we are looking at the last word in the intermediate ladder.
        auto currNode = popLadder.back();
        // Stop the search if we have the target word.
        if (currNode.compare(to)) {
            // Adding a valid ladder to our list of ladders.
            ladders.push_back(std::move(popLadder));
        } else {
            // Get all the neighbors to the current popped word.
            auto nextLevel = getNeighbors(currNode, to, lexicon);
            while (nextLevel.empty() == false) {
                // Get each word from the list of neighbors.
                auto newWord = nextLevel.pop_back();
                // Copy the older ladder we popped from the queue.
                auto newInsertion = popLadder;
                // Add the neighbor to the end of the copied old ladder.
                newInsertion.push_back(std::move(newWord));
                /* Finally push the incomplete or complete ladder back to
                   the queue for further observation. */
                lque.push(newInsertion);
            }
        }
    }
    return ladders;
}

auto getNeighbors(std::string const& node, std::string const& to,
                  std::unordered_set<std::string> const& lexicon)
                  ->  <std::vector<std::string> {

    /* We go through each letter of the word and change it a-z
       but if the letter in both source and destination same then
       we do nothing to that character and move to the next one*/
    <std::vector<std::string> adjcen;
    auto i = 0;
    for (auto iter = node.begin(); iter != node.end(); ++iter) {
        if(to(i) != *iter) {

        }
        i++;
    }

}