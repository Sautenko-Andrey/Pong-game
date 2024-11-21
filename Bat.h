#pragma once
#include <SFML/Graphics.hpp>



class Bat{

public:

    Bat(float start_x, float start_y);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void update(sf::Time dt);


private:

    sf::Vector2f m_position;     // position of the bat on the screen

    sf::RectangleShape m_shape;

    float m_speed = 1000.0f;   // speed (pixels per second)

    bool m_moving_right = false;

    bool m_moving_left = false;

};