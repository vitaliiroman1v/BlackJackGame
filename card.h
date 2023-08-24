#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QMenu>

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

class Card : public QLabel {
    Q_OBJECT

public:
    Card(QWidget* parent = nullptr);

    void setSuit(Suit suit);
    void setRank(Rank rank);
    void setFrontTexture(const QPixmap& frontTexture);
    void setBackTexture(const QPixmap& backTexture);

    Suit getSuit() const;
    Rank getRank() const;

    void showFront();
    void showBack();

private:
    Suit m_suit;
    Rank m_rank;
    QPixmap m_frontTexture;
    QPixmap m_backTexture;
};

#endif // CARD_H
