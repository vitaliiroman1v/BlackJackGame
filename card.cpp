#include "card.hpp"

Card::Card()
{

}

void Card::init(Suit suit, Rank rank)
{
    setSuit(suit);
    setRank(rank);
    setScore(rank);
}

void Card::setSuit(Suit suit)
{
    m_suit = suit;
}

void Card::setRank(Rank rank)
{
    m_rank = rank;
}

void Card::setScore(Rank rank)
{
    if (rank == Rank::Jack || rank == Rank::Queen || rank == Rank::King)
    {
        m_score = kPictureCardsValue;
    }
    else if (rank == Rank::Ace)
    {
        m_score = 11;
    }
    else
    {
        m_score = static_cast<int>(rank);
    }
}

int Card::getScore()
{
    return m_score;
}

Suit Card::getSuit()
{
    return m_suit;
}

Rank Card::getRank()
{
    return m_rank;
}