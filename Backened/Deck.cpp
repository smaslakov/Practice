#include "Deck.h"

void Deck::addCard(const Card& card) {
    cardsInDeck.push_back(card);
}

const Card& Deck::drawCard() {
    // For simplicity, assume the deck is not empty
    const Card& topCard = cardsInDeck.front();
    cardsInDeck.erase(cardsInDeck.begin());
    return topCard;
}