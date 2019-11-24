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

uint16_t moves = 0xFFFF;

const char *strings[] = {"NORTH", "EAST", "SOUTH", "WEST"};

bool moveNeg90Degrees(t_maze &maze, s_location* cur_pos, Direction *cur_dir);
bool move90Degrees(t_maze &maze, s_location* cur_pos, Direction *cur_dir);
Direction rotate90Degrees(Direction cur_dir);
bool moveFoward(t_maze &maze, s_location* cur_pos, Direction cur_dir);

const std::array<int, (int)Direction::NUM_DIRECTIONS> r_moves {-1, 0, 1, 0};
const std::array<int, (int)Direction::NUM_DIRECTIONS> c_moves {0, 1, 0, -1};

int main(int argc, char **argv) {

     t_maze sample_maze = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                           '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
                           '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
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

    if (argc > 1)
        moves = std::atoi(*++argv);

     mazeTraverse(sample_maze, locale);

}

bool moveNeg90Degrees(t_maze &maze, s_location* cur_pos, Direction *cur_dir) {

    int rotated_dir = (static_cast<int>(rotate90Degrees(*cur_dir)) + 2) % static_cast<int>(Direction::NUM_DIRECTIONS);
    bool canMove;

    canMove = (maze[cur_pos->row + r_moves[rotated_dir]][cur_pos->column + c_moves[rotated_dir]] == '.');

    if (canMove) {
        cur_pos->row += r_moves[rotated_dir];
        cur_pos->column += c_moves[rotated_dir];
        *cur_dir = static_cast<Direction>(rotated_dir);
    }

    return canMove;
}

bool move90Degrees(t_maze &maze, s_location* cur_pos, Direction *cur_dir) {

    int rotated_dir = static_cast<int>(rotate90Degrees(*cur_dir));
    bool canMove;

    canMove = (maze[cur_pos->row + r_moves[rotated_dir]][cur_pos->column + c_moves[rotated_dir]] == '.');

    if (canMove) {
        cur_pos->row += r_moves[rotated_dir];
        cur_pos->column += c_moves[rotated_dir];
        *cur_dir = static_cast<Direction>(rotated_dir);
    }

    return canMove;
}

bool moveFoward(t_maze &maze, s_location* cur_pos, Direction cur_dir) {
    bool canMove{false};

    canMove = (maze[cur_pos->row + r_moves[(int)cur_dir]][cur_pos->column + c_moves[(int)cur_dir]] == '.');

    if (canMove) {
        cur_pos->row += r_moves[(int)cur_dir];
        cur_pos->column += c_moves[(int)cur_dir];
        std::cout << (int)cur_pos->row << (int)cur_pos->column << std::endl;
    }

    return canMove;

}

Direction rotate90Degrees(Direction cur_dir) {
    return static_cast<Direction>((static_cast<int>(cur_dir) + 1)
            % static_cast<int>(Direction::NUM_DIRECTIONS));
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

    std::cout << "Move Number: " << int(moveNum) << std::endl;
    printMaze(maze, pos);

    if (moveNum >= moves) {
        return;
    }

    if (moveNum > 1 && hasExited(pos)) {
        std::cout << "Out of the maze!" << std::endl;
        return;
    }

    while (!has_moved) {
        if (move90Degrees(maze, &pos, &current_direction)) {
            has_moved = true;
            std::cout << "Moving 90 Degrees: " << strings[(int)(current_direction)] << std::endl;
        }
        else if (moveFoward(maze, &pos, current_direction)) {
            std::cout << "Moving Forward: " << strings[(int)(current_direction)] << std::endl;
            has_moved = true;
        }
        else if (moveNeg90Degrees(maze, &pos, &current_direction)) {
            std::cout << "Moving -90 Degrees: " << strings[(int)(current_direction)] << std::endl;
            has_moved = true;
        }
        else
        {
            current_direction = rotate90Degrees(current_direction);
            std::cout << "Rotating 90 degrees to: " << strings[(int)(current_direction)] << std::endl;
        }
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
