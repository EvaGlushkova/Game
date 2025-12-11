/*
Glushkova Eva st108255@student.spbu.ru
*/

#ifndef PLAYERVSAIMODE_H
#define PLAYERVSAIMODE_H

#include <string>

#include "GameMode.h"

/**
 * @class PlayerVsAIMode
 * @brief Human vs AI mode
 */

class PlayerVsAIMode : public GameMode {
private:
  std::string aiDifficulty_; ///< AI difficulty

public:
  /**
   * @brief Constructor
   * @param difficulty AI difficulty
   */
  PlayerVsAIMode(const std::string &difficulty = "EASY");

  /**
   * @brief Initialize human and AI players
   * @param deck Game deck
   */
  void initialize(Deck &deck) override;

  /**
   * @brief Get mode name
   * @return Mode name with difficulty
   */
  std::string getModeName() const override;

  /**
   * @brief Get AI difficulty
   * @return Difficulty level
   */
  std::string getAIDifficulty() const;
};

#endif