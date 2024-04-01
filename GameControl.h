#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <vector>
#include "Player.h"

class GameControl {
public:
    void startGame();

private:
    std::vector<Player> m_players;
    int m_currentPlayerIndex;

    void initializePlayers();

    void playRound();
    void playTurn(Player& player, int m_currentPlayerIndex);
    static void printBoardState(const Player& player1, const Player& player2);
    static void printDeckState(const Player& player);
    void printWinner(const Player& player1, const Player& player2) const;
    void addCardsToPlayersDeck(Deck& playerDeck);
};

#endif // GAMECONTROL_H