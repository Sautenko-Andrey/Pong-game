#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

enum class Coords {
    ScreenWidth = 1366,
    ScreenHeight = 768
};


int main(){

    // Create a video mode object
    sf::VideoMode video_mode = sf::VideoMode::getDesktopMode();

    // Create and open a window for the game
    sf::RenderWindow window(video_mode, "Pong", sf::Style::Fullscreen);

    int score = 0;

    int lives = 3;

    // Create a bat at the bottom center of the screen
    // using our custom class Bat
    Bat bat(
        static_cast<int>(Coords::ScreenWidth) / 2,
        static_cast<int>(Coords::ScreenHeight) - 20
    );

    // Create a ball
    Ball ball(
        static_cast<int>(Coords::ScreenWidth) / 2,
        0
    );

    // Create a Text object called HUD
    sf::Text hud;

    // A cool retro-style font
    sf::Font font;
    font.loadFromFile("fonts/DS-DIGIT.TTF");

    // Set the font to our retro-style
    hud.setFont(font);

    // Make it nice and big
    hud.setCharacterSize(75);

    // Choose a color
    hud.setFillColor(sf::Color::White);

    hud.setPosition(20, 20);

    // Here is our clock for timimg everything
    sf::Clock clock;

    
    // Game loop
    while(window.isOpen()){
        
        //Handle the player input-------------------------------------------
        /*********************************************************************
        *********************************************************************
        *********************************************************************
        */
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                // Quit the game when the window is closed
                window.close();
            }
        }

        // Handle the player quitting
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }

        // Handle the pressing and releasing of the arrow keys
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            bat.moveLeft();
        }
        else{
            bat.stopLeft();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            bat.moveRight();
        }
        else{
            bat.stopRight();
        }

        //------------------------------------------------------------------

        /*
        Update the bat, the ball and the HUD
        *********************************************************************
        *********************************************************************
        *********************************************************************
        */

        // Update the delta time
        sf::Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // Update the HUD text
        std::stringstream ss;
        ss << "Score:" << score << " Lives:" << lives;
        hud.setString(ss.str());

        /*
        Draw the bat, the ball and the HUD
        *****************************
        *****************************
        *****************************
        */

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();

    }

    return 0;
}