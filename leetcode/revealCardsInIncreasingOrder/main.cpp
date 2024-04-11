
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

class Game {
private:
  void printDeck(std::vector<int> deck) {
    std::cout << '[';
    for (int i{0}; i < deck.size(); ++i) {
      std::cout << deck[i];

      if (i < deck.size() - 1)
        std::cout << ',';
    }
    std::cout << ']' << '\n';
  }

  void printMove(std::vector<int> deck, int card, int move) {
    std::cout << "We reveal " << card << ", and move " << move
              << " to the bottom.";
    std::cout << " The deck is now ";
    printDeck(deck);
  }

  void printMove(std::vector<int> deck, int card) {
    std::cout << "We reveal " << card << '.' << '\n';
  }

public:
  void play(std::vector<int> deck) {
    // vector to check if all cards are in increasing order
    int lastNum{deck[0]};

    // bool to check all numbers are greater than the previous
    bool isIncreasing{true};

    while (!deck.empty()) {
      // only one card left
      if (deck.size() == 1) {
        printMove(deck, deck[0]);
        break;
      }

      // 2 cards that are in play
      int card{deck[0]};
      int move{deck[1]};

      // add card to checking vector
      if (card < lastNum)
        isIncreasing = false;

      lastNum = card;

      // pop top and move card to bottom
      deck.erase(deck.begin(), deck.begin() + 2);
      deck.push_back(move);

      // print what happened
      printMove(deck, card, move);
    }

    if (isIncreasing)
      std::cout << "All cards are in increasing order" << '\n';
    else
      std::cout << "NOT all cards are in increasing order" << '\n';
  }
};

class Solution {
public:
  void printDeck(const std::vector<int> &deck) {
    for (const int i : deck) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }

  std::vector<int> deckRevealedIncreasing(std::vector<int> &deck) {
    // sort vector in decending order
    std::sort(deck.begin(), deck.end(), std::greater<int>());

    // reverse order of game
    std::vector<int> result{};

    for (int card{0}; card < deck.size(); ++card) {
      if (result.empty()) {
        result.push_back(deck[card]);
        continue;
      }

      // pull card from back and push to front
      int back{result.back()};
      result.pop_back();
      result.insert(result.begin(), back);

      // insert next value
      result.insert(result.begin(), deck[card]);
    }

    return result;
  }
};

class OnlineSolution {
public:
  std::vector<int> deckRevealedIncreasing(std::vector<int> &deck) {
    sort(deck.begin(), deck.end()); // Sort the deck in increasing order

    int n = deck.size();
    std::vector<int> result(n);
    std::deque<int> indices;

    for (int i = 0; i < n; i++) {
      indices.push_back(i); // Initialize deque with indices 0, 1, 2, ..., n-1
    }

    for (int card : deck) {
      int idx = indices.front(); // Get the next available index
      indices.pop_front();       // Remove the index from the front
      result[idx] = card;        // Place the card in the result array
      if (!indices.empty()) {
        // Move the used index to the end of deque
        indices.push_back(indices.front());
        indices.pop_front(); // Remove the index from the front
      }
    }

    return result;
  }
};

int main() {
  std::vector<int> deck{2, 37, 3, 19, 5, 31, 7, 23, 11, 41, 13, 29, 17};

  Game game = Game();
  // game.play(deck);

  Solution solution = Solution();
  std::vector<int> ans = solution.deckRevealedIncreasing(deck);

  solution.printDeck(ans);

  return 0;
}
