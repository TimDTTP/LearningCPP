 
#include <algorithm> // for std::shuffle
#include <array> // for std::array
#include <chrono>
#include <random> // for std::random_device, seed_seq, mt19937
#include <string_view> // for std::string_view
#include <vector> // for std::vector
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


// print current player's hand, excluding 0's
void printHand(const std::vector<Card>& hand) {
    for(auto i : hand) {
        printCard(i);
    }

    std::cout << '\n';
}


// banner for blackjack
void banner() {
    for (int i{ 0 }; i < 50; ++i) {
        std::cout << '*';
    }
    std::cout << '\n';
}


// spacer for in between blackjack rounds
void spacer(int spacer) {
    for (int i{ 0 }; i < spacer; ++i) {
        std::cout << "---" << '\n';
    }
}


// function to handle excess string in std::cin buffer
void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// verify std::cin success
void cinCleanup(bool cinSuccess) {
    if (cinSuccess)
    {
        if (std::cin.eof())
            exit(0);

        std::cin.clear();
        ignoreLine();

        // error message
        std::cout << "Invalid input, try again!\n";
    }
    else
        ignoreLine();
}


// get hand total
int handTotal(const std::vector<Card>& hand) {
    int temp{ 0 };
    for (auto i : hand) {
        temp += getCardValue(i);
    }
    
    return temp;
}


// hit or stay (blackjack)
int thePlay(const std::array<Card, 52>& deck, int& index, std::vector<Card> person) {
    // true = hit, false = stay
    bool decision{ true };

    // if user input is valide
    bool inputValid{ false };

    // continue to ask, hit or stay
    while (decision){
        // check if current hand is above 21
        if (handTotal(person) > 21) {
            std::cout << "**BUSTED**\n\n";
            return handTotal(person);
        }

        // client inquiry; hit(continue) stay(exit)
        do {
            int userInput;
            std::cout << "Would you like to...\n" << "1) Hit\n" << "2) Stay\n" << "Choice: ";
            std::cin >> userInput;
            std::cout << '\n';

            // clear std::cin
            cinCleanup(!std::cin);

            if (userInput == 1) {
                inputValid = true;
                decision = true;
            }
            else if (userInput == 2) {
                inputValid = true;
                decision = false;
            }
            else {
                std::cout << "Invalid\n";
                continue;
            }
        }
        while (!inputValid);

        // in scenario of "Hit"
        if (decision) {
            // Note: std::vector does NOT decay
            // Note: std::size will return type, std::size_t

            // add next value to "hand" and increment next card in shuffled deck
            person.resize((static_cast<int>(std::size(person)) + 1));
            person[(static_cast<int>(std::size(person)) - 1)] = deck[index];

            std::cout << "Card: ";
            printCard(deck[index]);
            std::cout << '\n';
            
            std::cout << "Your new hand: ";
            printHand(person);
            std::cout << '\n';
            spacer(1);
            std::cout << '\n';

            ++index;
        }

        // in scenario of "Stay"
        if (!decision) {
            // print hand and quit
            std::cout << "Alright, your hand is: ";
            printHand(person);

            std::cout << '\n';
            spacer(1);
            std::cout << '\n';

            std::cout << "Which ends up as a total of ";
            std::cout << handTotal(person) << '\n'; 
        }
    }

    std::cout << '\n';
    
    return handTotal(person);
}


// blackjack game
bool playBlackjack(const std::array<Card, 52> deck) {
    // space out for readability
    for (int i{ 0 }; i < 5; ++i)
        std::cout << '\n';

    
    // welcome message
    banner();
    std::cout << "Welcome to Blackjack!\n";
    banner();


    // each hand, max amount of cards is 11
    std::vector<Card> player(2);
    int playerHandTotal;

    std::vector<Card> dealer(2);
    int dealerHandTotal;


    // index to keep track of current index of shuffled deck
    int index{ 0 };

    // deal cards, 2 each
    std::cout << "\nDealing cards..." << '\n';
    for (int i{ 0 }; i < 2; ++i) {
        player[i] = deck[index];
        ++index;

        dealer[i] = deck[index]; 
        ++index;
    }


    // show each player their cards
    std::cout << "Player's hand: "; 
    printHand(player);

    std::cout << "Dealer's hand: ";
    printHand(dealer);
    std::cout << '\n';


    // player's turn
    banner();
    std::cout << "Player's turn\n";
    printHand(player);
    banner();

    playerHandTotal = thePlay(deck, index, player);
    if (playerHandTotal > 21)
        return false;


    // dealer's turn
    banner();
    std::cout << "Dealer's turn\n";
    printHand(dealer);
    banner();

    dealerHandTotal = thePlay(deck, index, dealer);
    if (dealerHandTotal > 21)
        return true;

    // results if both players did NOT bust
    if (playerHandTotal > dealerHandTotal)
        return true;
    else if (playerHandTotal < dealerHandTotal)
        return false;
    else // in cases of a tie, player wins
        return true;
}


int main() {
    std::array<Card, 52> deck{ createDeck() };

    shuffleDeck(deck);

    bool winCondition{ playBlackjack(deck) };

    banner();
    if (winCondition) {
        std::cout << "You Win!\n";
    }
    else {
        std::cout << "You Lost!\n";
    }
    banner();
    

    return 0;
}
