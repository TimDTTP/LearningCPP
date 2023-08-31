
#include <algorithm> // for std::shuffle
#include <array> // for std::array
#include <chrono>
#include <random> // for std::random_device, seed_seq, mt19937
#include <iostream>

/* Disclaimer:
Built upon past code .../cardGame
*/


// all possible card ranks
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

    std::cout << ' ';
}


// initializes deck
std::array<Card, 52> createDeck() {
    std::array<Card, 52> deck{};

    // temporary card
    Card temp;

    int index{ 0 };

    // iterate through CardSuit
    for (int i{ 0 }; i != (static_cast<int>(CardSuit::max_suit)); ++i) {
        temp.suit = static_cast<CardSuit>(i);

        // iterate through CardRank
        for (int k{ 0 }; k != (static_cast<int>(CardRank::max_rank)); ++k) {
            temp.rank = static_cast<CardRank>(k);

            // add to deck
            deck[index] = temp;

            // increment index
            ++index;
        }
    }

    return deck;
}


// print entire deck
void printDeck(const std::array<Card, 52>& deck)  {
    // std::array doesn't decay; retains information on length
    for (int i{ 0 }; i != std::size(deck); ++i) {
        printCard(deck[i]);
    }

    std::cout << '\n';
}


// shuffle deck
void shuffleDeck(std::array<Card, 52>& deck) {
    // create PRNG seed
    std::random_device rd{};
    std::seed_seq ss{
        static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()
    };

    // implement seed into PRNG
    std::mt19937 mt{ ss };

    // shuffle deck
    std::shuffle(deck.begin(), deck.end(), mt);
}


// returns card's value
int getCardValue(const Card& card) {
    switch (card.rank) {
        case CardRank::rank_2 :
            return 2;
        case CardRank::rank_3 :
            return 3;
        case CardRank::rank_4 :
            return 4;
        case CardRank::rank_5 :
            return 5;
        case CardRank::rank_6 :
            return 6;
        case CardRank::rank_7 :
            return 7;
        case CardRank::rank_8 :
            return 8;
        case CardRank::rank_9 :
            return 9;
        case CardRank::rank_10 :
        case CardRank::rank_jack :
        case CardRank::rank_queen :
        case CardRank::rank_king :
            return 10;
        case CardRank::rank_ace:
            return 11;  

        case CardRank::max_rank:
            return 0;

        default:
            return 0;      
    };
}


// blackjack game
bool playBlackjack(const std::array<Card, 52> deck) {
    // each hand
    std::array<Card, 11> player;
    std::array<Card, 11> dealer;

    // index to keep track of current index of shuffled deck
    int index{ 0 };

    // deal cards, 2 each
    for (int i{ 0 }; i < 2; ++i) {
        player[i] = deck[index];
        ++index;

        dealer[i] = deck[index];
        ++index;
    }
}


int main() {
    std::array<Card, 52> deck{ createDeck() };

    shuffleDeck(deck);

    return 0;
}
