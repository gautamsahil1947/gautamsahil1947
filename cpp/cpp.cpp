#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(90, 90), "My Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing the window" << std::endl;
                window.close();
            }

            window.clear(sf::Color::Black);
            sf::CircleShape shape(10.0f);
            shape.setFillColor(sf::Color::Green);
            // this is the drawing ground
            window.draw(shape);
            window.display();
        }
    }
}
