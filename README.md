# 🎮 so_long — 42 Project

The goal is to handle window management, event handling, and sprite rendering using the **MiniLibX** library.


## 🎯 Objective

The player must:
- Collect **all the collectibles** (`C`)
- Reach the **exit** (`E`)
- Navigate the map without passing through walls

The game ends when all collectibles have been picked up and the player reaches the exit.

---

## ✨ Features

- Map parsing and validation (`.ber` files)
- Fully checked map:
  - Surrounded by walls
  - Includes 1 player (`P`), at least 1 collectible (`C`), and 1 exit (`E`)
  - Only valid characters allowed
  - Rectangular shape
- 2D rendering using MiniLibX
- Movement counter displayed in the terminal
- Error handling for invalid maps
- Simple and clean code structure following 42 Norm

---

## 🗺️ Map Format

Example of a valid `.ber` map:
1111111
1P0C0E1
1000001
1111111

### 🔤 Legend

| Character | Meaning         |
|-----------|-----------------|
| `1`       | Wall            |
| `0`       | Empty space     |
| `P`       | Player position |
| `C`       | Collectible     |
| `E`       | Exit            |

---

## ▶️ How to Run

### 1️⃣ Clone the repository
```bash
git clone https://github.com/RosseMry/42cursus-so_long.git
cd 42cursus-so_long

