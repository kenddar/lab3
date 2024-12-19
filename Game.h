#ifndef TESTSFML_GAME_H
#define TESTSFML_GAME_H


#ifndef GAME_H
#define GAME_H

#include "Game_Functions.h"

class Game {
private:
    Player board[GRID_SIZE][GRID_SIZE];
    Player currentPlayer;

public:
    Game() {
        resetBoard();
        currentPlayer = Player::Cross;
    }

    void resetBoard() {
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                board[i][j] = Player::Empty;
            }
        }
    }

    bool isBoardFull() const {
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Empty) {
                    return false;
                }
            }
        }
        return true;
    }

    bool makeMove(int x, int y) {
        if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || board[y][x] != Player::Empty) {
            return false;
        }

        board[y][x] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << (currentPlayer == Player::Cross ? "Cross" : "Circle") << " wins!\n";
            return true;
        }

        if (isBoardFull()) {
            std::cout << "Game Draw!\n";
            return true;
        }


        currentPlayer = (currentPlayer == Player::Cross) ? Player::Circle : Player::Cross;
        return false;
    }

    void drawBoard(sf::RenderWindow& window, Cross& cross, Circle& circle) const {
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Cross) {
                    cross.draw(window, j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2);
                } else if (board[i][j] == Player::Circle) {
                    circle.draw(window, j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2);
                }
            }
        }
    }

    Player getCurrentPlayer() const {
        return currentPlayer;
    }

    Player (&getBoard())[GRID_SIZE][GRID_SIZE] {
        return board;
    }
};

#endif // GAME_H
#endif //TESTSFML_GAME_H
