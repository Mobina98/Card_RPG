# Test Plan — Card RPG

## Objectives
Verify that the Card RPG game functions according to its requirements.

## Test Categories
1. **Unit Tests**
   - Card effects apply correctly.
   - Deck shuffling produces different orders.
   - Drawing from an empty deck is handled gracefully.
   - Energy increases/decreases as expected.

2. **Integration Tests**
   - Playing a card updates board state.
   - Turn switching between player and AI.
   - Battle system ends the game correctly.

3. **AI Behavior Tests**
   - AI always plays valid cards.
   - AI prioritizes attack when opponent is near defeat.

4. **Negative Tests**
   - Player tries to play a card without enough energy.
   - Drawing from an empty deck.

## Tools
- **GoogleTest** for unit and integration testing.
- GitHub Actions for CI.

## Acceptance Criteria
- All tests pass on GitHub Actions.
- Game flow matches documented scenarios.
