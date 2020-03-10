#include <Ex_9_15.h>
#include <algorithm>

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

    return (selection <= BOARD_SIZE * BOARD_SIZE && !board[row][col]);
}

/**
 * @brief Make the selection for the current player
 * 
 * @param selection Index of the board chosen
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
    board[row][col] = currentPlayer;
}

/**
 * @brief Make selection for computer 
 */
int TicTacToe::_makeSelectionComputer(void) {

    int bestVal{-1000};
    size_t bestIndex{0};

    for (size_t row{0}; row < BOARD_SIZE; row++) {
        for (size_t col{0}; col < BOARD_SIZE; col++) {
            if (board[row][col] == m_ePlayer::NO_PLAYER) {
                board[row][col] = currentPlayer;

                int moveVal = minimax(0, false);

                board[row][col] = m_ePlayer::NO_PLAYER;

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
 * @brief Minimax algorithm
 * @return Score of chosen space
 */
int TicTacToe::minimax(int depth, bool isMax) {

    int score = _findWinner();

    if (score == currentPlayer)
        return 10;
    else if (score == ((currentPlayer == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_2 : m_ePlayer::PLAYER_1))
        return -10;
    else if (score == m_ePlayer::TIE_GAME)
        return 0;

    if (isMax) {
        int best = -1000;

        for (size_t row{0}; row < BOARD_SIZE; row++)
            for (size_t col{0}; col < BOARD_SIZE; col++) {
                if (board[row][col] == m_ePlayer::NO_PLAYER) {
                    board[row][col] = currentPlayer;
                    best = std::max(best, minimax(depth+1, !isMax));
                    board[row][col] = m_ePlayer::NO_PLAYER;
            }
        }
        return best;
    }
    else {
        int best = 1000;

        for (size_t row{0}; row < BOARD_SIZE; row++)
            for (size_t col{0}; col < BOARD_SIZE; col++) {
                if (board[row][col] == m_ePlayer::NO_PLAYER) {
                    board[row][col] = currentPlayer;
                    best = std::max(best, minimax(depth+1, !isMax));
                    board[row][col] = m_ePlayer::NO_PLAYER;
            }
        }
        return best;
    }
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

            if (isComputerTurn) {
                selection = _makeSelectionComputer();
                validSelection = true;
                continue;
            }

            _printBoard();
            std::cout << "Player " << currentPlayer << " pick a space! ";
            std::cin >> selection;

            if (!(validSelection = _isValidSelection(selection) ))
                std::cout << selection << " is not a valid selection, pick again" << std::endl;
        } while (!validSelection);

        _makeSelection(selection);

        currentPlayer = (currentPlayer == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_2 : m_ePlayer::PLAYER_1;

        if (numPlayers == m_ePlayer::PLAYER_1)
            isComputerTurn = isComputerTurn ? false : true;         

    } while ((game_status = _findWinner()) == m_ePlayer::NO_PLAYER);

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

    for (uint8_t row{BOARD_SIZE}; row > 0; --row) {
        for (uint8_t col{0}; col < BOARD_SIZE; ++col)
            std::cout << (int)board[row-1][col] << "|";
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
        if (board[row][0] && (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]))
            return (board[row][0] == PLAYER_1) ? PLAYER_1 : PLAYER_2;

    /* Column Winner */
    for (size_t col{0}; col < BOARD_SIZE; col++)
        if (board[0][col] && (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]))
            return (board[0][col] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    /* Diagonal Winners */
    if (board[0][0] && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
        return (board[0][0] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    if (board[2][0] && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
        return (board[2][0] == m_ePlayer::PLAYER_1) ? m_ePlayer::PLAYER_1 : m_ePlayer::PLAYER_2;
    
    return (_movesLeft()) ? m_ePlayer::NO_PLAYER : m_ePlayer::TIE_GAME;
}

/**
 * @brief Determine the number of free spaces on the board
 */
bool TicTacToe::_movesLeft(void) const {
    for (size_t row{0}; row < BOARD_SIZE; row++)
        for (size_t col{0}; col < BOARD_SIZE; col++)
            if (board[row][col] == m_ePlayer::NO_PLAYER)
                return true;
    return false;
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

    isComputerTurn = (choice == 'n');
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
