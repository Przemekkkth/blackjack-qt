#ifndef DECK_H
#define DECK_H
#include <array>
#include <QVector>
#include <QString>
#include "card.h"
class Deck
{
public:
    Deck();
    void fill();
    Card removeCard(int index);
    int cardCount() const;
    void takeCard(QVector<Card>& hand);
    int getTotal(QVector<Card>& hand);
private:
    const std::array<QString, 4> m_cardTypes;
    QVector<Card> m_cards;
};

#endif // DECK_H
