#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <vector>
#include "Player.h"

class GameControl {
public:
    void startGame();

private:
    Player player;
    int WinInRoundsPlayerCount;
    Player opponent;
    int WinInRoundsOpponentCount;
    int m_currentPlayerIndex;
    int maxRoundsCount = 3;
    int RoundCount = 0;
    void initializePlayers();
    bool isGameOver();
    void playRound();
    void playTurn(Player& player);
    static void printBoardState(const Player& player1, const Player& player2);
    static void printDeckState(const Player& player);
    void printWinner(const Player& player1, const Player& player2);
    void addCardsToPlayersDeck(Deck& playerDeck);
};

#endif // GAMECONTROL_H