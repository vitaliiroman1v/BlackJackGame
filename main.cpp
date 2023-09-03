#include <iostream>

#include "deck.hpp"

void printDeck(Deck& deck)
{
    std::vector<std::unique_ptr<Card>> &cards = deck.getDeck();

    std::cout << "Suit\tRank\tScore\n";

    for (const auto& el : cards)
    {
        std::cout << static_cast<int>(el->getSuit()) << "\t"
                  << static_cast<int>(el->getRank()) << "\t"
                  << el->getScore() << "\n";
    }
}

int main()
{
    Deck deck;
    deck.init();
    printDeck(deck);
    return 0;
}