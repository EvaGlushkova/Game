/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "Player.h"

#include <sstream>

Player::Player(const std::string &name) : name_(name) {}

Player::~Player() {
  for (Card *card : hand_) {
    delete card;
  }
}

std::string Player::getName() const { return name_; }

int Player::getCoins() const { return coins_; }

int Player::getHandSize() const { return static_cast<int>(hand_.size()); }

const Field &Player::getField() const { return field_; }

bool Player::hasWon() const { return coins_ >= 30; }

void Player::addCoins(int amount) {
  if (amount > 0) {
    coins_ += amount;
  }
}

bool Player::spendCoins(int amount) {
  if (coins_ >= amount && amount > 0) {
    coins_ -= amount;
    return true;
  }
  return false;
}

bool Player::canTakeCard() const { return hand_.size() < MAX_HAND_SIZE; }

void Player::addCardToHand(Card *card) {
  if (card && canTakeCard()) {
    hand_.push_back(card);
  }
}

Card *Player::getCardFromHand(int index) const {
  if (index >= 0 && index < static_cast<int>(hand_.size())) {
    return hand_[index];
  }
  return nullptr;
}

Card *Player::removeCardFromHand(int index) {
  if (index < 0 || index >= static_cast<int>(hand_.size())) {
    return nullptr;
  }

  Card *card = hand_[index];
  hand_.erase(hand_.begin() + index);
  return card;
}

void Player::collectIncome() {
  int income = field_.activateAll();
  addCoins(income);
}

bool Player::playCard(int index) {
  if (index < 0 || index >= static_cast<int>(hand_.size())) {
    return false;
  }

  Card *card = hand_[index];

  if (!spendCoins(card->getCost())) {
    return false;
  }

  if (field_.placeCard(card)) {
    hand_.erase(hand_.begin() + index);
    return true;
  }

  addCoins(card->getCost());
  return false;
}

std::string Player::getPlayerInfo() const {
  std::stringstream info;
  info << name_ << " | Coins: " << coins_ << " | Hand: " << hand_.size() << "/"
       << MAX_HAND_SIZE << " | Income: " << field_.activateAll() << "/turn";
  return info.str();
}