/**
 * @file Ex_9_15.cpp
 * @author Matthew J Randazzo (mtrdazzo@domain.com)
 * @brief Tic Tac Toe Implementation
 * @version 0.1
 * @date 2020-03-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Ex_9_15.h>
#include <algorithm>

/**
 * @brief Construct a new TicTacToe::TicTacToe object
 * 
 */
TicTacToe::TicTacToe() {
    _printGreeting();
    _getNumberOfPlayers();
    _getPlayerOrder();
}

/**
 * @brief Determine if the space selected is valid.
 * 
 * @param selection Index (1-9) of a space on a board
 * @return {boolean} True if valid space, otherwise false
 */
bool TicTacToe::_isValidSelection(uint8_t selection) const {
    uint8_t row;
    uint8_t col;

    if (selection % BOARD_SIZE) {
        row = selection / BOARD_SIZE;
        col = selection % BOARD_SIZE - 1;
    }
    else {
        row = selection / BOARD_SIZE - 1;
        col = BOARD_SIZE - 1;
    }

    return (selection <= BOARD_SIZE * BOARD_SIZE && !m_pBoard[row][col]);
}

/**
 * @brief  Make the selection for the current player.
 * 
 * @param selection Index of a space on the board.
 */
void TicTacToe::_makeSelection(uint8_t selection) {

    uint8_t row;
    uint8_t col;

    if (selection % BOARD_SIZE) {
        row = selection / BOARD_SIZE;
        col = selection % BOARD_SIZE - 1;
    }
    else {
        row = selection / BOARD_SIZE - 1;
        col = BOARD_SIZE - 1;
    }
    m_pBoard[row][col] = m_uiCurrentPlayer;
}

/**
 * @brief  Make a selection for the computer player.
 * 
 * @return int Best index for the current board.
 */
int TicTacToe::_makeSelectionComputer(void) {

    int bestVal{-1000};
    size_t bestIndex{0};

    for (size_t row{0}; row < BOARD_SIZE; row++) {
        for (size_t col{0}; col < BOARD_SIZE; col++) {
            if (m_pBoard[row][col] == m_ePlayer::NO_PLAYER) {
                m_pBoard[row][col] = m_uiCurrentPlayer;

                int moveVal = minimax(0, true);

                m_pBoard[row][col] = m_ePlayer::NO_PLAYER;

                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    bestIndex = (row * BOARD_SIZE) + col + 1;
                }
            }
        }
    }
    return bestIndex;
}

/**
 * @brief Recursive minimax algorithm to find the best score for each space.
 * 
 * @param depth Depth of recursion.
 * @param isMax Maximum score of the current move.
 * @return int  Score of the current move.
 */
int TicTacToe::minimax(int depth, bool isMax) {

    int score = _findWinner();

    if (score == m_uiCurrentPlayer)
        return 10;
    else if (score == ((m_uiCurrentPlayer == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_2 : m_ePlayer::PLAYER_1))
        return -10;
    else if (score == m_ePlayer::TIE_GAME)
        return 0;

    if (isMax) {
        int best = -1000;

        for (size_t row{0}; row < BOARD_SIZE; row++)
            for (size_t col{0}; col < BOARD_SIZE; col++) {
                if (m_pBoard[row][col] == m_ePlayer::NO_PLAYER) {
                    m_pBoard[row][col] = m_uiCurrentPlayer;
                    best = std::max(best, minimax(depth+1, !isMax));
                    m_pBoard[row][col] = m_ePlayer::NO_PLAYER;
            }
        }
        return best;
    }
    else {
        int best = 1000;

        for (size_t row{0}; row < BOARD_SIZE; row++)
            for (size_t col{0}; col < BOARD_SIZE; col++) {
                if (m_pBoard[row][col] == m_ePlayer::NO_PLAYER) {
                    m_pBoard[row][col] = m_uiCurrentPlayer;
                    best = std::max(best, minimax(depth+1, !isMax));
                    m_pBoard[row][col] = m_ePlayer::NO_PLAYER;
            }
        }
        return best;
    }
}

/**
 * @brief Start the TicTacToe game.
 * 
 */
void TicTacToe::start(void) {

    int game_status;
    int selection;
    bool validSelection;

    do {

        validSelection = false;
        _printBoard();

        if (m_bIsComputerTurn) {
            selection = _makeSelectionComputer();
            validSelection = true;
            continue;
        }
        else {
            while (!validSelection) {
                std::cout << "Player " << static_cast<int>(m_uiCurrentPlayer) << " pick a space! ";
                std::cin >> selection;
                std::cin.clear();
                std::cout << selection << std::endl;
                if (!(validSelection = _isValidSelection(selection) ))
                    std::cout << selection << " is not a valid selection, pick again" << std::endl;
                exit(1);
            }
        }

        _makeSelection(selection);

        m_uiCurrentPlayer = (m_uiCurrentPlayer == m_ePlayer::PLAYER_1) ? 
                            m_ePlayer::PLAYER_2 : m_ePlayer::PLAYER_1;

        if (m_uiNumPlayers == m_ePlayer::PLAYER_1)
            m_bIsComputerTurn = m_bIsComputerTurn ? false : true;         

    } while ((game_status = _findWinner()) == m_ePlayer::NO_PLAYER);

    _printBoard();

    switch (game_status) {
        case m_ePlayer::PLAYER_1:
        case m_ePlayer::PLAYER_2:
            std::cout << "\n**************" << std::endl;
            if (!m_bIsComputerTurn)
                std::cout << "Computer WINS!" << std::endl;
            else
                std::cout << "Player " << game_status << " WINS!" << std::endl;
            std::cout << "**************\n" << std::endl;
            break;
        case m_ePlayer::TIE_GAME:
            std::cout << "Tie Game!" << std::endl;
            break;
        default: /* Should not enter */
            break;
    }
}

/**
 * @brief Print the current values of the board.
 * 
 */
void TicTacToe::_printBoard(void) const {

    char spaceChar;

    std::cout << '\n';
    for (uint8_t row{BOARD_SIZE}; row > 0; --row) {
        for (uint8_t col{0}; col < BOARD_SIZE; ++col) {
            std::cout << ((col == 0) ? " " : "");

            switch (m_pBoard[row-1][col]) {
                case m_ePlayer::NO_PLAYER:
                    spaceChar = ' ';
                    break;
                case m_ePlayer::PLAYER_1:
                    spaceChar = 'X';
                    break;
                case m_ePlayer::PLAYER_2:
                    spaceChar = 'O';
                    break;
                default:
                    break;
            }
            std::cout << spaceChar;
            std::cout << ((col < BOARD_SIZE - 1) ? " | " : "");
        }
        std::cout << std::endl;
        if (row > 1)
          std::cout << "-----------" << std::endl;
    }

    std::cout << '\n';
}

/**
 * @brief Determine if there is a winner of the current board.
 * 
 * @return int Enumeration value of the winning player, tie, or no player.
 */
int TicTacToe::_findWinner(void) const {
   
    /* Row winner */
    for (size_t row{0}; row < BOARD_SIZE; row++) 
        if (m_pBoard[row][0] && (m_pBoard[row][0] == m_pBoard[row][1]) && (m_pBoard[row][1] == m_pBoard[row][2]))
            return (m_pBoard[row][0] == PLAYER_1) ? PLAYER_1 : PLAYER_2;

    /* Column Winner */
    for (size_t col{0}; col < BOARD_SIZE; col++)
        if (m_pBoard[0][col] && (m_pBoard[0][col] == m_pBoard[1][col]) && (m_pBoard[1][col] == m_pBoard[2][col]))
            return (m_pBoard[0][col] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    /* Diagonal Winners */
    if (m_pBoard[0][0] && (m_pBoard[0][0] == m_pBoard[1][1]) && (m_pBoard[1][1] == m_pBoard[2][2]))
        return (m_pBoard[0][0] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    if (m_pBoard[2][0] && (m_pBoard[2][0] == m_pBoard[1][1]) && (m_pBoard[1][1] == m_pBoard[0][2]))
        return (m_pBoard[2][0] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    return (_movesLeft()) ? m_ePlayer::NO_PLAYER : m_ePlayer::TIE_GAME;
}

/**
 * @brief Determine if there is a free space on the TicTacToe board.
 * 
 */
bool TicTacToe::_movesLeft(void) const {
    for (size_t row{0}; row < BOARD_SIZE; row++)
        for (size_t col{0}; col < BOARD_SIZE; col++)
            if (m_pBoard[row][col] == m_ePlayer::NO_PLAYER)
                return true;
    return false;
}

/**
 * @brief Print greeting before the game has started.
 * 
 */
void TicTacToe::_printGreeting(void) const {
    std::cout << "Welcome!" << std::endl;
    std::cout << "Let's play a game of Tic Tac Toe!" << std::endl;
}

/**
 * @brief Get the order of the players in the TicTacToe game.
 * 
 */
void TicTacToe::_getPlayerOrder(void) {

    if (m_uiNumPlayers == m_ePlayer::PLAYER_2)
        return;

    char choice{'?'};

    while (choice != 'y' && choice != 'n') {
        std::cout << "Do you want to move first (y/n)? ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'n') {
            std::cout << "\nInvalid choice: " << choice << std::endl;
            std::cout << "Please enter a valid choice (y/n)" << std::endl;
        }
    }

    m_bIsComputerTurn = (choice == 'n');
    m_uiCurrentPlayer = (choice == 'y') ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2; 
}

/**
 * @brief Get the number of human players in the TicTacToe game.
 * 
 */
void TicTacToe::_getNumberOfPlayers(void) {

    while (m_uiNumPlayers < m_ePlayer::PLAYER_1 || m_uiNumPlayers > m_ePlayer::PLAYER_2) {
        std::cout << "How many players? (1 or 2) ";
        std::cin >> m_uiNumPlayers;

        m_uiNumPlayers -= '0';

        if (m_uiNumPlayers < m_ePlayer::PLAYER_1 || m_uiNumPlayers >  m_ePlayer::PLAYER_2) {
            std::cout << "Invalid number of players: " << static_cast<int>(m_uiNumPlayers) << std::endl;
            std::cout << "Please enter a valid number of players (1 or 2)" << std::endl;
        }
    }
}
