#include <iostream>
//using for cout, endl;
using namespace std;
#include "board.h"
#include <SFML/Graphics.hpp>
#include "snake.h"


//g++ -o sfml-app main.cpp -lsfml-graphics -lsfml-window -lsfml-system
//-o sfml-app: specify the output file name;  main.cpp is the name of the source file;   
// -lsfml-graphics -lsfml-window -lsfml-system: links sfml libraries for graphics, windows management, and system components




//sdl2: core libary that provides low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. 
//sdl2_image: loading and saving images in various formats
//sdl2_mixer: handle multiple audio channels for sound effects and music
//sdl2_ttf: render text on the screen
//sdl2_net: provides simple cross-platform networking support. It is used for network communication

int main(){
    cout<< "Snake Game start..." << endl;
    cout<< "Enter the height of the game board:" <<endl;
    int height = 0;
    cin>>height;
    cout<< "Enter the width of the game board:" <<endl;
    int width = 0;
    cin>>width;
    cout<< "Enter the number of the food for snake:" <<endl;
    int count = 0;
    cin>>count;
    //food will be generated randomly 

    Board board(height, width, count);
    Snake snake();


    sf::RenderWindow window(sf::VideoMode(height, width), "Snake Game!");
    // sf::CircleShape shape(100.f);
   // shape.setFillColor(sf::Color::Green);
    sf::RectangleShape rectangle(sf::Vector2f(20, 20));
    rectangle.setPosition(100, 100);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Right) board.setDirction(4);
                else if(event.key.code == sf::Keyboard::Left) board.setDirction(1);
                else if(event.key.code == sf::Keyboard::Up) board.setDirction(2);
                else if(event.key.code == sf::Keyboard::Down) board.setDirction(3);

            }
        }

        window.clear();
        board.draw(window, rectangle);
        // window.draw(shape);
        window.display();
    }

    return 0;


}
