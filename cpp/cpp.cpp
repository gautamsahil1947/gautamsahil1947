#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Moving Shape");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // drawing the shape
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Green);


    float circleMoveSpeed = 1.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        circle.setPosition(circle.getPosition().x + circleMoveSpeed, circle.getPosition().y + circleMoveSpeed);

        window.clear();
        window.draw(circle);
        window.display();

    }
    return 0;
}
