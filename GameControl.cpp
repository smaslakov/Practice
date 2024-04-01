#include "GameControl.h"
#include <iostream>

void GameControl::startGame() {
    initializePlayers();

    // Start the game loop
    bool gameOver = false;
    while (!gameOver) {
        playRound();

        // Check for game over condition
        if (m_players[0].calculateTotalStrength() >= 2 || m_players[1].calculateTotalStrength() >= 2) {
            gameOver = true;
        }
    }

    // Print the winner
    printWinner(m_players[0], m_players[1]);
}

void GameControl::initializePlayers() {
    Deck player1Deck;
    Deck player2Deck;

    addCardsToPlayersDeck(player1Deck);
    addCardsToPlayersDeck(player2Deck);

    Player player1("Player 1", player1Deck);
    Player player2("Player 2", player2Deck);

    m_players.push_back(player1);
    m_players.push_back(player2);

}

void GameControl::addCardsToPlayersDeck(Deck& playerDeck){
    for(int i = 0; i < 35; i++){
        playerDeck.addCard(Card("Card " + std::to_string(i), 5));
    }
}

void GameControl::playRound() {
    // Alternate turns between players
    m_currentPlayerIndex = 0;

    Player& currentPlayer = m_players[m_currentPlayerIndex];
    Player& opponent = m_players[1 - m_currentPlayerIndex];

    currentPlayer.initializeCardsInHand();
    opponent.initializeCardsInHand();

    // Each player plays a turn
    playTurn(currentPlayer, m_currentPlayerIndex);
    playTurn(opponent, 1 - m_currentPlayerIndex);

    // Clear the board at the end of the round
    currentPlayer.clearBoard();
    opponent.clearBoard();
}

void GameControl::playTurn(Player& player, int m_currentPlayerIndex) {
    std::cout << player.getName() << "'s turn." << std::endl;

    GameControl::printDeckState(player);

    // Draw a card
    player.drawCard();

    // Print the player's hand and board state
    GameControl::printBoardState(player, m_players[1 - m_currentPlayerIndex]);

    // Play a card from hand
    int cardIndex;
    std::cout << "Enter the index of the card to play: ";
    std::cin >> cardIndex;
    player.playCard(cardIndex);

    // Print the updated board state
    GameControl::printBoardState(player, m_players[1 - m_currentPlayerIndex]);
}

void GameControl::printBoardState(const Player& player1, const Player& player2)  {
    std::cout << "----- " << player1.getName() << "'s Board -----" << std::endl;
    for (const Card& card : player1.m_board) {
        std::cout << card.getName() << " (" << card.getStrength() << ")\t";
    }
    std::cout << std::endl;

    std::cout << "----- " << player2.getName() << "'s Board -----" << std::endl;
    for (const Card& card : player2.m_board) {
        std::cout << card.getName() << " (" << card.getStrength() << ")\t";
    }
    std::cout << std::endl;
}

void GameControl::printWinner(const Player& player1, const Player& player2) const {
    int player1Strength = player1.calculateTotalStrength();
    int player2Strength = player2.calculateTotalStrength();

    if (player1Strength > player2Strength) {
        std::cout << player1.getName() << " wins!" << std::endl;
    } else if (player2Strength > player1Strength) {
        std::cout << player2.getName() << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

void GameControl::printDeckState(const Player &player) {
    std::cout << "-------------------******************------------------- " << player.getName() << "'s Deck ------------" << std::endl;
    const Deck playerDeck = player.getDeck();
    int counter = 0;
    for (const Card& card : playerDeck.cardsInDeck) {
        if(counter < 7){
            std::cout << card.getName() << " (" << card.getStrength() << ")\t";
        }
        else{
            counter = 0;
            std::cout << card.getName() << " (" << card.getStrength() << ")\n";
        }
        counter++;
    }
    std::cout << std::endl;

}