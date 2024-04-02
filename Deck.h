#ifndef DECK_H
#define DECK_H
#pragma once
#include <vector>
#include "Card.h"
class Deck {
public:
    void addCard(const Card& card);
    const Card& drawCard();
    // Cards count from top ,topCard`s index is 0
    std::vector<Card> cardsInDeck;
private:

};

#endif // DECK_H