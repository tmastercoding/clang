#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

int main(){
    bool wasMouseReleased = false;

    // initial setup
    // setting window size
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    // adding any shapes
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Blue);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(300, 300));
    triangle.setPoint(1, sf::Vector2f(400, 400));
    triangle.setPoint(2, sf::Vector2f(200, 400));
    triangle.setFillColor(sf::Color::Red);


    sf::RectangleShape rectangle;
    rectangle.setPosition(sf::Vector2f(250.0, 40.0));
    rectangle.setSize(sf::Vector2f(150, 150));
    rectangle.setFillColor(sf::Color::Green);

    // sf::Shape shapes[3] = {circle, triangle, rectangle};

    // application loop
    while (window.isOpen()){    
        // event object
        sf::Event event;

        // while event is true
        while (window.pollEvent(event)){   
            // if event is closing tab
            if (event.type == sf::Event::Closed){

                // close the window
                window.close();

                // print
                cout << "Window succesfully closed!\n";
            }


            // if(event.type == sf::Event::KeyReleased){
            //     if(event.key.code == sf::Keyboard::W){
            //         cout << "W key was pressed\n";
            //     } else {
            //         cout << "Key was pressed\n";
            //     }
            // }
            
            // if event is mouseButtonPressed
            if(event.type == sf::Event::MouseButtonPressed){
                cout << "Mouse was pressed down" << endl;
            }

            // if event is mouseButtonReleased
            if(event.type == sf::Event::MouseButtonReleased){
                wasMouseReleased = true;
            }
        }
        // outside of event loop
        // check if left button was pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && wasMouseReleased){
            cout << "Left button pressed\n";
            wasMouseReleased = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            cout << "The A key was pressed\n";
        }

        // erase everything on the window
        window.clear();
        // draw shape again
        // for(int idx = 0; idx < 3; idx++){
        //     window.draw(shapes[idx]);
        // }
        window.draw(circle);
        window.draw(triangle);
        window.draw(rectangle);
        // display the new changes
        window.display();
    }

    return 0;
}