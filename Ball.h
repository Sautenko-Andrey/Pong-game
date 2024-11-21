#pragma once
#include <SFML/Graphics.hpp>



class Ball {

public:

    Ball(float start_x, float start_y);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void reboundBottom();

    void update(sf::Time dt);


private:

    sf::Vector2f m_position;   // position of the ball

    sf::RectangleShape m_shape;   // the ball

    float m_speed = 300.0f;     // speed of the ball (pixels/second)

    float m_direction_x = 0.2f;

    float m_direction_y = 0.2f;

};