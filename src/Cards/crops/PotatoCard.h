/*
Glushkova Eva st108255@student.spbu.ru
*/

/**
 * @file PotatoCard.h
 * @brief Potato crop card - cost 3, income 2
 */

#ifndef POTATOCARD_H
#define POTATOCARD_H

#include "../core/CropCard.h"

class PotatoCard : public CropCard {
public:
  /**
   * @brief Constructor - sets Potato card properties
   */
  PotatoCard();
  /**
   * @brief Destructor
   */
  ~PotatoCard() override = default;
};

#endif