
#include "Hand.h"
void Hand::drawCard(Player player){
    const Card& drawnCard = player.m_deck.drawCard();
    cardsInHand.push_back(drawnCard);
}
void Hand::removeCardFromHand(int cardIndex){
    cardsInHand.erase(cardsInHand.begin() + cardIndex);
}
void Hand::initializeCardsInHand(Player player){
    int i = 0;
    while(i < StartNumberOfCardsHand){
        drawCard(player);
        i++;
    }
}