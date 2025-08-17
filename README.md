# Fantasy Card RPG — Step 3 Core

Plain-text console card RPG (human vs AI). Short demo loop (max 10 turns).

## Build
```
mkdir build && cd build
cmake ..
cmake --build .
```

## Run
```
./Card_RPG
```

## How to Play
- Each turn you automatically draw a card.
- Your Energy refreshes each turn (max 10). Cards have a cost.
- Choose a card by number to play it. 0 = skip.
- **Card Types**:
  - AttackCard: Deal 5 damage (cost 2).
  - HealCard: Heal 4 (cost 2).
  - SpellCard: Buff your next attacks +2 for 2 turns (cost 3).
  - TrapCard: Immediate counter-damage 3 (cost 1).
- Win by dropping opponent HP to 0, or by higher HP after turn 10.

## Tests
```
cd build
ctest --output-on-failure
```
