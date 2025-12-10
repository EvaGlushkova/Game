# Functional Requirements
1. Game Modes: "Against AI"(easy, medium) and "Against Player"
2. Game Process Management
   * Sequential execution of turn phases
   * Field limit control (maximum 5 crops and 5 animals per player)
   * Hand size management (maximum 7 cards per player)

3. Economic System
   * Initial balance: 3 coins for each player
   * Victory condition: reaching 30 coins
   * Defeat condition: opponent's victory

4. Card System:
   * Deck of 24 cards (12 crops, 12 animals)
     
# The scenario of user interaction with the game
Before the game starts, the system displays the main menu where the player selects either "Against AI"(easy or medium) or "Against Player" mode. The system initializes the selected mode and the game begins.

## Against Player
1. The system randomly deals 1 card and 3 coins to each player
2. Player 1's turn:
   * The system automatically calculates income from all crops and animals on the field, if any
   * The system automatically adds +1 coin to the balance
   * If the player has 30 or more coins in balance, they win and the game ends
   * The player draws 1 card from the deck if they have no more than 7 cards in hand and there are cards in the deck
   * The player chooses one action: plant a crop or place an animal from their card (provided there is space for placement and sufficient coins to pay) and then the card is removed, or skip this action
3. Player 2's turn is similar
4. The game continues until one of the players collects 30 coins

## Against AI
1. The system randomly deals 1 card and 3 coins to each player
2. Player 1's turn is similar to the previous item
3. AI's turn
4. The game continues until one of the players collects 30 coins

The system determines the winner, displays the results screen indicating the winner, and terminates the game process