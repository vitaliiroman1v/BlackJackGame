#include "blackjack.h"
#include "ui_blackjack.h"

#include "card.h"
#include <QVBoxLayout>

BlackJack::BlackJack(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BlackJack)
{
    ui->setupUi(this);

    // Creating cards
    Card* card1 = new Card;
    card1->setSuit(Suit::Hearts);
    card1->setRank(Rank::Ace);
    card1->setFrontTexture(QPixmap("/home/pypy/Downloads/A-Heart.png"));
    card1->showFront();

    Card* card2 = new Card;
    card2->setSuit(Suit::Clubs);
    card2->setRank(Rank::King);
    card2->setFrontTexture(QPixmap("/home/pypy/Downloads/king_of_clubs.png"));
    card2->showFront();

    // Creating layouts for each card
    QVBoxLayout* card1Layout = new QVBoxLayout;
    card1Layout->addWidget(card1);

    QVBoxLayout* card2Layout = new QVBoxLayout;
    card2Layout->addWidget(card2);

    // Creating a main layout
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(card1Layout);
    mainLayout->addLayout(card2Layout);

    // Creating a central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    // Set the central widget of the main window
    setCentralWidget(centralWidget);
}

BlackJack::~BlackJack()
{
    delete ui;
}

