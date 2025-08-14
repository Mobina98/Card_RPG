# Architecture Overview — Card RPG

## General Description
Card RPG is a fantasy, turn-based, console card game where a human player battles against an AI opponent.  
The game features a deck-building system, special cards, spells, equipment, and quests.  
Players take turns drawing and playing cards to attack, defend, and gain strategic advantages.

The architecture follows an **object-oriented design** with over 20 classes organized in a hierarchy.  
Core components include:
- **Game Control** (Card_Game, Turn, Board, Battle)
- **Entities** (Player, Enemy, Deck, Card, Item, Equipment, Spell)
- **Gameplay Systems** (Effects, Skills, Quests, Achievements)
- **Resources & State** (Energy, HealthPotion, Level)

## High-Level Component Interaction
- The **Card_Game** orchestrates initialization, turn progression, and win/loss detection.
- **Board** manages all active entities in play.
- **Deck** manages card storage, shuffling, and drawing.
- **Turn** executes player and AI moves.
- **Battle** controls combat resolution.
- **AI** uses a simple decision-making algorithm to choose cards.
