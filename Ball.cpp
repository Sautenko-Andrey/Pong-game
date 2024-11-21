#include "Ball.h"


Ball::Ball(float start_x, float start_y) : m_position(start_x, start_y)
{
    m_shape.setSize(sf::Vector2f(10, 10));   // make the ball size 10 x 10
    m_shape.setPosition(m_position);         // assign ball's start position
}



sf::FloatRect Ball::getPosition(){

    return m_shape.getGlobalBounds();

}



sf::RectangleShape Ball::getShape(){

    return m_shape;

}



float Ball::getXVelocity(){

    return m_direction_x;

}



void Ball::reboundSides(){

    m_direction_x = -m_direction_x;

}



void Ball::reboundBatOrTop(){

    m_direction_y = -m_direction_y;

}



void Ball::reboundBottom(){

    m_position.y = 0;
    m_position.x = 500;
    m_direction_y = -m_direction_y;

}



void Ball::update(sf::Time dt){

    // Update the ball's position
    m_position.y += m_direction_y * m_speed * dt.asSeconds();
    m_position.x += m_direction_x * m_speed * dt.asSeconds();

    // Move the ball
    m_shape.setPosition(m_position);

}