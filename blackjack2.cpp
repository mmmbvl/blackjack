#include <iostream>
#include <string>
#include <vector>

#include "blackjack2.h"

void dealCardsToAll(Player playerlist[], int numPlayers, Card cards[], int* numCards);
void showCards(Player playerList[], int numPlayers);

int main() {
	srand(time(NULL));
	Card drawnCards[52];
	int numDrawnCards = 0;
	std::cout << "How many players are there?\n";
	int numPlayers;
	std::cin >> numPlayers;
	Player players[numPlayers];

	std::cout << "Would you like to play? (y/n)\n";
	std::string humanPlayer;
	std::cin >> humanPlayer;
	if (humanPlayer == "y") {players[0].humanPlayer();}
	
	std::cout << "No rounds of cards dealt: \n";
	showCards(players, numPlayers);

	dealCardsToAll(players, numPlayers, drawnCards, &numDrawnCards);
	std::cout << "1 round of cards dealt: " << numDrawnCards << " total:\n";
	showCards(players, numPlayers);

	dealCardsToAll(players, numPlayers, drawnCards, &numDrawnCards);
	std::cout << "2 rounds of cards dealt: " << numDrawnCards << " total:\n";
	showCards(players, numPlayers);

	dealCardsToAll(players, numPlayers, drawnCards, &numDrawnCards);
	std::cout << "3 rounds of cards dealt: " << numDrawnCards << " total:\n";
	showCards(players, numPlayers);

	return 0;
}

void dealCardsToAll(Player playerList[], int numPlayers, Card cards[], int* numCards) {
	for (int i = 0; i < numPlayers; i++) {
		playerList[i].addCard(Card(cards, numCards));
	}
	return;
}

void dealCard(Player playerList[], int playerID, Card cards[], int* numCards) {
	playerList[playerID].addCard(Card(cards, numCards));
	return;
}

void doTurn(Player playerList[], int playerID, Card cards[], int* numCards) {
	std::string choice = "";
	if (playerList[playerID].getPlayerType() == "human") {
		std::cout << "It is player " << playerID << "'s turn. Would you like to 'hit' or 'pass'?\n";
		std::cin >> choice;
	}
	else {
		choice = playerList[playerID].decide();
	}
	if (choice == "hit") {
		playerList[playerID].addCard(Card(cards, numCards));
		if (playerList[playerID].getPlayerType() == "human") {
			std::cout << "Your new hand is: ";
			playerList[playerID].showPlayerHand();
		}
	}
	else if (choice == "pass") {
		
	}
	else {
		std::cout << "That was an invalid move.\n";			//Change to return value to re-do turn
 	}
	return;
}

void showCards(Player playerList[], int numPlayers) {
	for (int i = 0; i < numPlayers; i++) {
		playerList[i].showPlayerHand();
	}
	return;
}