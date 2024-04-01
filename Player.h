#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"

class Player {
public:
    Player(const std::string& name, const Deck& deck);

    const std::string& getName() const;
    void drawCard();
    void playCard(int cardIndex);
    void removeCardFromHand(int cardIndex);
    void clearBoard();
    int calculateTotalStrength() const;

    std::vector<Card> m_board;
    void initializeCardsInHand();
    bool IsPlayerPassed = false;
    void ChangeFlagPass();
    Deck getDeck() const;
private:
    std::string m_name;
    Deck m_deck;
    const int StartNumberOfCardsHand = 15;
    std::vector<Card> cardsInHand;
};

#endif // PLAYER_H