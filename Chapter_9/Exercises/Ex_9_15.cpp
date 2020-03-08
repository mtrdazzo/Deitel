#include <Ex_9_15.h>

TicTacToe::TicTacToe() {
    _printGreeting();
    _getNumberOfPlayers();
    _getPlayerOrder();
}

TicTacToe::~TicTacToe() {}

/**
 * @brief Determine if the space selected is a valid selection
 * @param selection Index (1-9) of a space on the board
 * @return true if selection is valid, otherwise false
 */
bool TicTacToe::_isValidSelection(int selection) const {
    uint8_t row;
    uint8_t col;

    row = (selection / 3) ? (selection / 3 - 1) : 0;
    col = selection % 3;

    return (selection >= 0 && selection <= 9 && !board[row][col]);
}

/**
 * @brief Start the game
 */
void TicTacToe::start(void) {

    int game_status;
    int selection;
    bool validSelection;

    do {

        validSelection = false;

        do {

            _printBoard();
            std::cout << "Player " << currentPlayer << " pick a space! ";
            std::cin >> selection;

            if (!(validSelection = _isValidSelection(selection) ))
                std::cout << selection << " is not a valid selection, pick again" << std::endl;

        } while (!validSelection);

        currentPlayer = (currentPlayer = m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_2 : m_ePlayer::PLAYER_1;
    
    } while ((game_status = _findWinner() == m_ePlayer::NO_PLAYER));

    switch (game_status) {

        case m_ePlayer::PLAYER_1:
        case m_ePlayer::PLAYER_2:
            std::cout << "Player " << game_status << " WINS!" << std::endl;
            break;
        case m_ePlayer::TIE_GAME:
            std::cout << "Tie Game!" << std::endl;
            break;
        default: /* Should not enter */
            break;
    }

}

/**
 * @brief Print the board
 */
void TicTacToe::_printBoard(void) const {

    for (auto & row: board) {
        for (const int space: row)
            std::cout << space << "|";
        std::cout << std::endl;
    }
}

/**
 * @brief Determine is there is a winner of the game
 * @return true if the game has been won, otherwise false
 */
int TicTacToe::_findWinner(void) const {
   
    /* Row winner */
    for (size_t row{0}; row < BOARD_SIZE; row++) 
        if (board[row][0] && (board[row][0] == (board[row][1] == board[row][2])))
            return (board[row][0] == PLAYER_1) ? PLAYER_1 : PLAYER_2;

    /* Column Winner */
    for (size_t col{0}; col < BOARD_SIZE; col++)
        if (board[0][col] && (board[0][col] == (board[1][col] == board[2][col])))
            return (board[0][col] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    /* Diagonal Winners */
    if (board[0][0] && (board[0][0] == (board[1][1] == board[2][2])))
        return (board[0][0] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    if (board[2][0] && (board[2][0] == (board[1][1] == board[0][2])))
        return (board[2][0] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    return (_freeSpaces()) ? m_ePlayer::NO_PLAYER : m_ePlayer::TIE_GAME;
}

/**
 * @brief Determine the number of free spaces on the board
 * @return The number of free spaces on the board
 */
int TicTacToe::_freeSpaces(void) const {

    int free_spaces{0};

    for (auto &row : board)
        for (const uint8_t space : row)
            free_spaces += (space) ? 1 : 0;
    
    return free_spaces;
}

/**
 * @brief Print greeting before the game has started
 */
void TicTacToe::_printGreeting(void) const {
    std::cout << "Welcome!" << std::endl;
    std::cout << "Let's play a game of Tic Tac Toe!" << std::endl;
}

/**
 * @brief Get the order of the players
 */
void TicTacToe::_getPlayerOrder(void) {

    if (numPlayers == m_ePlayer::PLAYER_2)
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

    currentPlayer = (choice == 'y') ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2; 
}

/**
 * @brief Get the number of human players
 */
void TicTacToe::_getNumberOfPlayers(void) {

    while (numPlayers < m_ePlayer::PLAYER_1 || numPlayers > m_ePlayer::PLAYER_2) {
        std::cout << "How many players? (1 or 2) ";
        std::cin >> numPlayers;

        if (numPlayers < m_ePlayer::PLAYER_1 || numPlayers >  m_ePlayer::PLAYER_2) {
            std::cout << "Invalid number of players: " << static_cast<int>(numPlayers) << std::endl;
            std::cout << "Please enter a valid number of players (1 or 2)" << std::endl;
        }
    }

}
