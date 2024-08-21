# So Long - 42Cursus Project

**So long** is a **42 cursus** project. The goal is to create a 2D game using the Minilibx library. The goal of the game is to guide the character through a maze, collect items and reach the exit. The project helps to practice your skills in event handling and working with the Minilibx library.

## ✨ Project Overview

The game involves a simple map represented by a grid where the player character moves around, collects items and finds the exit to win. The map is loaded from a file and the player interacts with the game using keyboard inputs.

### 🎯 Features:
- **2D grid-based game**
- **Map parsing**
- **Graphic rendering**
- **Events handling**

## ⭐ Mandatory Part

### Parsing
The map can only contain the following characters:
- **0**: Empty space.
- **1**: Wall.
- **C**: Collectible.
- **E**: Exit.
- **P**: Player.
 
There must be 1 exit, 1 player position and at least 1 collectible.

The map must be rectangular and surronded by walls. It must be in a `.ber` file.

### Gameplay
Play with the keys **W**, **A**, **S**, **D**. Close the game with **Esc**.

You can only exit the map after getting all collectibles.

The move count will be displayed in the terminal after each move.

### Graphic
You can change the sprites of the game in the `textures` directory. The game takes `.xmp` files.

## 💫 Bonus Part
The following bonuses have been implemented:
- Player lose when they touch an enemy.
- Some sprite animation.
- Movement count is displayed directly on screen.

## 🛠️ Installation & Compilation Guide

### 🏗️ Compilation

Clone the repository:
```bash
git clone https://github.com/jgdmt/so_long.git
```
Compile (executable is `so_long`):
```bash
make
```
Compile the bonus (executable is `so_long_bonus`):
```bash
make bonus
```

## 🚀 Usage

Start the game with the following command:
```bash
./so_long [path_of_the_map] # Basic game
./so_long_bonus [path_of_the_map] # Game with bonuses
```
Maps are included in the project. You can try one:
```bash
./so_long maps/haha.ber
./so_long_bonus maps/speedrun.ber
```
