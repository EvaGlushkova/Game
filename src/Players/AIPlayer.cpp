/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "AIPlayer.h"

AIPlayer::AIPlayer(const std::string &name, const std::string &difficulty)
    : Player(name), difficulty_(difficulty) {}

std::string AIPlayer::getDifficulty() const { return difficulty_; }
