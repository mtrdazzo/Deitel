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
 * Usage:
 *
 * ./a.out                    Run until out of maze
 * ./a.out <NUMBER_OF_TURNS>  Rum until NUMBER_OF_TURNS
 *
 */

#include <iostream>
#include <array>
#include "Ex_7_33.h"

bool moveNumberDegrees(const t_maze&, s_location&, Direction&);
bool move270Degrees(const t_maze&, s_location&, Direction&);
bool move90Degrees(const t_maze&, s_location&, Direction&);
bool moveCurrentDirection(const t_maze&, s_location&, Direction&);
Direction rotate90Degrees(const Direction);

const std::array<int, (int)Direction::NUM_DIRECTIONS> r_moves {-1, 0, 1, 0};
const std::array<int, (int)Direction::NUM_DIRECTIONS> c_moves {0, 1, 0, -1};

int main(int argc, char **argv) {

     t_maze sample_maze = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                           '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
                           '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '.',
                           '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
                           '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#',
                           '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                           '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                           '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
                           '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
                           '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
                           '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
                           '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
       s_location locale{2, 0};

     mazeTraverse(sample_maze, locale);

}

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
    static Direction current_direction{Direction::SOUTH};
    bool has_moved{false};

    printMaze(maze, pos);

    if (moveNum && exitedMaze(pos)) {
        std::cout << "CONGRATULATIONS!!!\n";
        std::cout << "Took " << moveNum << " moves to get out of the maze!\n" << std::endl;
        return;
    }

    while (!has_moved) {
        if ((has_moved = move90Degrees(maze, pos, current_direction)));
        else if ((has_moved = moveCurrentDirection(maze, pos, current_direction)));
        else if ((has_moved = move270Degrees(maze, pos, current_direction)));
        else
            current_direction = rotate90Degrees(current_direction);
    }

    moveNum++;
    mazeTraverse(maze, pos);
}

/**
 *
 * Determine if the maze has been exited.
 *
 * @param pos  curent position in the maze
 * @return true if maze has been exited, else false
 */
bool exitedMaze(const s_location& pos) {
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

bool moveNumberDegrees(const t_maze &maze, const int degrees, s_location& current_pos, Direction& current_dir) {

    int rotated_row{0};
    int rotated_col{0};
    int rotated_index{0};
    Direction rotated_dir{current_dir};

    for (int deg{0}; deg < degrees; deg += 90)
        rotated_dir = rotate90Degrees(rotated_dir);

    rotated_index = static_cast<int>(rotated_dir);
    rotated_row = current_pos.row + r_moves[rotated_index];
    rotated_col = current_pos.column + c_moves[rotated_index];

    if (maze[rotated_row][rotated_col] == '.') {
        current_pos.row = rotated_row;
        current_pos.column = rotated_col;
        current_dir = rotated_dir;
        return true;
    }
    else
    {
        return false;
    }
}

Direction rotate90Degrees(const Direction cur_dir) {
    return static_cast<Direction>((static_cast<int>(cur_dir) + 1)
            % static_cast<int>(Direction::NUM_DIRECTIONS));
}

bool move90Degrees(const t_maze &maze, s_location& current_pos, Direction& current_dir) {

    return moveNumberDegrees(maze, 90, current_pos, current_dir);
}

bool move270Degrees(const t_maze &maze, s_location& current_pos, Direction& current_dir) {

    return moveNumberDegrees(maze, 270, current_pos, current_dir);
}

bool moveCurrentDirection(const t_maze &maze, s_location& current_pos, Direction& current_dir) {

    return moveNumberDegrees(maze, 0, current_pos, current_dir);
}
