#include "Player.h"

Player::Player(){}
void Player::SetPlayer(const std::string& name,const Deck& deck){
    m_name = name;
    m_deck = deck;
}
const std::string& Player::getName() const {
    return m_name;
}

void Player::playCard(int cardIndex) {
    Card playedCard = hand.cardsInHand[cardIndex - 1];
    m_board.push_back(playedCard);
    hand.removeCardFromHand(cardIndex);
}

void Player::clearBoard() {
    m_board.clear();
}

int Player::calculateTotalStrength() const {
    int totalStrength = 0;
    for (const Card& card : m_board) {
        totalStrength += card.getStrength();
    }
    return totalStrength;
}

Deck Player::getDeck() const {
    return m_deck;
}

void Player::ChangeFlagPass() {
    IsPlayerPassed?IsPlayerPassed = false:IsPlayerPassed = true;
}
