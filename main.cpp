/*
Glushkova Eva st108255@student.spbu.ru
*/

#include <iostream>

#include "src/Game/Game.h"

int main() {
  std::cout << "Farm Card Game \n\n";

  std::cout << "Choose game mode:\n";
  std::cout << "1. Player vs Player\n";
  std::cout << "2. Player vs AI (Easy)\n";
  std::cout << "3. Player vs AI (Medium)\n";
  std::cout << "Enter 1, 2 or 3: ";

  int choice;
  std::cin >> choice;

  Game game;

  if (choice == 1) {
    game.setup("PvP");
  } else if (choice == 2) {
    game.setup("PvAI", "EASY");
  } else if (choice == 3) {
    game.setup("PvAI", "MEDIUM");
  } else {
    std::cout << "Invalid choice. Using Player vs Player\n";
    game.setup("PvP");
  }

  game.start();

  std::cout << "\nFinish. Press Enter to exit";
  std::cin.ignore();
  std::cin.get();

  return 0;
}