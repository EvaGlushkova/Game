/*
Glushkova Eva st108255@student.spbu.ru
*/

/**
 * @file Player.h
 * @brief For all players
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Field.h"

/**
 * @class Player
 * @brief Base abstract class for all players
 */
class Player {
protected:
  std::string name_;         ///< Player name
  int coins_;                ///< Current coins
  std::vector<Card *> hand_; ///< Cards in player's hand
  Field field_;              ///< Player's field

  static const int MAX_HAND_SIZE = 7; ///< Max cards in hand

public:
  /**
   * @brief Constructor
   * @param name Player's display name
   */
  Player(const std::string &name);

  /**
   * @brief Virtual destructor
   */
  virtual ~Player();

  /**
   * @brief Get player's name
   * @return Player name as string
   */
  std::string getName() const;

  /**
   * @brief Get current coin balance
   * @return Number of coins player has
   */
  int getCoins() const;

  /**
   * @brief Get number of cards in hand
   * @return Current hand size
   */
  int getHandSize() const;

  /**
   * @brief Get player's field
   * @return Const reference to Field object
   */
  const Field &getField() const;

  /**
   * @brief Check if player has won the game
   * @return true if player has 30 or more coins
   */
  bool hasWon() const;

  /**
   * @brief Collect income from all cards on field
   * Adds field income to player's coin balance
   */
  void collectIncome();

  /**
   * @brief Add coins to player's balance
   * @param amount Number of coins to add
   */
  void addCoins(int amount);

  /**
   * @brief Spend coins from player's balance
   * @param amount Number of coins to spend
   * @return true if player had enough coins, false otherwise
   */
  bool spendCoins(int amount);

  /**
   * @brief Check if hand has space for more cards
   * @return true if hand size is less than MAX_HAND_SIZE
   */
  bool canTakeCard() const;

  /**
   * @brief Add a card to player's hand
   * @param card Pointer to card to add
   */
  void addCardToHand(Card *card);

  /**
   * @brief Get card from hand without removing it
   * @param index Position of card in hand
   * @return Pointer to card, nullptr if index invalid
   */
  Card *getCardFromHand(int index) const;

  /**
   * @brief Remove a card from hand by index
   * @param index Position of card in hand
   * @return Pointer to removed card, nullptr if index invalid
   */
  Card *removeCardFromHand(int index);

  /**
   * @brief Play a card from hand to field
   * @param index Position of card in hand to play
   * @return true if card was successfully played, false otherwise
   */
  bool playCard(int index);

  /**
   * @brief Choose a card to play or pass
   * @return Index of card to play, or -1 to pass
   */
  virtual int chooseCardToPlay() = 0;

  /**
   * @brief Get formatted player information
   * @return String describing player's current state
   */
  std::string getPlayerInfo() const;
};

#endif