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
#include "Ex_7_33.h"

uint16_t moves;

int main(int argc, char **argv) {

     t_maze sample_maze = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                           '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
                           '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
                           '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
                           '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
                           '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                           '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                           '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                           '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
                           '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
                           '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
                           '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
       s_location locale{2, 0};

    if (argc > 1)
        moves = std::atoi(*++argv);

     mazeTraverse(sample_maze, locale);

}

enum class Direction {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
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
void mazeTraverse(t_maze & maze, s_location& pos) {

    static uint16_t moveNum{0};
    static Direction current_direction{Direction::WEST};
    bool has_moved{false};

    if (moves > 0 && moveNum > moves) {
        return;
    }

    if (moveNum > 1 && hasExited(pos)) {
        printMaze(maze, pos);
        return;
    }

    std::cout << "Move Number: " << int(moveNum) << std::endl;
    printMaze(maze, pos);

    while (!has_moved) {
        std::cout << (int)(current_direction) << std::endl;
        switch(current_direction) {
            case Direction::NORTH:
                if (maze[pos.row][pos.column+1] == '#') {
                    if (maze[pos.row-1][pos.column] == '.') {
                        --pos.row;
                    }
                    else if (maze[pos.row][pos.column-1]){
                        --pos.column;
                        current_direction = Direction::WEST;
                    }
                    has_moved = true;
                }
                else if (maze[pos.row][pos.column+1] == '.') {
                    ++pos.column;
                    has_moved = true;
                    current_direction = Direction::EAST;
                }
                else if (maze[pos.row-1][pos.column] == '.') {
                    current_direction = Direction::NORTH;
                    --pos.row;
                    has_moved = true;
                }
                else
                    current_direction = Direction::SOUTH;
                break;
            case Direction::EAST:
                if (maze[pos.row+1][pos.column] == '#') {
                    if (maze[pos.row][pos.column+1] == '.') {
                        ++pos.column;
                    }
                    else if (maze[pos.row-1][pos.column] == '.') {
                        current_direction = Direction::NORTH;
                        --pos.row;
                    }
                    has_moved = true;
                }
                else if (maze[pos.row+1][pos.column] == '.') {
                    ++pos.row;
                    has_moved = true;
                    current_direction = Direction::SOUTH;
                }
                else if (maze[pos.row][pos.column+1] == '.') {
                    current_direction = Direction::EAST;
                    ++pos.column;
                    has_moved = true;
                }
                else
                    current_direction = Direction::WEST;
                break;
            case Direction::SOUTH:
                if (maze[pos.row][pos.column-1] == '#') {
                    if (maze[pos.row+1][pos.column] == '.') {
                        ++pos.row;
                    }
                    else if (maze[pos.row][pos.column+1] == '.'){
                        current_direction = Direction::EAST;
                        ++pos.column;
                    }
                    has_moved = true;
                }
                else if (maze[pos.row][pos.column-1] == '.') {
                    current_direction = Direction::WEST;
                    --pos.column;
                    has_moved = true;
                }
                else if (maze[pos.row+1][pos.column] == '.') {
                    current_direction = Direction::SOUTH;
                    ++pos.row;
                    has_moved = true;
                }
                else
                    current_direction = Direction::NORTH;
                break;
            case Direction::WEST:
                if (maze[pos.row-1][pos.column] == '#') {
                    if (maze[pos.row][pos.column-1] == '.') {
                        --pos.column;
                    has_moved = true;

                    }
                    else if (maze[pos.row+1][pos.column] == '.')
                    {
                        ++pos.row;
                        current_direction = Direction::SOUTH;
                        has_moved = true;
                    }
                    else {
                        current_direction = Direction::EAST;
                    }
                }
                else if (maze[pos.row-1][pos.column] == '.') {
                    --pos.row;
                    current_direction = Direction::NORTH;
                    has_moved = true;
                }
                else if (maze[pos.row][pos.column-1] == '.') {
                    current_direction = Direction::WEST;
                    --pos.column;
                    has_moved = true;
                }
                else
                    current_direction = Direction::EAST;
                break;
            default:
                exit(1); // should never enter
        }
    }
    moveNum++;
    std::cout << (int)(current_direction) << std::endl;

    mazeTraverse(maze, pos);
}

/**
 *
 * Determine if the maze has been exited.
 *
 * @param pos  curent position in the maze
 * @return true if maze has been exited, else false
 */
bool hasExited(const s_location& pos) {
    return (pos.column == 0 || pos.column == MAZE_SIZE - 1 ||
            pos.row == 0 || pos.row == MAZE_SIZE - 1);
}

/**
 *
 * Print the values of array of the maze.
 *
 * @param maze  2D (12 x 12) array representing a maze.
 * @return void
 */
void printMaze(const t_maze &maze, const s_location& current) {
    for (uint8_t row{0}; row < MAZE_SIZE; row++) {
        for (uint8_t column{0}; column < MAZE_SIZE; column++)
            if (row == current.row && column == current.column)
                std::cout << "X" << " ";
            else
                std::cout << maze[row][column] << " ";

        std::cout << std::endl;
    }
    std::cout << '\n';
}

/**
 * Check if (row, column) is a space on the board.
 *
 * @param pos position in maze
 * @return true if is a valid position in the maze array
 */
bool inMaze(const s_location& pos) {
    return (pos.row >= 0 && pos.row < MAZE_SIZE) &&
           (pos.column >=0 && pos.column < MAZE_SIZE);
}
