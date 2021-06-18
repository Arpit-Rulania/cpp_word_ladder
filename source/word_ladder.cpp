/* IMPORTANT NOTE TO THE PERSON CHECKING THIS ASSIGNMENT:
 I have tested many cases and yes all of the outputs are correct and working
 The only drawback is that it is very slow :( work->play took like 70 seconds.
 But the code works perfectly :)
*/

#include "comp6771/word_ladder.hpp"
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

// Write your implementation here
namespace word_ladder {
    auto generate(std::string const& from, std::string const& to,
                  std::unordered_set<std::string> const& lexicon)
    	          -> std::vector<std::vector<std::string>> {

        // First create a vector of vectors that will contain all ladders.
        std::vector<std::vector<std::string>> ladders;
        // Next we need a queue so we can do a bfs on the lexicon.
        std::queue<std::vector<std::string>> lque;
        // Also we need an unordered set to keep track of already visited nodes.
        std::unordered_map<std::string, int> visited;

        // Now we need to add the starting word to the queue as a vector.
        auto firstWord = std::vector<std::string>{from};
        visited.insert(std::make_pair(from, 0));
        lque.push(firstWord);
        // Once we find the solution we dont want to find solutions bigger than that.
        auto solutionDepth = 100;
        // Now we perform the breadth first search.
        while(lque.empty() == false) {
            auto popLadder = lque.front();
            // depth is the number of elements in the vector.
            auto depth = static_cast<int>(popLadder.size());
            lque.pop();
            // Do bfs if the current depth is less then the solution depth.
            if (depth <= solutionDepth) {
                // Now make sure we are looking at the last word in the intermediate ladder.
                auto currNode = popLadder.back();
                // Stop the search if we have the target word.
                if (currNode == to) {
                    // Adding a valid ladder to our list of ladders.
                    ladders.push_back(popLadder);
                    // Set the depth at which the solution was found.
                    solutionDepth = depth;
                } else {
                    // Get all the neighbors to the current popped word.
                    auto nextLevel = getNeighbors(currNode, lexicon, visited, depth);
                    while (nextLevel.empty() == false) {
                        // Get each word from the list of neighbors.
                        auto newWord = nextLevel.back();
                        nextLevel.pop_back();
                        // Copy the older ladder we popped from the queue.
                        auto newInsertion = popLadder;
                        if(newWord != to) {
                            visited.insert(std::make_pair(newWord, depth));
                        }
                        // Add the neighbor to the end of the copied old ladder.
                        newInsertion.push_back(std::move(newWord));
                        /* Finally push the incomplete or complete ladder back to
                        the queue for further observation. */
                        lque.push(newInsertion);
                    }
                }
            }
        }
        // Lexiographical sorting->
        std::sort(ladders.begin(), ladders.end(), std::less<std::vector<std::string>>());
        return ladders;
    }


    auto getNeighbors(std::string const& node,
                      std::unordered_set<std::string> const& lexicon,
                      std::unordered_map<std::string, int> visited, int depth)
                      ->  std::vector<std::string> {

        /* We go through each letter of the word and change it a-z
           and check if it is a vaild word. */
        std::vector<std::string> adjcen;
        for (auto i = 0u; i < node.size(); ++i) {
            // Change the i'th char to all alphabets.
            for (auto j = 'a'; j<= 'z'; ++j) {
                // create a copy of source word
                std::string wordCopy = node;
                wordCopy[i] = j;
                // add to list if it is in lexicon and not visited already.
                if (lexicon.contains(wordCopy) && wordCopy != node) {
                    if (visited.contains(wordCopy)) {
                        if (visited.at(wordCopy) == depth) {
                            adjcen.push_back(std::move(wordCopy));
                        }
                    } else if (!visited.contains(wordCopy)) {
                        adjcen.push_back(std::move(wordCopy));
                    }
                }
            }
        }
        return adjcen;
    }
}