# System Requirements

## Functional Requirements
1. **Gameplay**
   - The game must allow a human to play against an AI opponent.
   - Each player must start with a predefined deck of cards.
   - Players take turns to draw and play cards.
   - Cards can have effects such as dealing damage, healing, or modifying stats.

2. **Card Types**
   - Attack cards (deal damage to opponents)
   - Spell cards (special effects with mana cost)
   - Equipment cards (increase stats)
   - Item cards (e.g., health potions)

3. **Game Flow**
   - Start game → Initialize decks and health
   - Turn loop: Draw → Play → Resolve effects → End turn
   - End game when one player's health is 0.

4. **AI**
   - AI must make reasonable card choices.
   - AI uses a basic heuristic (e.g., prioritize attack if opponent health is low).

5. **Persistence**
   - The game does not require saving progress (in Step 1–4 scope).

## Non-Functional Requirements
- Written in **C++17**.
- Compilable with CMake.
- Tested with GoogleTest.
- Console-based interface.
- Code documented using Doxygen.

## Constraints
- No external game engine (console only).
- At least 20 classes implemented.
