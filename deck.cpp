#include "deck.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <algorithm>

Deck::Deck(QObject* parent) :
    QObject(parent)
{
    // Seed the random number generator
    srand(time(nullptr));
}

void Deck::initialize()
{
    // Clear the deck if it contains any cards
    qDeleteAll(m_cards);
    m_cards.clear();

    // Create a standard deck of 52 cards
    for (int suitInt = static_cast<int>(Suit::Hearts); suitInt <= static_cast<int>(Suit::Spades); ++suitInt)
    {
        for (int rankInt = static_cast<int>(Rank::Two); rankInt <= static_cast<int>(Rank::Ace); ++rankInt)
        {
            Card* card = new Card();
            card->setSuit(static_cast<Suit>(suitInt));
            card->setRank(static_cast<Rank>(rankInt));
            card->setFrontTexture(texture.getCardTexture(suitInt, rankInt));
            card->setBackTexture(texture.getBackCardTexture());
            m_cards.push_back(card);
        }
    }

    // Shuffle the deck
    shuffle();
}

void Deck::shuffle()
{
    // Shuffle the deck using the Fisher-Yates algorithm
    int n = m_cards.size();
    for (int i = n - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        iter_swap(m_cards.begin() + i, m_cards.begin() + j);
    }
}

Card* Deck::dealCard()
{
    if (m_cards.empty())
    {
        return nullptr;
    }

    Card* card = m_cards.back();
    return card;
}

void Deck::backCard()
{
    std::rotate(m_cards.rbegin(), m_cards.rbegin() + 1, m_cards.rend());
}
