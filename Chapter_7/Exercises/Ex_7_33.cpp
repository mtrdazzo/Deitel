/**
 * Exercise 7-33 Maze Traversal
 *
 * There is a simple algorithm for walking through a maze that guarantees finding the exit
 * (assuming there is an exit). If there is not an exit, you'll arrive at the starting location
 * again. Place your right hand on the wall to your right and begin walking forward. Never move
 * your hand from the wall. If the maze turns to the right, you follow the wall to the right.
 * As long as you do not remove your hand from the wall, eventually you'll arrive at the exit
 * of the maze.
 *
 * Write a recursive function mazeTraverse to walk through the maze. The function should
 * receive arguments that include a 12 by 12 built-in array of chars representing the maze
 * and the starting location of the maze. As mazeTraverse attempts to locate the exit from
 * the maze, it should place the character X in each square in the path. The function should
 * display the maze after each move so the user can watch as the maze is solved.
 *
 */

#include <iostream>
#include <array>

#define GRID_LENGTH 12

typedef std::array<std::array<char, GRID_LENGTH>, GRID_LENGTH> t_maze;

struct location {
    char row;
    char column;
};

/**
 * Attempts to locate the exit from the input maze using a recursive solution.
 * It will place the character X in each square on the path and will display
 * the maze after each move.
 *
 * @param maze  12 x 12 grid of values that represent open, closed, and already
 *              traveled spaced.
 * @return void
 */
void mazeTraverse(t_maze & maze, location& pos) {

}

/**
 *
 * Print the values of array of the maze.
 *
 * @param maze  2D (12 x 12) array representing a maze.
 * @return void
 */
void printMaze(const t_maze &maze) {
    for (auto& row : maze) {
        for (char space : row)
            std::cout << static_cast<int>(space) << " ";
        std::cout << std::endl;
    }
}