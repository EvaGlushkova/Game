/*
Glushkova Eva st108255@student.spbu.ru
*/

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <string>

#include "Player.h"

/**
 * @class AIPlayer
 * @brief Base class for AI players
 */
class AIPlayer : public Player {
protected:
  std::string difficulty_; ///< AI difficulty level

public:
  /**
   * @brief Constructor
   * @param name Player name
   * @param difficulty AI difficulty ("EASY", "MEDIUM")
   */
  AIPlayer(const std::string &name, const std::string &difficulty);

  /**
   * @brief Get AI difficulty
   * @return Difficulty string
   */
  std::string getDifficulty() const;

  /**
   * @brief Override chooseAction
   */

  virtual int chooseCardToPlay() = 0;
};

#endif