#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <string>
#include <vector>
#include "Deck.h"
#include "Field.h"

class Player {
public:
    Deck m_deck;
    Player();
    void SetPlayer(const std::string& name,const Deck& deck);
    const std::string& getName() const;
    void playCard(int cardIndex,int fieldIndex);
    void clearBoard();
    int calculateTotalStrength() const;

    Field m_board;

    bool IsPlayerPassed = false;
    Deck getDeck() const;
    const int StartNumberOfCardsHand = 15;
    std::vector<Card> cardsInHand;
    void drawCard(Player player);
    void removeCardFromHand(int cardIndex);
    void initializeCardsInHand(Player player);
private:
    std::string m_name;


};

#endif // PLAYER_H