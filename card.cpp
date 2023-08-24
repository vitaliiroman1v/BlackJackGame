#include "card.h"

Card::Card(QWidget* parent) : QLabel(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(100, 150);
}

void Card::setSuit(Suit suit)
{
    m_suit = suit;
}

void Card::setRank(Rank rank)
{
    m_rank = rank;
}

void Card::setFrontTexture(const QPixmap& frontTexture)
{
    m_frontTexture = frontTexture.scaled(this->size());
}

void Card::setBackTexture(const QPixmap& backTexture)
{
    m_backTexture = backTexture.scaled(this->size());;
}

Suit Card::getSuit() const
{
    return m_suit;
}

Rank Card::getRank() const
{
    return m_rank;
}

void Card::showFront()
{
    setPixmap(m_frontTexture);
}

void Card::showBack()
{
    setPixmap(m_backTexture);
}
