/*
 * Exercise 7-22 Knight's Tour
 *
 * Write a program to move the knight around the chessboard. Run the program.
 * 
 */

#include <iostream>
#include <array>
#include <iomanip>
#include <cstdlib>

#define NUM_ROWS    0x08
#define NUM_COLUMNS 0x08
#define NUM_MOVES   0x08

std::array<std::array<int8_t, NUM_COLUMNS>, NUM_ROWS> chess_board{ 0 };
std::array<std::array<uint8_t, NUM_COLUMNS>, NUM_ROWS> availability{0};
const std::array<int8_t, NUM_MOVES> vertical{2,1,-1,-2,-2,-1,1,2};
const std::array<int8_t, NUM_MOVES> horizontal{-1,-2,-2,-1,1,2,2,1};

void printBoard(void);
bool checkSpace(uint8_t, uint8_t);
void updateAvailability(void);
void printAvailability(void);

int main(int argc, char **argv) {

    uint8_t moveNumber;
    uint8_t newRow;
    uint8_t newColumn;
    uint8_t currentRow;
    uint8_t currentColumn;
    int8_t lowestAvailability;
    int8_t lowestIndex;

    srand(static_cast<unsigned int>(time(0)));

    for (size_t r_start{0}; r_start < NUM_ROWS; r_start++) {

        for (size_t c_start{0}; c_start < NUM_ROWS; c_start++) {
            
            currentRow = r_start;
            currentColumn = c_start;
            moveNumber = 1;

            std::cout << "Starting at: (" << static_cast<int>(r_start+1) << ", " << static_cast<int>(c_start+1) << ")" << std::endl;

            for (uint8_t row{0}; row < NUM_ROWS; row++)
                for (uint8_t column{0}; column < NUM_COLUMNS; column++)
                    chess_board[row][column] = 0;
           
            chess_board[currentRow][currentColumn] = moveNumber;
            updateAvailability();

            while (moveNumber < NUM_ROWS * NUM_COLUMNS) {

                lowestAvailability = 9;
                lowestIndex = -1;

                for (size_t move{0}; move < NUM_MOVES; ++move) {
                    newRow = currentRow + vertical[move];
                    newColumn = currentColumn + horizontal[move];
                    if (checkSpace(newRow, newColumn) && (availability[newRow][newColumn] < lowestAvailability)) {
                        lowestAvailability = availability[newRow][newColumn];
                        lowestIndex = move;
                    }
                }
                
                currentRow += vertical[lowestIndex];
                currentColumn += horizontal[lowestIndex];
                ++moveNumber;
                chess_board[currentRow][currentColumn] = moveNumber;
                updateAvailability();
            }
            printBoard();
        }
    }
    return EXIT_SUCCESS;
}

/* updateAvailability: update availability array */
void updateAvailability(void) {

    for(size_t i{0}; i < NUM_ROWS; i++)
        for(size_t j{0}; j < NUM_COLUMNS; j++)
            availability[i][j] = 0;

    for(size_t i{0}; i < NUM_ROWS; i++)
        for(size_t j{0}; j < NUM_COLUMNS; j++) {
            if (!checkSpace(i, j)) {
                availability[i][j] = 0;
                continue;
            }
            for (size_t k{0}; k < NUM_MOVES; k++)
                if (checkSpace(i + horizontal[k], j + vertical[k]))
                    ++availability[i + horizontal[k]][j + vertical[k]];
        }
}

/* printAvailabilityL print availability board */
void printAvailability(void) {
    for(size_t i{0}; i < NUM_ROWS; i++) {
        for(size_t j{0}; j < NUM_COLUMNS; j++)
            std::cout << static_cast<int>(availability[i][j]) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* printBoard: print the chess board */
void printBoard(void) {

    std::cout << "  ";
    for (int column{0}; column < NUM_COLUMNS; column++)
        std::cout << std::setw(2) << column + 1 << " ";
    std::cout << std::endl;

    for(uint8_t row{0}; row < chess_board.size(); row++) {
        std::cout << static_cast<int>(row+1) << " ";
        for (uint8_t column{0}; column < NUM_ROWS; column++)
            std::cout << std::setw(2) << static_cast<int>(chess_board[row][column]) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/* checkSpace: check if chessBoard space at (row, column) is valid */
bool checkSpace(uint8_t row, uint8_t column) {
    return (row >= 0 && 
            row < NUM_COLUMNS &&
            column >= 0 &&
            column < NUM_ROWS &&
            !chess_board[row][column]);
}