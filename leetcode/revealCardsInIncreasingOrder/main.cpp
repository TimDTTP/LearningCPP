
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
  std::vector<int> deckRevealedIncreasing(std::vector<int> &deck) {
    // lorem ipsum

    return deck;
  }
};

int main() {
  std::vector<int> deck{2, 37, 3, 19, 5, 31, 7, 23, 11, 41, 13, 29, 17};

  Game game = Game();
  game.play(deck);

  return 0;
}
