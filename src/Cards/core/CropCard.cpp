/*
Glushkova Eva st108255@student.spbu.ru
*/

#include "CropCard.h"

std::string CropCard::getType() const { return "Crop"; }

std::string CropCard::getName() const { return name; }

int CropCard::getCost() const { return cost; }

int CropCard::getIncome() const { return income; }

int CropCard::activateIncome() { return income; }