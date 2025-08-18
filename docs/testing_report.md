# Step 4: Testing Report

## 1. Introduction
This report documents the testing performed on the Card RPG core system.
The objectives of testing are:
- Verify that all components (cards, deck, battle loop, AI) behave as expected.
- Ensure the system meets requirements defined in Step 2.
- Detect and fix defects before final delivery.

## 2. Test Environment
- **OS**: Ubuntu 22.04 (GitHub Actions runner, local VirtualBox Linux)
- **Compiler**: g++ 13 with C++17 standard
- **Build system**: CMake 3.10+
- **Testing framework**: GoogleTest
- **CI**: GitHub Actions (Ubuntu latest)

## 3. Test Plan Summary
The following aspects were tested:
1. **Deck mechanics**  
   - Shuffling changes card order.  
   - Drawing reduces deck size.  
2. **Card effects**  
   - AttackCard reduces opponent HP.  
   - HealCard restores HP.  
   - SpellCard buffs next attack.  
   - TrapCard deals counter-damage when attacked.  
3. **Battle system**  
   - Turn order alternates correctly.  
   - HP reaches 0 → correct winner announced.  
   - Game ends after max 10 turns.  
4. **AI**  
   - AI heals itself when HP low.  
   - AI attacks otherwise.  

## 4. Test Cases and Results
| Test Case | Description | Expected Result | Actual Result | Status |
|-----------|-------------|-----------------|---------------|--------|
| TC-01 | Shuffle deck | Order differs from initial | Order changed | ✅ Pass |
| TC-02 | Draw card | Deck size decreases by 1 | Decreased | ✅ Pass |
| TC-03 | AttackCard | Enemy HP reduced by damage | Correctly reduced | ✅ Pass |
| TC-04 | HealCard | Player HP increased | Correctly increased | ✅ Pass |
| TC-05 | SpellCard | Buff applies to next attack | Works as expected | ✅ Pass |
| TC-06 | TrapCard | Counter damage applied | Works as expected | ✅ Pass |
| TC-07 | Battle End HP | Winner determined at 0 HP | Correct winner | ✅ Pass |
| TC-08 | Battle Max Turns | Winner chosen by HP after 10 turns | Works as expected | ✅ Pass |
| TC-09 | AI Behavior | AI heals at low HP, attacks otherwise | Behavior observed | ✅ Pass |

## 5. Bugs Found & Fixes
- **Bug**: In `Card_Game::printState()`, inconsistent `auto` deduction.  
  - **Fix**: Explicitly separated `std::shared_ptr<Player>` and `std::shared_ptr<Enemy>`.  

No other functional bugs observed.

## 6. Conclusion
All planned tests executed successfully.  
The system meets the functional requirements defined in Step 2.  
No critical issues remain.  

The project is ready for submission.
