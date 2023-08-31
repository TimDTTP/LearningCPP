
#include <iostream>

enum class CardRank {
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_rank,
};


// all possible card suits
enum class CardSuit {
    suit_spades,
    suit_clubs,
    suit_diamonds,
    suit_hearts,

    max_suit,
};


// each card
struct Card {
    CardRank rank{};
    CardSuit suit{};
};


// prints each card with corresponding Char
void printCard(const Card& card) {
    switch (card.rank) {
        case CardRank::rank_2:
            std::cout << "2";
            break;
        case CardRank::rank_3:
            std::cout << "3";
            break;
        case CardRank::rank_4:
            std::cout << "4";
            break;
        case CardRank::rank_5:
            std::cout << "5";
            break;
        case CardRank::rank_6:
            std::cout << "6";
            break;
        case CardRank::rank_7:
            std::cout << "7";
            break;
        case CardRank::rank_8:
            std::cout << "8";
            break;
        case CardRank::rank_9:
            std::cout << "9";
            break;
        case CardRank::rank_10:
            std::cout << "10";
            break;
        case CardRank::rank_jack:
            std::cout << "J";
            break;
        case CardRank::rank_queen:
            std::cout << "Q";
            break;
        case CardRank::rank_king:
            std::cout << "K";
            break;
        case CardRank::rank_ace:
            std::cout << "A";
            break;

        case CardRank::max_rank:
            std::cout << static_cast<int>(CardRank::max_rank);
            break;

        default:
            std::cout << "\nNot an available suit\n";
            break;
    }

    switch (card.suit) {
        case CardSuit::suit_spades:
            std::cout << "S";
            break;
        case CardSuit::suit_clubs:
            std::cout << "C";
            break;
        case CardSuit::suit_diamonds:
            std::cout << "D";
            break;
        case CardSuit::suit_hearts:
            std::cout << "H";
            break;

        case CardSuit::max_suit:
            std::cout << static_cast<int>(CardSuit::max_suit);
            break;

        default:
            std::cout << "\nNot an available suit\n";
            break;
    }

    std::cout << '\n';
}


// create deck
std::array<Card, 52> createDeck() {
    std::array<Card, 52> deck{};

    // iterate through array
    for (int iter{0}; auto cardArray : deck) {
        // temporary card
        Card temp;

        // iterate through CardSuit
        for (int i{ 0 }; i != (static_cast<int>(CardSuit::max_suit)); ++i) {
            temp.suit = static_cast<CardSuit>(i);

            // iterate through CardRank
            for (int k{ 0 }; k != (static_cast<int>(CardRank::max_rank)); ++k) {
                temp.rank = static_cast<CardRank>(k);
            }
        }

        // add card to index location
        deck[iter] = temp;

        ++iter;
    }

    return deck;
}
/* Problem:
The first loop is constantly repeating the iteration within.
This is causing only the last iteration to be assigned to the deck.
*/

int main() {
    std::array<Card, 52> deck{ createDeck() };

    for (auto i : deck) {
        printCard(i);
    }

    return 0;
}