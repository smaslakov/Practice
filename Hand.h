#include <vector>
#pragma once
#include "card.h"
#include "player.h"
#include "deck.h"
#ifndef NEWPROJECT_HAND_H
#define NEWPROJECT_HAND_H


class Hand {
private:
    const int StartNumberOfCardsHand = 15;
    const int MaxNumberOfCardsHand = 30;
public:
    std::vector<Card> cardsInHand;
    void drawCard(Player player);
    void removeCardFromHand(int cardIndex);
    void initializeCardsInHand(Player player);
};


#endif //NEWPROJECT_HAND_H
