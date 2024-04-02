#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
class Player {
public:
    Deck m_deck;
    Hand hand;
    Player();
    void SetPlayer(const std::string& name,const Deck& deck);
    const std::string& getName() const;
    void playCard(int cardIndex);
    void clearBoard();
    int calculateTotalStrength() const;
    std::vector<Card> m_board;
    bool IsPlayerPassed = false;
    void ChangeFlagPass();
    Deck getDeck() const;
private:
    std::string m_name;


};

#endif // PLAYER_H