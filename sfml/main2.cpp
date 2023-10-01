#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main(){
    // set up window
    sf::RenderWindow window( sf::VideoMode(400, 400), "SFML Sprites and Textures" );

    // set up sprite
    sf::Texture texture;
    texture.loadFromFile( "./monaLisa.jpeg" );
    sf::Sprite sprite( texture );
    sprite.setScale( 0.25f, 0.25f );
    
    // Load a font, set up text
    sf::Font font;
    font.loadFromFile( "./timesNewRoman.ttf" );
    sf::Text text( "Mona Lisa", font, 48);
    text.move(100.0f, 0.0f);

    float xPos = 0.0f;

    // while window is open
    while( window.isOpen() ){
        sf::Event event;
    
        // event loop
        while( window.pollEvent( event ) ){
            if( event.type == sf::Event::Closed ){
                // close window
                window.close();
                cout << "Window has succesfully been closed";
            }
        }

        xPos += 0.01;
        sprite.setPosition(xPos, 0.0f);

        if(xPos > 100){
            xPos = 0;
        }

        // clear window
        window.clear();
    
        // draw sprites
        window.draw( sprite );

        // draw text
        window.draw( text );

        // display window
        window.display();
    }
    return 0;
}