#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <vector>
#include "card.h"
#include "textures.h"

class Deck : public QObject
{
    Q_OBJECT

public:
    explicit Deck(QObject* parent = nullptr);

    void initialize();
    void shuffle();
    Card* dealCard();
    void backCard();

private:
    std::vector<Card*> m_cards;
    Textures texture;
};

#endif // DECK_H
