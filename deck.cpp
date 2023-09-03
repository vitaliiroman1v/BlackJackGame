#include "deck.hpp"

Deck::Deck()
{
}

void Deck::init()
{
    m_deck.clear();

    for (int suitInt = static_cast<int>(Suit::Hearts); suitInt <= static_cast<int>(Suit::Spades); ++suitInt)
    {
        for (int rankInt = static_cast<int>(Rank::Two); rankInt <= static_cast<int>(Rank::Ace); ++rankInt)
        {
            std::unique_ptr<Card> card = std::make_unique<Card>();
            card->init(static_cast<Suit>(suitInt), static_cast<Rank>(rankInt));
            m_deck.push_back(std::move(card));
        }
    }
}

std::vector<std::unique_ptr<Card>>& Deck::getDeck()
{
    return m_deck;
}