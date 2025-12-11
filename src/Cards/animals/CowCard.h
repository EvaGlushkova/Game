/*
Glushkova Eva st108255@student.spbu.ru
*/

/**
 * @file CowCard.h
 * @brief Cow animal card - cost 4, income 2
 */

#ifndef COWCARD_H
#define COWCARD_H

#include "../core/AnimalCard.h"

class CowCard : public AnimalCard {
public:
  /**
   * @brief Constructor - sets Cow card properties
   */
  CowCard();
  /**
   * @brief Destructor
   */
  ~CowCard() override = default;
};

#endif