/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "Card.h"

std::string Card::getDescription() const {
  return getName() + " (Cost: " + std::to_string(getCost()) +
         ", Income: " + std::to_string(getIncome()) + ", Type: " + getType() +
         ")";
}
