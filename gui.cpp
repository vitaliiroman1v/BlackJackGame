#include "gui.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "deck.h"

GUI::GUI(QWidget *parent) : QMainWindow{parent}
{
    setFixedSize(1200, 800);

    // Create a layout for the GUI
    QVBoxLayout *layout = new QVBoxLayout();
    deck = new Deck();
    deck->initialize();
    deck->shuffle();

    // Create a label to display the top card
    topCard = deck->dealCard();
    topCard->setAlignment(Qt::AlignCenter);
    topCard->showFront();
    layout->addWidget(topCard);

    // Create a "Next" button to change the card
    QPushButton *nextButton = new QPushButton("Next", this);
    connect(nextButton, &QPushButton::clicked, this, &GUI::showNextCard);
    layout->addWidget(nextButton);

    // Set the layout for the main window
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Initialize the deck and show the top card
    currentCardIndex = 0;
    showNextCard();
}

void GUI::showNextCard()
{
    deck->backCard();
    topCard = deck->dealCard();

    topCard->showFront();
    // Update the displayed card in the GUI
    topCard->setAlignment(Qt::AlignCenter);
    layout()->addWidget(topCard);
}

