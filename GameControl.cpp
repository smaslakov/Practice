#include "GameControl.h"
#include <iostream>

void GameControl::startGame() {
    initializePlayers();
    // Start the game loop
    bool gameOver = false;
    while (!gameOver) {
        opponent.IsPlayerPassed = false;
        player.IsPlayerPassed = false;
        playRound();
    // Check for game over condition
      if(WinInRoundsPlayerCount == 2 || WinInRoundsOpponentCount == 2){
          gameOver = true;
      }
    }
    // Print the winner
    std::cout << ( (WinInRoundsPlayerCount > WinInRoundsOpponentCount)?player.getName():opponent.getName() ) << "wins!!!" << "\n";
    std::cout << ( (WinInRoundsPlayerCount > WinInRoundsOpponentCount)?WinInRoundsPlayerCount:WinInRoundsOpponentCount )<< ":" << ( (WinInRoundsPlayerCount > WinInRoundsOpponentCount)?WinInRoundsOpponentCount:WinInRoundsPlayerCount );
}

void GameControl::initializePlayers() {
    Deck playerDeck;
    Deck opponentDeck;

    addCardsToPlayersDeck(playerDeck);
    addCardsToPlayersDeck(opponentDeck);

    player.SetPlayer("Player 1",playerDeck);
    opponent.SetPlayer("Player 2",opponentDeck);
}

void GameControl::addCardsToPlayersDeck(Deck& playerDeck){
    for(int i = 0; i < 35; i++){
        playerDeck.addCard(Card("Card " + std::to_string(i), 5));
    }
}

void GameControl::playRound() {
    RoundCount++;
    if (opponent.IsPlayerPassed && player.IsPlayerPassed) {
        player.calculateTotalStrength()>opponent.calculateTotalStrength()?++WinInRoundsPlayerCount:++WinInRoundsOpponentCount;
        return;
    }
    player.hand.initializeCardsInHand();
    opponent.hand.initializeCardsInHand();
    // Each player plays a turn
    while(!opponent.IsPlayerPassed || !player.IsPlayerPassed){
        if(!player.IsPlayerPassed) playTurn(player);
        if(!opponent.IsPlayerPassed) playTurn(opponent);
    }
    printWinner(player,opponent);
    // Clear the board at the end of the round
    player.clearBoard();
    opponent.clearBoard();
}

void GameControl::playTurn(Player& player) {
    std::cout << player.getName() << "'s turn." << "\n";
    std::cout << "Do u want to pass(Y or N)" << "\n";
    char answer;
    std::cin>>answer;
    switch(answer){
        case 'Y':
            player.IsPlayerPassed = true;
            return;
        default:
            break;
    }
    GameControl::printDeckState(player);
//PlayCard time
    std::cout<<"Enter the index of card that u want to play:";
    int ind;
    std::cin>>ind;
    player.playCard(ind - 1);

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

void GameControl::printWinner(const Player& player1, const Player& player2){
    int player1Strength = player1.calculateTotalStrength();
    int player2Strength = player2.calculateTotalStrength();

    if (player1Strength > player2Strength) {
        std::cout << player1.getName() << " wins!" << std::endl;
        ++WinInRoundsPlayerCount;
    } else if (player2Strength > player1Strength) {
        std::cout << player2.getName() << " wins!" << std::endl;
        ++WinInRoundsOpponentCount
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
bool GameControl::isGameOver() {
    if(RoundCount == maxRoundsCount) return true;
    if(WinInRoundsPlayerCount == 2 || WinInRoundsOpponentCount == 2) return true;

}