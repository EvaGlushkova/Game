/*
Glushkova Eva st108255@student.spbu.ru
*/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

/**
 * @class HumanPlayer
 * @brief Human-controlled player
 */

class HumanPlayer : public Player {
public:
  /**
   * @brief Constructor
   */
  HumanPlayer(const std::string &name = "Player");

  /**
   * @brief Human chooses a card to play or passes
   * @return Card index to play, or -1 to pass
   */
  int chooseCardToPlay() override;

  /**
   * @brief Let human select a card from hand
   * @return Selected card index (-1 for cancel)
   */
  int selectCardFromHand() const;
};

#endif