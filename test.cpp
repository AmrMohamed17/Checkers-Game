#include <SFML/Graphics.hpp>
#include <iostream> 
using namespace std;
using namespace sf; 

int main()
{
    RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Texture menu;
    menu.loadFromFile("menu.jpg");
    Sprite MENU;
    MENU.setTexture(menu);
    MENU.setScale(1.2, 1);
    int counter = 0;




    while (window.isOpen())
    {

       


        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mouse = Mouse::getPosition(window);
            if (mouse.x < 700 && mouse.x > 500 && mouse.y < 700 && mouse.y > 500)
            {
                window.close();

            }
            else if(mouse.x < 700 && mouse.x > 500 && mouse.y < 100 && mouse.y > 300)
            {
                counter = 1;

            }



        }
       
        
        window.clear();
        if (counter == 0)
        {
            window.draw(MENU);
        }
        else if (counter == 1)
        {
            window.draw(shape);
        }
        
        window.display();
    }

    return 0;
}