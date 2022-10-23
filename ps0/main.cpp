/*
* Name: Doulos Htet
*
* Course Name: Computing IV
*
* Assignment #: PS0
*
* Instructor: Dr. Yelena Rykalova 
*
* Due Date: 1/24/2022
*
* Problem: Learning to compile the cpp program was head-scratching. I was trying with visual studio first
* and later found out the easy way to compile in a specific directory with terminal
*
* Bugs: code works fine
*
*/

#include <SFML/Graphics.hpp>

//main start
int main()
{
    // display window 
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML Window");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    // display sprite
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(100, 230));
    
     // display text 
    sf::Font font;
    if (!font.loadFromFile("JustBubble.ttf"))
        return EXIT_FAILURE;
    sf::Text text("cute image with heart", font, 30);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(420, 150);

    // Loop to display windows 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();      
        }
        
        
    // codes to move the sprite with arrow keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    { 
            sprite.move(sf::Vector2f(0, -0.5));
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    { 
            sprite.move(sf::Vector2f(0, 0.5));
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    { 
            sprite.move(sf::Vector2f(0.5, 0));
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    { 
            sprite.move(sf::Vector2f(-0.5, 0));
    }

	// clear, draw, and display the window 
        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.draw(text);
        window.display();
        
    }

    return 0;
}
