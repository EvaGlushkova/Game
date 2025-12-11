/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "PlayerVsAIMode.h"

#include <iostream>

#include "GameMode.h"

PlayerVsAIMode::PlayerVsAIMode(const std::string &difficulty)
    : aiDifficulty_(difficulty) {}

void PlayerVsAIMode::initialize(Deck &deck) {
  player1_ = new HumanPlayer("Player");

  if (aiDifficulty_ == "EASY") {
    player2_ = new EasyAIPlayer("Easy AI");
  } else if (aiDifficulty_ == "MEDIUM") {
    player2_ = new MediumAIPlayer("Medium AI");
  } else {
    player2_ = new EasyAIPlayer("Easy AI");
    aiDifficulty_ = "EASY";
  }

  if (deck.getCardCount() > 0) {
    player1_->addCardToHand(deck.drawCard());
  }
  if (deck.getCardCount() > 0) {
    player2_->addCardToHand(deck.drawCard());
  }

  player1_->addCoins(3);
  player2_->addCoins(3);

  std::cout << "Game Mode: Player vs AI (" << aiDifficulty_ << ")\n";
}

std::string PlayerVsAIMode::getModeName() const {
  return "Player vs AI (" + aiDifficulty_ + ")";
}

std::string PlayerVsAIMode::getAIDifficulty() const { return aiDifficulty_; }