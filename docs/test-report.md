# Test Report 
### 1. Unit Tests

#### 1.1 Card Component Tests
- **Test Suite**: `CardTests`
- **Test Count**: 1
- **Status**: **PASSED**
- **Tests Executed**:
  - `CardCreationAndBasicProperties` - Validates basic card properties creation and validation

#### 1.2 Crop Card Tests
- **Test Suite**: `CropCardTests`
- **Test Count**: 1
- **Status**: **PASSED**
- **Tests Executed**:
  - `CropCardIncomeAndType` - Validates crop card income calculation and type identification

#### 1.3 Animal Card Tests
- **Test Suite**: `AnimalCardTests`
- **Test Count**: 1
- **Status**: **PASSED**
- **Tests Executed**:
  - `AnimalCardIncomeAndType` - Validates animal card income calculation and type identification

#### 1.4 Field Component Tests
- **Test Suite**: `FieldTests`
- **Test Count**: 2
- **Status**: **PASSED**
- **Tests Executed**:
  - `FieldCardPlacementAndIncome` - Tests card placement functionality and income generation
  - `FieldLimits` - Validates field capacity limits (max 5 cards per field)

#### 1.5 Deck Component Tests
- **Test Suite**: `DeckTests`
- **Test Count**: 1
- **Status**: **PASSED**
- **Tests Executed**:
  - `DeckInitializationAndDrawing` - Tests deck initialization and card drawing mechanics

#### 1.6 Player Component Tests
- **Test Suite**: `PlayerTests`
- **Test Count**: 1
- **Status**: **PASSED**
- **Tests Executed**:
  - `PlayerCardPlaying` - Tests player card playing mechanics and validation

### 2. AI Component Tests

#### 2.1 AI Player Tests
- **Test Suite**: `AITests`
- **Test Count**: 2
- **Status**: **PASSED**
- **Tests Executed**:
  - `EasyAIPlayerCardSelection` - Tests easy AI decision making algorithm
  - `MediumAIPlayerCardSelection` - Tests medium AI decision making algorithm

### 3. Human Player Tests

#### 3.1 Human Interface Tests
- **Test Suite**: `HumanPlayerTests`
- **Test Count**: 1
- **Status**: **PASSED**
- **Tests Executed**:
  - `HumanPlayerInterface` - Tests human player interface functionality and card management

### 4. Integration Tests

#### 4.1 Game Integration Tests
- **Test Suite**: `IntegrationTests`
- **Test Count**: 2
- **Status**: **PASSED**
- **Tests Executed**:
  - `GameModeInitialization` - Tests game mode setup and initialization
  - `TurnSwitching` - Tests turn management and switching between players

### 5. System Tests

#### 5.1 End-to-End Game Tests
- **Test Suite**: `SystemTests`
- **Test Count**: 3
- **Status**: **PASSED**
- **Tests Executed**:
  - `GameStartAndInitialDistribution` - Tests game startup and initial card distribution
  - `PlayerTurnSequence` - Tests complete player turn sequence
  - `AITurnAutomaticPlay` - Tests AI automatic turn execution

### 6. Exception Tests

#### 6.1 Error Handling Tests
- **Test Suite**: `ExceptionTests`
- **Test Count**: 3
- **Status**: **PASSED**
- **Tests Executed**:
  - `FullHand` - Tests handling of full hand scenarios
  - `EmptyDeck` - Tests handling of empty deck scenarios
  - `FullField` - Tests handling of full field scenarios


