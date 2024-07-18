#include <iostream>
//using for cout, endl;
using namespace std;
#include "board.h"
#include <SFML/Graphics.hpp>
#include "Exception/GameOverException.h"
#include "Constant/constant.h"

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
    int height = 400;
   // cin>>height;
    cout<< "Enter the width of the game board:" <<endl;
    int width =400;
   // cin>>width;
    cout<< "Enter the number of the food for snake:" <<endl;
    int count = 0;
    //  cin>>count;
    //food will be generated randomly 

    
    int score = 0;
    int dir = 0;
    Board board;
    board.setHeight(height);
    board.setWidth(width);
    board.placeFood();
    sf::RenderWindow window(sf::VideoMode(height, width), "Snake Game!");
    //sf::RectangleShape rectangle(sf::Vector2f(20, 20));
    //rectangle.setPosition(20, 100);
    Snake snake;
    //Game over window
    sf::Font font;
    if(!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf")){
        cout<<"Error loading font"<<endl;
        return -1;
    }
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(CELLSIZE);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(10, 150);


    bool gameOver = false;
    while (window.isOpen())
    {
       
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Right) dir = 4;
                else if(event.key.code == sf::Keyboard::Left) dir = 1;
                else if(event.key.code == sf::Keyboard::Up) dir = 3;
                else if(event.key.code == sf::Keyboard::Down) dir = 2;
               
            }    
            window.clear();
            window.setTitle("Snake Game!      Sore: " + to_string(score));
           
            // score += board.draw(window, snake, dir, gameOver);
      
            // if(gameOver){
            //     gameOverText.setString("Game Over");
            //     window.draw(gameOverText);
            // }
            try{
                score += board.draw(window, snake, dir, gameOver);
            }catch(GameOverException& e){
                gameOverText.setString(e.what());
                
            }
            
            if(gameOver){
                window.draw(gameOverText);
                window.display();
                sf::sleep(sf::seconds(2));
                window.close();
            }
           
            // window.draw(shape);
            window.display();
            dir = 0;
        }   
    
    }

    return 0;

}
