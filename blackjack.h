#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BlackJack; }
QT_END_NAMESPACE

class BlackJack : public QMainWindow
{
    Q_OBJECT

public:
    BlackJack(QWidget *parent = nullptr);
    ~BlackJack();

private:
    Ui::BlackJack *ui;
};
#endif // BLACKJACK_H
