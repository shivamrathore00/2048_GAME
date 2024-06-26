# 2048 Game Implementation

## Overview
This project is a console-based implementation of the popular 2048 game. The game is built using C++ and simulates the 2048 game mechanics with a simple text interface.

## How to Play
The objective of the game is to combine tiles with the same numbers by sliding them in one of the four directions (Up, Down, Left, Right) to form larger numbers.
The ultimate goal is to create a tile with the number 2048. The game ends when there are no possible moves left.

## Features
- Random generation of new tiles (2 or 4) after each move.
- Merging of tiles when they collide with the same number.
- Calculation and display of the score based on the tile values.
- Game-over condition when no moves are possible.

## Requirements
- C++ Compiler (GCC, Clang, etc.)

## Compilation and Execution
1. Compile the code using a C++ compiler:
   ```bash
   g++ -o game2048 game2048.cpp
   ```

2. Run the executable:
   ```bash
   ./game2048
   ```

## Code Structure

### `Game2048` Structure
- `board[4][4]`: Represents the game board.
- `void score()`: Calculates and prints the current score.
- `void random()`: Generates a new tile (2 or 4) at a random empty position.
- `void init()`: Initializes the game board with two random tiles.
- `bool end()`: Checks if the game is over (no possible moves).
- `void push(int array[])`: Merges tiles in the array.
- `void print()`: Prints the current state of the game board.
- `void move(int dir)`: Moves tiles in the specified direction (0 = up, 1 = down, 2 = left, 3 = right).

### `main()` Function
- Initializes the game.
- Continuously prompts the user for a move until the game is over.
- Validates user input and calls the appropriate move function.
- Prints the game-over message when no moves are possible.

## Controls
- `U` or `u`: Move tiles up.
- `D` or `d`: Move tiles down.
- `L` or `l`: Move tiles left.
- `R` or `r`: Move tiles right.

## Example Gameplay
```
What Move? (U,D,L,R): U
 2    4    8   16
 4    8   16   32
 8   16   32   64
16   32   64  128
Your Score: 320
What Move? (U,D,L,R): D
 ...
```

## Notes
- The game will print "Input Not Allowed!" if the move does not change the board state.
- The game automatically generates a new tile after each valid move.
- The score is calculated based on the value of the tiles on the board.

## Author
This 2048 game implementation was created by Shivam Rathore.

