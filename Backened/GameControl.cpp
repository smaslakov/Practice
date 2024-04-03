#include "GameControl.h"
#include <iostream>

void GameControl::startGame() {
    initializePlayers();
    // Start the game loop
    while (!isGameOver()) {
        opponent.IsPlayerPassed = false;
        player.IsPlayerPassed = false;
        playRound();
    }
    // Print the winner
    printWinner(player, opponent);
}

void GameControl::initializePlayers() {
    Deck playerDeck;
    Deck opponentDeck;

    addCardsToPlayersDeck(playerDeck);
    addCardsToPlayersDeck(opponentDeck);

    player.SetPlayer("Player 1", playerDeck);
    opponent.SetPlayer("Player 2", opponentDeck);
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
    player.initializeCardsInHand(player);
    opponent.initializeCardsInHand(opponent);
    // Each player plays a turn
    while(!opponent.IsPlayerPassed || !player.IsPlayerPassed){
        if(!player.IsPlayerPassed) playTurn(player);
        GameControl::printBoardState(player, opponent);
        if(!opponent.IsPlayerPassed) playTurn(opponent);
        GameControl::printBoardState(player, opponent);
    }
    printRoundWinner(player,opponent);
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
    GameControl::printHandState(player);
//PlayCard time
    std::cout<<"Enter the index of card that u want to play:";
    int ind;
    std::cin>>ind;
    std::cout<<"Enter the index of field that u want to play card to:";
    int fieldInd;
    std::cin >> fieldInd;
    player.playCard(ind - 1, fieldInd);

    // Print the player's hand and board state
   /* GameControl::printBoardState(player, opponent);

    // Play a card from hand
    int cardIndex;
    std::cout << "Enter the index of the card to play: ";
    std::cin >> cardIndex;
    player.playCard(cardIndex);

    // Print the updated board state
    */

}

void GameControl::printBoardState(const Player& player1, const Player& player2)  {
    std::cout << "----- " << player1.getName() << "'s Board -----" << std::endl;

    std::cout << std::endl << "----- " << player1.getName() << "'s 1st field -----" << std::endl;

    for (const Card& card : player1.m_board.field[0]) {
        std::cout << card.getName() << " (" << card.getStrength() << ")\t";
    }
    std::cout << std::endl;

    std::cout << std::endl << "----- " << player1.getName() << "'s 2st field -----" << std::endl;

    for (const Card& card : player1.m_board.field[1]) {
        std::cout << card.getName() << " (" << card.getStrength() << ")\t";
    }
    std::cout << std::endl;





    std::cout << "----- " << player2.getName() << "'s Board -----" << std::endl;

    std::cout << std::endl << "----- " << player2.getName() << "'s 1st field -----" << std::endl;

    for (const Card& card : player2.m_board.field[0]) {
        std::cout << card.getName() << " (" << card.getStrength() << ")\t";
    }
    std::cout << std::endl;

    std::cout << std::endl << "----- " << player2.getName() << "'s 2st field -----" << std::endl;

    for (const Card& card : player2.m_board.field[1]) {
        std::cout << card.getName() << " (" << card.getStrength() << ")\t";
    }
    std::cout << std::endl;
}

void GameControl::printRoundWinner(const Player& player1, const Player& player2){
    int player1Strength = player1.calculateTotalStrength();
    int player2Strength = player2.calculateTotalStrength();

    if (player1Strength > player2Strength) {
        std::cout << player1.getName() << " wins!" << std::endl;
        ++WinInRoundsPlayerCount;
    } else if (player2Strength > player1Strength) {
        std::cout << player2.getName() << " wins!" << std::endl;
        ++WinInRoundsOpponentCount;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

void GameControl::printHandState(const Player &player) {
    std::cout << "-------------------******************------------------- " << player.getName() << "'s Hand ------------" << std::endl;
    int counter = 0;
    for (const Card& card : player.cardsInHand) {
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
    else return false;
}

void GameControl::printWinner(const Player& player,const Player& opponent){
    if(WinInRoundsPlayerCount > WinInRoundsOpponentCount){
        std::cout << player.getName() << " wins!!!" << "\n" << "\t" << WinInRoundsPlayerCount << ":"<<WinInRoundsOpponentCount;
    }else if(WinInRoundsOpponentCount > WinInRoundsPlayerCount){
        std::cout<<opponent.getName()<<" wins!!!"<<"\n"<<"\t"<<WinInRoundsOpponentCount<<":"<<WinInRoundsPlayerCount;
    }else{
        std::cout<<"It`s draw!!!"<<"\n"<<"\t"<<WinInRoundsOpponentCount<<":"<<WinInRoundsPlayerCount;
    }
}