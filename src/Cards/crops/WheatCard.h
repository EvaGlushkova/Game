/*
Glushkova Eva st108255@student.spbu.ru
*/

/**
 * @file WheatCard.h
 * @brief Wheat crop card - cost 2, income 1
 */

#ifndef WHEATCARD_H
#define WHEATCARD_H

#include "../core/CropCard.h"

class WheatCard : public CropCard {
public:
  /**
   * @brief Constructor - sets Wheat card properties
   */
  WheatCard();

  /**
   * @brief Destructor
   */
  ~WheatCard() override = default;
};

#endif