#ifndef TRAINING_SFML_GAME_FUNCTIONS_H
#define TRAINING_SFML_GAME_FUNCTIONS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ISortedSequence.h"
#include "Graphics_elements.h"





struct MoveScore {
    sf::Vector2i move;
    int score;

    bool operator < (const MoveScore& other) const {
        return score < other.score;
    }
};
enum class Player { Cross, Circle, Empty };

sf::Vector2i findBestMove(Player board[GRID_SIZE][GRID_SIZE], ISortedSequence<MoveScore>& moveSequence);
int minimax(Player board[GRID_SIZE][GRID_SIZE], int depth, bool isMaximizing, ISortedSequence<MoveScore>& moveSequence);
int evaluate(Player board[GRID_SIZE][GRID_SIZE]);


bool isBoardFull(const Player board[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (board[i][j] == Player::Empty) {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(const Player board[GRID_SIZE][GRID_SIZE], Player player) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}


sf::Vector2i findBestMove(Player board[GRID_SIZE][GRID_SIZE], ISortedSequence<MoveScore>& moveSequence) {
    int bestVal = INT_MIN;
    sf::Vector2i bestMove = { -1, -1 };

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (board[i][j] == Player::Empty) {
                board[i][j] = Player::Circle;

                int moveVal = minimax(board, 0, false, moveSequence);

                board[i][j] = Player::Empty;

                if (moveVal > bestVal) {
                    bestMove = { j, i };
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

int minimax(Player board[GRID_SIZE][GRID_SIZE], int depth, bool isMaximizing, ISortedSequence<MoveScore>& moveSequence) {
    int score = evaluate(board);

    if (score != -2) {
        return score;
    }

    if (isMaximizing) {
        int best = INT_MIN;

        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Empty) {
                    board[i][j] = Player::Circle;
                    int moveVal = minimax(board, depth + 1, !isMaximizing, moveSequence);
                    board[i][j] = Player::Empty;

                    MoveScore moveScore;
                    moveScore.move = { j, i };
                    moveScore.score = moveVal;
                    moveSequence.Add(moveScore);

                    best = std::max(best, moveVal);
                }
            }
        }

        return best;
    } else {
        int best = INT_MAX;

        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Empty) {
                    board[i][j] = Player::Cross;
                    int moveVal = minimax(board, depth + 1, !isMaximizing, moveSequence);
                    board[i][j] = Player::Empty;

                    MoveScore moveScore;
                    moveScore.move = { j, i };
                    moveScore.score = moveVal;
                    moveSequence.Add(moveScore);

                    best = std::min(best, moveVal);
                }
            }
        }

        return best;
    }
}

int evaluate(Player board[GRID_SIZE][GRID_SIZE]) {
    if (checkWin(board, Player::Cross)) {
        return -1;
    }
    if (checkWin(board, Player::Circle)) {
        return 1;
    }

    bool isFull = isBoardFull(board);


    if (isFull) {
        return 0;
    }

    return -2;
}

#endif //TRAINING_SFML_GAME_FUNCTIONS_H
