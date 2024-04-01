#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    void addCard(const Card& card);
    const Card& drawCard();
    // Cards count from top ,topCard`s index is 0
    std::vector<Card> cardsInDeck;// Должен быть private, но хахахаха я инкапсулятор
private:

};

#endif // DECK_H