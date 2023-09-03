#pragma once

constexpr int kPictureCardsValue = 10;

enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank
{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card
{
public:
    Card();

    void init(Suit suit, Rank rank);

    void setSuit(Suit suit);
    void setRank(Rank rank);
    void setScore(Rank rank);

    int getScore();
    Suit getSuit();
    Rank getRank();

private:
    Suit m_suit;
    Rank m_rank;
    int  m_score;
};
