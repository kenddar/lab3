#ifndef TRAINING_SFML_GRAPHICS_ELEMENTS_H
#define TRAINING_SFML_GRAPHICS_ELEMENTS_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int WINDOW_SIZE = 600;
const int GRID_SIZE = 3;
const int CELL_SIZE = WINDOW_SIZE / GRID_SIZE;



class Cross {
private:
    sf::RectangleShape line1;
    sf::RectangleShape line2;
public:
    Cross(float size, sf::Color color = sf::Color::Red, float thickness = 5.0f) {
        // Отцентрируем крестик внутри клетки
        line1.setSize(sf::Vector2f(size, thickness));
        line1.setFillColor(color);
        line1.setOrigin(size / 2, thickness / 2);
        line1.rotate(45);

        line2.setSize(sf::Vector2f(size, thickness));
        line2.setFillColor(color);
        line2.setOrigin(size / 2, thickness / 2);
        line2.rotate(-45);
    }

    void draw(sf::RenderWindow& window, float x, float y) {
        line1.setPosition(x, y);
        line2.setPosition(x, y);
        window.draw(line1);
        window.draw(line2);
    }
};

class Circle {
private:
    sf::CircleShape circleShape;
public:
    Circle(float radius, sf::Color color = sf::Color::Blue, float thickness = 5.0f) {
        circleShape.setRadius(radius);
        circleShape.setFillColor(sf::Color::Transparent);
        circleShape.setOutlineColor(color);
        circleShape.setOutlineThickness(thickness);
        circleShape.setOrigin(radius, radius);
    }

    void draw(sf::RenderWindow& window, float x, float y) {
        circleShape.setPosition(x, y);
        window.draw(circleShape);
    }
};

#endif //TRAINING_SFML_GRAPHICS_ELEMENTS_H
