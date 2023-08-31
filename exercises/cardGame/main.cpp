
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


enum class CardSuit {
    suit_spades,
    suit_clubs,
    suit_diamonds,
    suit_hearts,

    max_suit,
};


struct Card {
    CardRank rank{};
    CardSuit suit{};
};


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
    }

    std::cout << ' ';
}


int main() {
    Card card{};
    card.rank = CardRank::rank_ace;
    card.suit = CardSuit::suit_hearts;

    printCard(card);

    return 0;
}
