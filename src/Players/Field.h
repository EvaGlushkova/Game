/*
Glushkova Eva st108255@student.spbu.ru
*/

/**
 * @file Field.h
 * @brief Player's field for cards
 */

#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "../Cards/animals/ChickenCard.h"
#include "../Cards/animals/CowCard.h"
#include "../Cards/animals/PigCard.h"
#include "../Cards/animals/SheepCard.h"
#include "../Cards/crops/CarrotCard.h"
#include "../Cards/crops/PotatoCard.h"
#include "../Cards/crops/TomatoCard.h"
#include "../Cards/crops/WheatCard.h"

/**
 * @class Field
 * @brief Manages cards placed on player's field
 */

class Field {
private:
  std::vector<Card *> crops_;   ///< Collection of crop cards on field
  std::vector<Card *> animals_; ///< Collection of animal cards on field

  static const int MAX_CROPS = 5;   ///< Maximum crop cards allowed
  static const int MAX_ANIMALS = 5; ///< Maximum animal cards allowed

public:
  /**
   * @brief Constructor - creates empty field
   */
  Field();

  /**
   * @brief Destructor - deletes all cards on field
   */
  ~Field();

  /**
   * @brief Get number of crop cards on field
   * @return Number of crop cards
   */
  int getCropCount() const;

  /**
   * @brief Get number of animal cards on field
   * @return Number of animal cards
   */
  int getAnimalCount() const;

  /**
   * @brief Activate all cards on field to generate income
   * @return Total income generated from all cards
   */
  int activateAll() const;

  /**
   * @brief Place a card on the field
   * @param card Card to place
   * @return True if card was placed successfully, false otherwise
   */
  bool placeCard(Card *card);

  /**
   * @brief Check if more crop cards can be placed
   * @return True if there is space for more crops
   */
  bool canPlaceCrop() const;

  /**
   * @brief Check if more animal cards can be placed
   * @return True if there is space for more animals
   */
  bool canPlaceAnimal() const;

  /**
   * @brief Returns string representation of field state
   * @return String describing field contents
   */
  std::string getFieldInfo() const;
};

#endif