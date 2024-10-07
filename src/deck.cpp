#include "deck.h"
#include <QRandomGenerator>
#include <QVector>

Deck::Deck()
    : m_cardTypes{ {"club", "diamond", "heart", "spade"} }
{
    fill();
}

void Deck::fill()
{
    m_cards.clear();
    for (const QString &type : m_cardTypes) {
        for (int i = 1; i <= 13; ++i) {
            Card card;
            card.suit = type;
            card.rank = i;
            m_cards.push_back(card);
        }
    }
}

Card Deck::removeCard(int index)
{
    Card retValue = m_cards[index];
    m_cards.removeAt(index);
    return retValue;
}

int Deck::cardCount() const
{
    return m_cards.size();
}

void Deck::takeCard(QVector<Card> &hand)
{
    int idx = QRandomGenerator::global()->generate() % cardCount();
    Card card = removeCard(idx);
    hand.push_back(card);
}

int Deck::getTotal(QVector<Card> &hand)
{
    int total = 0;
    int hasAce = false;
    for (int i = 0; i < hand.size(); ++i) {
        if (hand.at(i).rank > 10) {
            total += 10;
        }
        else {
            total += hand.at(i).rank;
        }

        if (hand.at(i).rank == 1) {
            hasAce = true;
        }
    }

    if (hasAce && total < 11) {
        total = total + 10;
    }

    return total;
}
