/*
Glushkova Eva st108255@student.spbu.ru
*/

/**
 * @file ChickenCard.h
 * @brief Chicken animal card - cost 3, income 2
 */

#ifndef CHICKENCARD_H
#define CHICKENCARD_H

#include "../core/AnimalCard.h"

class ChickenCard : public AnimalCard {
public:
  /**
   * @brief Constructor - sets Chicken card properties
   */
  ChickenCard();
  /**
   * @brief Destructor
   */
  ~ChickenCard() override = default;
};

#endif