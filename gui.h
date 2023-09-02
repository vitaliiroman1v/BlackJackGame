#ifndef GUI_H
#define GUI_H

#include <QMainWindow>

class Card;
class Deck;
class QLabel;

class GUI : public QMainWindow
{
    Q_OBJECT
public:
    explicit GUI(QWidget *parent = nullptr);
    void showTopCard();
    void showNextCard();
signals:

private:
    Deck *deck;
    Card* topCard;  // Member variable to hold the top car
    int currentCardIndex;
};

#endif // GUI_H
