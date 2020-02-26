#include <iostream>
#include <string>
#include <vector>
#include <time.h>

const std::string RANKS[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const std::string SUITES[4] = {"Heart", "Diamond", "Clover", "Spade"};

class Card {
	private:
		std::string rank = "none";
		std::string suite = "none";

	public:
		Card() {
			rank = "none";
			suite = "none";
		}

		std::string getRank() const { return rank; }
		int getRankVal() const {
			for (int i = 0; i < 13; i++) {
				if (getRank() == RANKS[i]) {return (i + 1);}
			}
			return 0;
		}
		std::string getSuite() const { return suite; }

		Card(Card cardList[], int* numCards) { 				//Ideally, generate card not present in drawn card list
			if (*numCards == 52) { return;}				//How to fail constructor so duplicate card cannot be made?
			bool gotUniqueCard = false;
			while (!gotUniqueCard) {
				rank = RANKS[rand() % 13];
				suite = SUITES[rand() % 4];
				gotUniqueCard = true;	
				for (int i = 0; i < (*numCards); i++) {		//How to more efficiently generate random, non-duplicate cards?
					if (getRank() == (cardList)[i].getRank() && getSuite() == (cardList)[i].getSuite()) {
						gotUniqueCard = false;
						break;
					}
				}
			}
			cardList[*numCards] = *this;
			(*numCards)++;
			return;
		}


};

class Player {
	private:
		int numCards = 0;
		Card cards[10];
		std::string playerType = "computer";
	public:
		Player() {

		}
		
		const Card* getCards() {return cards;}
		const int getNumCards() {return numCards;}
		const std::string getPlayerType() {return playerType;}
		void humanPlayer() {playerType = "human";}			//Better ways to toggle human/computer?
		
		int calcCardsValue() {
			int val = 0;
			for (int i = 0; i < getNumCards(); i++) {
				val += getCards()[i].getRankVal();
			}
		}

		void addCard(Card input) {
			if (numCards == 52) {return; }
			cards[numCards] = input;
			numCards++;
		}
		
		void showPlayerHand() {
			std::cout << "Player hand: ";
			for (int i = 0; i < numCards; i++) {
				std::cout << cards[i].getRank() << "-" << cards[i].getSuite();
				if (i < numCards - 1) { std::cout << ", "; }
			}
			std::cout << ". \n";
		}
		std::string decide() {
			int val = calcCardsValue();
			if (calcCardsValue() > 14) {
				return "pass";
			}
			else {
				return "hit";
			}
		}
		
};

