

#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() : mode_(nullptr), turn_(1), gameOver_(false) {
  std::srand(time(nullptr));
}

Game::~Game() {
  if (mode_)
    delete mode_;
}

void Game::setup(const std::string &mode, const std::string &difficulty) {
  deck_.initializeDeck();

  if (mode == "PvP") {
    mode_ = new PlayerVsPlayerMode();
  } else if (mode == "PvAI") {
    mode_ = new PlayerVsAIMode(difficulty);
  } else {
    mode_ = new PlayerVsPlayerMode();
  }

  mode_->initialize(deck_);
}

void Game::start() {
  std::cout << "\n- FARM GAME -\n\n";

  Player *p1 = mode_->getPlayer1();
  Player *p2 = mode_->getPlayer2();

  while (!gameOver_) {
    std::cout << "\n----- TURN " << turn_ << " -----\n";

    Player *player = mode_->getCurrentPlayer();
    Player *opponent = (player == p1) ? p2 : p1;

    std::cout << "\nCollecting income...\n";

    player->collectIncome();
    player->addCoins(1);

    if (player->hasWon()) {
      std::cout << "\n*** VICTORY ***\n";
      std::cout << player->getName() << " wins with " << player->getCoins()
                << " coins!\n";
      break;
    }

    if (player->canTakeCard() && deck_.getCardCount() > 0) {
      Card *card = deck_.drawCard();
      player->addCardToHand(card);
      std::cout << "\nNew card: " << card->getName() << "\n";
    }

    std::cout << "\nYour field:\n";
    std::cout << player->getField().getFieldInfo() << "\n\n";

    std::cout << "Hand (" << player->getHandSize() << " cards):\n";
    for (int i = 0; i < player->getHandSize(); i++) {
      Card *card = player->getCardFromHand(i);
      if (card) {
        std::cout << i << ". " << card->getName()
                  << " (Cost: " << card->getCost()
                  << ", Income: " << card->getIncome() << ")\n";
      }
    }

    int choice = player->chooseCardToPlay();

    if (choice >= 0) {
      player->playCard(choice);
      std::cout << player->getField().getFieldInfo() << "\n";
    }

    std::cout << "\n- OPPONENT -\n";
    std::cout << opponent->getName() << ": " << opponent->getCoins()
              << " coins, " << opponent->getHandSize() << " cards in hand\n";

    std::cout << "\nOpponent's field:\n";
    std::cout << opponent->getField().getFieldInfo() << "\n";

    std::cout << "\nDECK: " << deck_.getCardCount() << " cards left\n";
    mode_->nextTurn();
    turn_++;
  }

  std::cout << "\n!!! GAME OVER !!!\n";
  std::cout << "Turns played: " << (turn_ - 1) << "\n";
  std::cout << "Final scores:\n";
  std::cout << p1->getName() << ": " << p1->getCoins() << " coins\n";
  std::cout << p2->getName() << ": " << p2->getCoins() << " coins\n";
}