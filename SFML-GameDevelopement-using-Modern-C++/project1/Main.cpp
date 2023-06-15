#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

class Shapes {
    sf::Shape* ptr;
    sf::Text* m_text;
    std::string identifier;
    float m_vx, m_vy;
    int m_lenx, m_leny;
    int m_winx, m_winy;
public:

    // constructor for the rectangles
    Shapes(std::string name, int x, int y, float vx, float vy, int R, int G, int B, int lengthx, int lengthy, int winx, int winy) 
    : identifier("rectangle"), m_vx(vx), m_vy(vy), m_lenx(lengthx), m_leny(lengthy), m_winx(winx), m_winy(winy) {
        ptr = new sf::RectangleShape(sf::Vector2f(lengthx, lengthy));
        ptr -> setPosition(sf::Vector2f(x, y));
        ptr -> setFillColor(sf::Color(R, G, B));
    }

    // constructor for the circle
    Shapes(std::string name, int x, int y, float vx, float vy, int R, int G, int B, int radius, int winx, int winy) 
    : identifier("circle"), m_vx(vx), m_vy(vy), m_winx(winx), m_winy(winy), m_lenx(radius * 2), m_leny(radius * 2)
    {
        ptr = new sf::CircleShape(radius);
        ptr -> setPosition(sf::Vector2f(x, y));
        ptr -> setFillColor(sf::Color(R, G, B));
    }
    // the  constructors above will overload each other

    void checkForWalls() {
        if (ptr -> getPosition().x + m_lenx >= m_winx || ptr -> getPosition().x <= 0) {
            m_vx *= -1;
        }


        if (ptr -> getPosition().y + m_leny >= m_winy || ptr -> getPosition().y <= 0) {
            m_vy *= -1;
        }
    }

    void updateLocation () {
        (*ptr).setPosition((*ptr).getPosition().x + m_vx, (*ptr).getPosition().y + m_vy);
    }


    sf::Shape* getShape() {
        return ptr;
    }


    sf::Text* getName() {
        return m_text;
    }


};


int main() {

    std::ifstream fin("/home/sahil/gautamsahil1947/SFML-GameDevelopement-using-Modern-C++/project1/data.txt");
    int winx, winy;
    sf::Font font;
    int fontSize, fontR, fontG, fontB;
    std::string fileName;
    std::string tmp;

    std::vector<Shapes> arr;

    while (fin >> tmp) {
        if (tmp == "Window") 
        {
                fin >> winx >> winy;
        } 
        else if (tmp == "Font") 
        {
            fin >> fileName >> fontSize >> fontR >> fontG >> fontB;
            if (!font.loadFromFile(fileName)) 
            {
                std::cout << "Error font file not found" << std::endl;
            }
        } 
        else if (tmp == "Rectangle") 
        {

            int x, y, R, G, B, len, width;
            float vx, vy;
            std::string name;

            fin >> name >> x >> y >> vx >> vy >> R >> G >> B >> len >> width;
            Shapes rectangle(name, x, y, vx, vy, R, G, B, len, width, winx, winy);
            arr.push_back(rectangle);

        } 
        else if (tmp == "Circle") 
        {
            int x, y, R, G, B, rad;
            float vx, vy;
            std::string name;
            fin >> name >> x >> y >> vx >> vy >> R >> G >> B >> rad;
            Shapes circle(name, x, y, vx, vy, R, G, B, rad, winx, winy);
            arr.push_back(circle);
        }
    }


    sf::RenderWindow window(sf::VideoMode(winx, winy), "Game Window");


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }




        window.clear(sf::Color::Black);
        for (auto& x : arr) {
            x.checkForWalls();
            x.updateLocation();
            window.draw(*(x.getShape()));

        }
        window.display();



    }
}


