#include "Player.h"

Player::Player(const std::string& name, const Deck& deck) : m_name(name), m_deck(deck) {}

const std::string& Player::getName() const {
    return m_name;
}

void Player::drawCard() {
    const Card& drawnCard = m_deck.drawCard();
    m_hand.push_back(drawnCard);
}

void Player::playCard(int cardIndex) {
    Card playedCard = m_hand[cardIndex];
    m_board.push_back(playedCard);
    removeCardFromHand(cardIndex);
}

void Player::removeCardFromHand(int cardIndex) {
    m_hand.erase(m_hand.begin() + cardIndex);
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

void Player::initializeCardsInHand(){
    int i = 0;
    while(i < StartNumberOfCardsHand){
        drawCard();
        i++;
    }
}

Deck Player::getDeck() const {
    return m_deck;
}

void Player::ChangeFlagPass() {
    IsPlayerPassed?IsPlayerPassed = false:IsPlayerPassed = true;
}
