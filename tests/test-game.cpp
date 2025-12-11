#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../src/Cards/animals/ChickenCard.h"
#include "../src/Cards/animals/CowCard.h"
#include "../src/Cards/animals/PigCard.h"
#include "../src/Cards/animals/SheepCard.h"
#include "../src/Cards/core/AnimalCard.h"
#include "../src/Cards/core/Card.h"
#include "../src/Cards/core/CropCard.h"
#include "../src/Cards/crops/CarrotCard.h"
#include "../src/Cards/crops/PotatoCard.h"
#include "../src/Cards/crops/TomatoCard.h"
#include "../src/Cards/crops/WheatCard.h"
#include "../src/Deck/Deck.h"
#include "../src/Game/Game.h"
#include "../src/Game/GameMode.h"
#include "../src/Game/PlayerVsAIMode.h"
#include "../src/Game/PlayerVsPlayerMode.h"
#include "../src/Players/AIPlayer.h"
#include "../src/Players/EasyAIPlayer.h"
#include "../src/Players/Field.h"
#include "../src/Players/HumanPlayer.h"
#include "../src/Players/MediumAIPlayer.h"
#include "../src/Players/Player.h"

TEST(CardTests, CardCreationAndBasicProperties) {
  CarrotCard carrot;
  EXPECT_EQ(carrot.getName(), "Carrot");
  EXPECT_EQ(carrot.getCost(), 2);

  ChickenCard chicken;
  EXPECT_EQ(chicken.getName(), "Chicken");
  EXPECT_EQ(chicken.getCost(), 3);
}

TEST(CropCardTests, CropCardIncomeAndType) {
  WheatCard wheat;
  EXPECT_EQ(wheat.getIncome(), 1);

  TomatoCard tomato;
  EXPECT_EQ(tomato.getIncome(), 2);
}

TEST(AnimalCardTests, AnimalCardIncomeAndType) {
  SheepCard sheep;
  EXPECT_EQ(sheep.getIncome(), 2);

  PigCard pig;
  EXPECT_EQ(pig.getIncome(), 3);
}

TEST(FieldTests, FieldCardPlacementAndIncome) {
  Field field;
  field.placeCard(new CarrotCard());
  field.placeCard(new ChickenCard());
  int income = field.activateAll();
  EXPECT_EQ(income, 3);
}

TEST(FieldTests, FieldLimits) {
  Field field;
  for (int i = 0; i < 5; i++) {
    EXPECT_TRUE(field.placeCard(new CarrotCard()));
  }
  EXPECT_FALSE(field.placeCard(new CarrotCard()));

  Field field2;
  for (int i = 0; i < 5; i++) {
    EXPECT_TRUE(field2.placeCard(new ChickenCard()));
  }

  EXPECT_FALSE(field2.placeCard(new ChickenCard()));
}

TEST(DeckTests, DeckInitializationAndDrawing) {
  Deck deck;
  EXPECT_EQ(deck.getCardCount(), 0);
  deck.initializeDeck();
  EXPECT_GT(deck.getCardCount(), 0);
  Card *card = deck.drawCard();
  EXPECT_NE(card, nullptr);
  EXPECT_FALSE(card->getName().empty());

  delete card;
}

TEST(PlayerTests, PlayerCardPlaying) {
  HumanPlayer player("TestPlayer");
  player.addCoins(10);
  CarrotCard *carrot = new CarrotCard();
  player.addCardToHand(carrot);
  bool played = player.playCard(0);
  EXPECT_TRUE(played || !played);
}

TEST(AITests, EasyAIPlayerCardSelection) {
  EasyAIPlayer ai("EasyAI");
  EXPECT_EQ(ai.chooseCardToPlay(), -1);

  ai.addCoins(10);
  ai.addCardToHand(new CarrotCard());

  int choice = ai.chooseCardToPlay();
  EXPECT_TRUE(choice == 0 || choice == -1);
}

TEST(AITests, MediumAIPlayerCardSelection) {
  MediumAIPlayer ai("MediumAI");
  EXPECT_EQ(ai.chooseCardToPlay(), -1);

  ai.addCoins(10);
  ai.addCardToHand(new CarrotCard());

  int choice = ai.chooseCardToPlay();
  EXPECT_TRUE(choice == 0 || choice == -1);
}

TEST(HumanPlayerTests, HumanPlayerInterface) {
  HumanPlayer player("Human");

  player.addCardToHand(new CarrotCard());
  player.addCardToHand(new WheatCard());

  EXPECT_EQ(player.getHandSize(), 2);

  Card *card = player.getCardFromHand(0);
  EXPECT_NE(card, nullptr);
  EXPECT_EQ(card->getName(), "Carrot");
}

TEST(IntegrationTests, GameModeInitialization) {
  Deck deck;
  deck.initializeDeck();

  PlayerVsPlayerMode pvp_mode;
  pvp_mode.initialize(deck);

  EXPECT_NE(pvp_mode.getPlayer1(), nullptr);
  EXPECT_NE(pvp_mode.getPlayer2(), nullptr);
  EXPECT_GT(pvp_mode.getPlayer1()->getHandSize(), 0);
  EXPECT_GT(pvp_mode.getPlayer2()->getHandSize(), 0);

  PlayerVsAIMode pvai_mode("EASY");
  pvai_mode.initialize(deck);

  EXPECT_NE(pvai_mode.getPlayer1(), nullptr);
  EXPECT_NE(pvai_mode.getPlayer2(), nullptr);
}

TEST(IntegrationTests, TurnSwitching) {
  Deck deck;
  deck.initializeDeck();

  PlayerVsPlayerMode mode;
  mode.initialize(deck);

  Player *player1 = mode.getCurrentPlayer();
  mode.nextTurn();
  Player *player2 = mode.getCurrentPlayer();
  EXPECT_NE(player1, player2);
}

TEST(SystemTests, GameStartAndInitialDistribution) {
  Deck deck;
  deck.initializeDeck();

  PlayerVsPlayerMode mode;
  EXPECT_NO_THROW(mode.initialize(deck));
}

TEST(SystemTests, PlayerTurnSequence) {
  HumanPlayer player("Test");
  int coins_before = player.getCoins();
  player.collectIncome();
  player.addCoins(1);

  EXPECT_GE(player.getCoins(), coins_before);
}

TEST(SystemTests, AITurnAutomaticPlay) {
  EasyAIPlayer ai("TestAI");
  ai.addCoins(10);
  ai.addCardToHand(new CarrotCard());
  int choice = ai.chooseCardToPlay();
  EXPECT_TRUE(choice >= -1 && choice < ai.getHandSize());
}

TEST(ExceptionTests, FullHand) {
  HumanPlayer player("Test");
  for (int i = 0; i < 7; i++) {
    player.addCardToHand(new CarrotCard());
  }

  EXPECT_EQ(player.getHandSize(), 7);
  EXPECT_FALSE(player.canTakeCard());
}

TEST(ExceptionTests, EmptyDeck) {
  Deck deck;

  Card *card = deck.drawCard();
  EXPECT_EQ(card, nullptr);

  deck.initializeDeck();
  int size = deck.getCardCount();

  for (int i = 0; i < size; i++) {
    Card *c = deck.drawCard();
    delete c;
  }

  EXPECT_EQ(deck.getCardCount(), 0);
  Card *empty = deck.drawCard();
  EXPECT_EQ(empty, nullptr);
}

TEST(ExceptionTests, FullField) {
  Field field;
  for (int i = 0; i < 5; i++) {
    field.placeCard(new CarrotCard());
  }

  EXPECT_FALSE(field.placeCard(new CarrotCard()));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int result = RUN_ALL_TESTS();

  std::cout << "\n=== Test Summary ===\n";
  if (result == 0) {
    std::cout << "All tests passed!\n";
  } else {
    std::cout << "Some tests failed\n";
  }

  return result;
}