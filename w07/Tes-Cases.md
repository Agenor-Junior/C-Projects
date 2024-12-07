# Test Cases for Treasure Hunt Game

This document outlines all possible test cases for the Treasure Hunt game, focusing on user inputs, game configurations, and gameplay outcomes.

---

## **Section 1: Player Configuration**

### Test Case 1: Set Player Symbol
- **Description:** Ensure the player symbol is correctly stored.
- **Input:** `@`
- **Expected Output:** Player symbol is set to `@`.
- **Status:** Pass/Fail

### Test Case 2: Set Lives Within Range
- **Description:** Validate the correct range for lives.
- **Input:** `5`
- **Expected Output:** Player lives set to `5`.
- **Status:** Pass/Fail

### Test Case 3: Set Lives Out of Range
- **Description:** Ensure lives outside the valid range trigger an error.
- **Input:** `12` (assuming max lives = 10)
- **Expected Output:** Error: "Must be between 1 and 10!"
- **Status:** Pass/Fail

---

## **Section 2: Game Configuration**

### Test Case 4: Set Path Length - Valid Input
- **Description:** Accept path lengths that are multiples of the divisor.
- **Input:** `20` (assuming divisor = 5)
- **Expected Output:** Path length set to `20`.
- **Status:** Pass/Fail

### Test Case 5: Set Path Length - Invalid Input
- **Description:** Reject path lengths not divisible by the divisor.
- **Input:** `23`
- **Expected Output:** Error: "Must be a multiple of 5 and between 10-70!"
- **Status:** Pass/Fail

### Test Case 6: Set Moves Within Range
- **Description:** Validate that the number of moves is within the calculated range.
- **Input:** `15`
- **Expected Output:** Moves set to `15`.
- **Status:** Pass/Fail

### Test Case 7: Set Moves Out of Range
- **Description:** Ensure moves outside the valid range trigger an error.
- **Input:** `50` (assuming max = 30)
- **Expected Output:** Error: "Value must be between 3 and 30."
- **Status:** Pass/Fail

---

## **Section 3: Bomb Placement**

### Test Case 8: Valid Bomb Placement
- **Description:** Ensure bomb positions are correctly stored.
- **Input:** `1 0 1 0` (for positions 1-4)
- **Expected Output:** Bombs set for positions 1 and 3.
- **Status:** Pass/Fail

### Test Case 9: Invalid Bomb Placement
- **Description:** Reject invalid bomb values (not 0 or 1).
- **Input:** `2`
- **Expected Output:** Error: "Invalid input, must be 0 or 1."
- **Status:** Pass/Fail

---

## **Section 4: Treasure Placement**

### Test Case 10: Valid Treasure Placement
- **Description:** Ensure treasure positions are correctly stored.
- **Input:** `1 0 1 0` (for positions 1-4)
- **Expected Output:** Treasures set for positions 1 and 3.
- **Status:** Pass/Fail

### Test Case 11: Invalid Treasure Placement
- **Description:** Reject invalid treasure values (not 0 or 1).
- **Input:** `2`
- **Expected Output:** Error: "Invalid input, must be 0 or 1."
- **Status:** Pass/Fail

---

## **Section 5: Gameplay**

### Test Case 12: Repeat Position
- **Description:** Warn the player when selecting an already visited position.
- **Input:** `5` (already visited)
- **Expected Output:** "Dope! You've been here before!"
- **Status:** Pass/Fail

### Test Case 13: Bomb and Treasure
- **Description:** Handle positions with both a bomb and treasure.
- **Input:** Position with bomb = `1`, treasure = `1`
- **Expected Output:** Life lost, treasure collected.
- **Status:** Pass/Fail

### Test Case 14: Only Bomb
- **Description:** Handle positions with only a bomb.
- **Input:** Position with bomb = `1`, treasure = `0`
- **Expected Output:** Life lost.
- **Status:** Pass/Fail

### Test Case 15: Only Treasure
- **Description:** Handle positions with only a treasure.
- **Input:** Position with bomb = `0`, treasure = `1`
- **Expected Output:** Treasure collected.
- **Status:** Pass/Fail

### Test Case 16: Nothing Found
- **Description:** Handle positions with no bomb or treasure.
- **Input:** Position with bomb = `0`, treasure = `0`
- **Expected Output:** "Nothing found here."
- **Status:** Pass/Fail

### Test Case 17: Out of Range Move
- **Description:** Warn the player when selecting an out-of-range position.
- **Input:** `-1` or `100` (assuming path length = 70)
- **Expected Output:** Error: "Out of Range!!!"
- **Status:** Pass/Fail

---

## **Section 6: End of Game**

### Test Case 18: Lives Depleted
- **Description:** End the game when no lives remain.
- **Input:** All lives lost.
- **Expected Output:** "No more LIVES remaining! Game over!"
- **Status:** Pass/Fail

### Test Case 19: Remaining Treasures
- **Description:** Show remaining treasures when the game ends.
- **Input:** Game over with uncollected treasures.
- **Expected Output:** Display treasure positions.
- **Status:** Pass/Fail

---

## **Additional Notes**
- Ensure all invalid inputs are gracefully handled.
- Test edge cases such as minimum and maximum values for all configurations.

Feel free to expand or modify these test cases as needed for additional coverage.
