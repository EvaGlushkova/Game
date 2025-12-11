# Farm Game Test Plan

## Unit testing:

#### Checking how the cards work:

- Card: creating a card, getting a name, cost

- CropCard: Testing income generation, crop type verification

- Animal Cards: Testing income generation, animal type verification

#### Testing Game Mechanics::

- Field: Placing cards (max 5 crops and 5 animals), calculating total income from all cards

- Deck: Initializing the deck, drawing cards, shuffling

- Player: Collecting income, playing cards, checking victory condition (30 coins), managing coins

#### Testing AI Behavior::

- EasyAIPlayer: Selecting cards to play 

- MediumAIPlayer: Selecting cards to play 

- HumanPlayer: Selecting cards from hand (user interaction)

## Integration testing:

#### Testing Component Interactions:

 - GameEngine + Player + AI + Field: Correct game state updates after each turn

 - Turn Switching: Proper handoff between player and AI in different game modes

 - Game Modes (GameMode): Correct initialization in PvP and PvAI modes

## System Testing:

#### Complete testing of the game in different scenarios:

  - Game Start: Player creation, initial card distribution

  - Player Turn: Income collection, drawing cards, playing cards
  
  - AI Turn: Automatic card selection and playing

  - Game End: Determining winner upon reaching 30 coins

## Testing Exception Handling:

- Insufficient Coins: Attempting to play a card without enough coins

- Full Hand: Attempting to draw a card with full hand (7 cards)

- Empty Deck: Attempting to draw from an empty deck

- Full Field: Attempting to place a card on a full field (5 crops or 5 animals)

## Testing Tools:

- Google Test
