/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "GameMode.h"

GameMode::GameMode()
    : player1_(nullptr), player2_(nullptr), isPlayer1Turn_(true) {}

GameMode::~GameMode() {
  if (player1_)
    delete player1_;
  if (player2_)
    delete player2_;
}

Player *GameMode::getCurrentPlayer() const {
  return isPlayer1Turn_ ? player1_ : player2_;
}

void GameMode::nextTurn() { isPlayer1Turn_ = !isPlayer1Turn_; }

bool GameMode::hasWinner() const {
  if (player1_ && player1_->hasWon())
    return true;
  if (player2_ && player2_->hasWon())
    return true;
  return false;
}

Player *GameMode::getWinner() const {
  if (player1_ && player1_->hasWon())
    return player1_;
  if (player2_ && player2_->hasWon())
    return player2_;
  return nullptr;
}

Player *GameMode::getPlayer1() const { return player1_; }

Player *GameMode::getPlayer2() const { return player2_; }