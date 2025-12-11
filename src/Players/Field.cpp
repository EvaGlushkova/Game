/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "Field.h"

#include <sstream>

Field::Field() {}

Field::~Field() {
  for (Card *crop : crops_) {
    delete crop;
  }

  for (Card *animal : animals_) {
    delete animal;
  }
}

int Field::getCropCount() const { return crops_.size(); }

int Field::getAnimalCount() const { return animals_.size(); }

int Field::activateAll() const {
  int total = 0;

  for (Card *crop : crops_) {
    total += crop->getIncome();
  }

  for (Card *animal : animals_) {
    total += animal->getIncome();
  }

  return total;
}

bool Field::placeCard(Card *card) {
  if (!card)
    return false;

  std::string type = card->getType();

  if (type == "Crop") {
    if (crops_.size() >= MAX_CROPS) {
      return false;
    }
    crops_.push_back(card);
    return true;
  }

  if (type == "Animal") {
    if (animals_.size() >= MAX_ANIMALS) {
      return false;
    }
    animals_.push_back(card);
    return true;
  }

  return false;
}

bool Field::canPlaceCrop() const { return crops_.size() < MAX_CROPS; }

bool Field::canPlaceAnimal() const { return animals_.size() < MAX_ANIMALS; }

std::string Field::getFieldInfo() const {
  std::string info;

  info = "Crops: " + std::to_string(crops_.size()) + "/5\n";
  for (Card *crop : crops_) {
    info += "  " + crop->getName() + "\n";
  }

  info += "Animals: " + std::to_string(animals_.size()) + "/5\n";
  for (Card *animal : animals_) {
    info += "  " + animal->getName() + "\n";
  }

  return info;
}