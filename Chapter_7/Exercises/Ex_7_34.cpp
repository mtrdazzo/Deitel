#include <Ex_7_34.h>
#include <ctime>
#include <cstdlib>

int main(void) {

    t_maze maze;

    createMaze(maze, 0, ARRAY_SIZE, 0, ARRAY_SIZE);

    printMaze(maze);
}

/**
 * Create a Maze using a recursive algorithm.
 *
 * @param maze    Two-dimensional maze object
 * @param min_row Minimum row index of the maze
 * @param max_row Maximum row index of the maze
 * @param min_col Minimum column index of the maze
 * @param max_col Maximum column index of the maze
 * @return        void
 */
void createMaze(t_maze& maze, size_t min_row, size_t max_row, size_t min_col, size_t max_col) {

    static bool firstPass{true};
    size_t random_row;
    size_t random_col;
    size_t valid_row;
    size_t valid_col;
    bool validHor;
    bool validVert;

    /* Create borders around maze, and exit/entry points */
    if (firstPass) {
        srand(static_cast<unsigned int>(time(0)));

        createBorders(maze, --max_row, --max_col);

        /* Left side entry */
        random_row = getRandomIndex(min_row + 1, max_row);
        maze[random_row][0] = false;

        /* Right side exit */
        random_row = getRandomIndex(min_col + 1, max_col);
        maze[random_row][max_col] = false;

        firstPass = false;
    }

    /* Find random row and column and create walls */
    if ((validHor = ((max_row - min_row > 3) && horizontalWallSpaceAvail(maze, min_row+2, max_row-2, min_col, max_col)))) {
        while (true) {
            random_row = getRandomIndex(min_row + 2, max_row - 1);
            if (maze[random_row][min_col] && maze[random_row][max_col]) {
                valid_row = random_row;
                break;
            }
        }
        /* Create Horizontal Wall */
        createHorizontalWall(maze, valid_row, min_col, max_col);
    }

    if ((validVert = ((max_col - min_col > 3) && verticalWallSpaceAvail(maze, min_row, max_row, min_col+2, max_col-2)))) {
        while (true) {
            random_col = getRandomIndex(min_col + 2, max_col - 1);
            if (maze[min_row][random_col] && maze[max_row][random_col]) {
                valid_col = random_col;
                break;
            }
        }

        /* Create Vertical Wall */
        createVerticalWall(maze, valid_col, min_row, max_row);
    }

    /* Both vertical and horizontal walls were made */
    if (validHor && validVert) {

        random_row = getRandomIndex(min_row+1, valid_row);
        maze[random_row][valid_col] = false;

        random_row = getRandomIndex(valid_row+1, max_row);
        maze[random_row][valid_col] = false;

        random_col = getRandomIndex(min_col+1, valid_col);
        maze[valid_row][random_col]= false;

        random_col = getRandomIndex(valid_col+1, max_col);
        maze[valid_row][random_col] = false;

        createMaze(maze, min_row, valid_row, min_col, valid_col); /* top left */
        createMaze(maze, valid_row, max_row, min_col, valid_col); /* top right */
        createMaze(maze, min_row, valid_row, valid_col, max_col); /* bottom left */
        createMaze(maze, valid_row, max_row, valid_col, max_col); /* bottom right */
    }
    else if (validHor) { /* only a horizontal wall was made */

        random_col = getRandomIndex(min_col+1, max_col);
        maze[valid_row][random_col]= false;

        createMaze(maze, valid_row, max_row, min_col, max_col); /* left */
        createMaze(maze, min_row, valid_row, min_col, max_col); /* right */
    }
    else if (validVert) { /* only a vertical wall was made */

        random_row = getRandomIndex(min_row+1, max_row);
        maze[random_row][valid_col] = false;

        createMaze(maze, min_row, max_row, min_col, valid_col); /* top */
        createMaze(maze, min_row, max_row, valid_col, max_col); /* bottom */
    } /* no valid spaces for walls */
    else
        return;
}

/**
 * Get a random index between the minimum and maximum indices given.
 *
 * @param min_index Minimum index
 * @param max_index Maximum index
 * @return          And random index between min_index and max_index
 */
size_t getRandomIndex(const size_t min_index, const size_t max_index) {
    return min_index + rand() % (max_index - min_index);
}

/**
 * Determine if there is a column available in the maze to place a horizontal wall. A wall can only be placed in a row
 * at least one row away from another wall, and the min and max column spaces must also already be a wall.
 *
 * @param maze    Two-dimensional maze object
 * @param min_row Minimum row index for the wall
 * @param max_row Maximum row index for the wall
 * @param min_col Minimum column index of the maze for the wall
 * @param max_col Maximum column index of the maze for the wall
 * @return        true if a horizontal wall can be placed between min_col and max_col, false otherwise
 */
bool horizontalWallSpaceAvail(const t_maze &maze, const size_t min_row, const size_t max_row, const size_t min_col, const size_t max_col) {
    for (size_t r{min_row}; r <= max_row; r++)
        if (maze[r][min_col] == true && maze[r][max_col] == true)
            return true;
    return false;
}

/**
 * Determine if there is a column available in the maze to place a vertical wall. A wall can only be placed in a column
 * at least one column away from another wall, and the min and max row spaces must also already be a wall.
 *
 * @param maze    Two-dimensional maze object
 * @param min_row Minimum row index for the wall
 * @param max_row Maximum row index for the wall
 * @param min_col Minimum column index of the maze for the wall
 * @param max_col Maximum column index of the maze for the wall
 * @return        true if a vertical wall can be placed between min_row and max_row, false otherwise
 */
bool verticalWallSpaceAvail(const t_maze &maze, const size_t min_row, const size_t max_row, const size_t min_col, const size_t max_col) {
    for (size_t c{min_col}; c <= max_col; c++)
        if (maze[min_row][c] == true && maze[max_row][c] == true)
            return true;
    return false;
}

/**
 * Create the solid outside border around the maze
 *
 * @param maze        Two-dimensional maze object
 * @param num_rows    Number of rows in the maze
 * @param num_columns Number of columns in the maze
 * @return            void
 */
void createBorders(t_maze& maze, const size_t num_rows, const size_t num_columns) {

    /* Vertical Border */
    for (size_t r{0}; r <= num_rows; r++) {
        maze[r][0] = true;
        maze[r][num_columns] = true;
    }

    /* Horizontal Border */
    for (size_t c{0}; c <= num_columns; c++) {
        maze[0][c] = true;
        maze[num_rows][c] = true;
    }
}

/**
 * Print the maze.
 *
 * @param maze Two-dimensional maze object
 * @return     void
 */
void printMaze(const t_maze &maze) {
    for(size_t r{0}; r < maze.size(); r++) {
        for (size_t c{0}; c < maze[0].size(); c++)
            std::cout << (maze[r][c] ? "# " : ". ");
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Create a horizontal wall in the maze from min_col to max_col
 *
 * @param maze    Two-dimensional maze object
 * @param row     Row index for the wall
 * @param min_col Minimum column index of the maze for the wall
 * @param max_col Maximum column index of the maze for the wall
 * @return        void
 */
void createHorizontalWall(t_maze &maze, const size_t row, const size_t min_col, const size_t max_col) {
    for (size_t c{min_col}; c < max_col; c++)
        maze[row][c] = true;
}

/**
 * Create a vertical wall in the maze from min_row to max_row
 *
 * @param maze    Two-dimensional maze object
 * @param col     Column index for the wall
 * @param min_row Minimum row index of the maze for the wall
 * @param max_row Maximum row index of the maze for the wall
 * @return        void
 */
void createVerticalWall(t_maze &maze, const size_t col, const size_t min_row, const size_t max_row) {
    for (size_t r{min_row}; r < max_row; r++)
        maze[r][col] = true;
}
