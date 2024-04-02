#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#pragma once
#include <vector>
#include "Player.h"
class GameControl {
public:
    void startGame();

private:
    Player player;
    int WinInRoundsPlayerCount = 0;
    Player opponent;
    int WinInRoundsOpponentCount = 0;
    int m_currentPlayerIndex;
    int maxRoundsCount = 3;
    int RoundCount = 0;
    void initializePlayers();
    bool isGameOver();
    void playRound();
    void playTurn(Player& player);
    static void printBoardState(const Player& player1, const Player& player2);
    static void printHandState(const Player& player);
    void printRoundWinner(const Player& player1, const Player& player2);
    void addCardsToPlayersDeck(Deck& playerDeck);
};

#endif // GAMECONTROL_H