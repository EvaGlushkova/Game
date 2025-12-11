/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "MediumAIPlayer.h"

#include <iostream>

MediumAIPlayer::MediumAIPlayer(const std::string &name)
    : AIPlayer(name, "MEDIUM") {}

int MediumAIPlayer::chooseCardToPlay() {
  std::cout << getName() << "'s Turn \n";
  std::cout << getPlayerInfo() << "\n";

  if (getHandSize() == 0) {
    std::cout << "No cards, so pass \n";
    return -1;
  }

  int crops = getField().getCropCount();
  int animals = getField().getAnimalCount();

  if (crops < animals) {
    for (int i = 0; i < getHandSize(); i++) {
      Card *card = getCardFromHand(i);
      if (card->getType() == "Crop" && getCoins() >= card->getCost() &&
          getField().canPlaceCrop()) {
        std::cout << "Playing: " << card->getName() << "\n";
        return i;
      }
    }
  }

  if (animals < crops) {
    for (int i = 0; i < getHandSize(); i++) {
      Card *card = getCardFromHand(i);
      if (card->getType() == "Animal" && getCoins() >= card->getCost() &&
          getField().canPlaceAnimal()) {
        std::cout << "Playing: " << card->getName() << "\n";
        return i;
      }
    }
  }

  for (int i = 0; i < getHandSize(); i++) {
    Card *card = getCardFromHand(i);
    if (getCoins() >= card->getCost()) {
      if (card->getType() == "Crop" && getField().canPlaceCrop()) {
        std::cout << "Playing: " << card->getName() << "\n";
        return i;
      }
      if (card->getType() == "Animal" && getField().canPlaceAnimal()) {
        std::cout << "Playing: " << card->getName() << "\n";
        return i;
      }
    }
  }

  std::cout << "Passing \n";
  return -1;
}