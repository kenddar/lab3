#ifndef TRAINING_SFML_START_GAME_H
#define TRAINING_SFML_START_GAME_H
#include "Game_Functions.h"


int start_game() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tic Tac Toe");

    sf::RectangleShape gridLines[GRID_SIZE - 1][2];
    for (int i = 0; i < GRID_SIZE - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            gridLines[i][j].setSize(sf::Vector2f(WINDOW_SIZE, 5));
            gridLines[i][j].setFillColor(sf::Color::Black);
            if (j == 0) {
                gridLines[i][j].setPosition(0, (i + 1) * CELL_SIZE - 2.5);
            } else {
                gridLines[i][j].setPosition((i + 1) * CELL_SIZE - 2.5, 0);
                gridLines[i][j].rotate(90);
            }
        }
    }

    Player board[GRID_SIZE][GRID_SIZE] = {{Player::Empty, Player::Empty, Player::Empty},
                                          {Player::Empty, Player::Empty, Player::Empty},
                                          {Player::Empty, Player::Empty, Player::Empty}};

    Player currentPlayer = Player::Cross;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("D:/mephilabs/testsfml/Pictures/fon.jpg")) {
        std::cerr << "Failed to load background texture\n";
        return EXIT_FAILURE;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    Cross cross(CELL_SIZE - 10);
    Circle circle((CELL_SIZE - 30) / 2);
    Circle transparentCircle((CELL_SIZE - 30) / 2, sf::Color(0, 0, 0, 128), 5.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    int x = event.mouseButton.x / CELL_SIZE;
                    int y = event.mouseButton.y / CELL_SIZE;

                    if (x < GRID_SIZE && y < GRID_SIZE && board[y][x] == Player::Empty) {
                        board[y][x] = currentPlayer;

                        if (currentPlayer == Player::Cross) {
                            cross.draw(window, x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
                        } else if (currentPlayer == Player::Circle) {
                            circle.draw(window, x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2);
                        }

                        if (checkWin(board, currentPlayer)) {
                            std::cout << "Player " << (currentPlayer == Player::Cross ? "Cross" : "Toe") << " win!\n";
                            window.close();
                        } else {
                            bool isBoardFull = true;
                            for (int i = 0; i < GRID_SIZE; ++i) {
                                for (int j = 0; j < GRID_SIZE; ++j) {
                                    if (board[i][j] == Player::Empty) {
                                        isBoardFull = false;
                                        break;
                                    }
                                }
                            }

                            if (isBoardFull) {
                                std::cout << "Game Draw!\n";
                                window.close();
                            } else {
                                currentPlayer = (currentPlayer == Player::Cross) ? Player::Circle : Player::Cross;
                            }
                        }
                    }
                }
            }
        }

        window.clear();

        window.draw(backgroundSprite);

        for (int i = 0; i < GRID_SIZE - 1; ++i) {
            for (int j = 0; j < 2; ++j) {
                window.draw(gridLines[i][j]);
            }
        }

        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (board[i][j] == Player::Cross) {
                    cross.draw(window, j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2);
                } else if (board[i][j] == Player::Circle) {
                    circle.draw(window, j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2);
                }
            }
        }

        if (currentPlayer == Player::Circle) {
            ISortedSequence<struct MoveScore> moveQueue;
            sf::Vector2i bestMove = findBestMove(board, moveQueue);
            if (board[bestMove.y][bestMove.x] == Player::Empty) {
                transparentCircle.draw(window, bestMove.x * CELL_SIZE + CELL_SIZE / 2, bestMove.y * CELL_SIZE + CELL_SIZE / 2);
            }
        }

        window.display();
    }
    return 0;
}
#endif //TRAINING_SFML_START_GAME_H
