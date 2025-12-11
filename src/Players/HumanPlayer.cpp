#include "HumanPlayer.h"

#include <iostream>

HumanPlayer::HumanPlayer(const std::string &name) : Player(name) {}

int HumanPlayer::chooseCardToPlay() {
  std::cout << getName() << "'s Turn \n";
  std::cout << getPlayerInfo() << "\n";

  if (getHandSize() == 0) {
    std::cout << "No cards in hand. Passing turn\n";
    return -1;
  }

  int actionChoice = 0;

  while (true) {
    std::cout << "\nChoose action:\n";
    std::cout << "1. Play a card\n";
    std::cout << "2. Pass turn\n";
    std::cout << "Enter choice (1-2): ";

    if (std::cin >> actionChoice) {
      if (actionChoice == 1 || actionChoice == 2) {
        break;
      }
    } else {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
    std::cout << "Please enter 1 or 2 \n";
  }

  if (actionChoice == 1) {
    return selectCardFromHand();
  }

  return -1;
}

int HumanPlayer::selectCardFromHand() const {
  std::cout << "\nYour hand:\n";

  for (int i = 0; i < getHandSize(); i++) {
    Card *card = getCardFromHand(i);
    std::cout << i + 1 << ". " << card->getName()
              << " (Cost: " << card->getCost()
              << ", Income: " << card->getIncome() << ")\n";
  }

  int choice = -1;

  while (true) {
    std::cout << "0. Cancel\n";
    std::cout << "Select card (0-" << getHandSize() << "): ";

    if (std::cin >> choice) {
      if (choice >= 0 && choice <= getHandSize()) {
        break;
      }
    } else {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
    std::cout << "Please enter a valid number \n";
  }

  return (choice == 0) ? -1 : choice - 1;
}