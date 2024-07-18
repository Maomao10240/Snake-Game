#include "snake.h"
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>
#include "Exception/GameOverException.h"


Snake::Snake(){
    //start at 0, 0 position
    snake.push_back({0,0});
    body.insert("0&0");
}
Snake::~Snake(){

}
//return -1 means fail; return 1 means success;
int Snake::move(sf::RenderWindow& window, int dir){ 
    
    //1.get tail position  2.remove tail; remove tail first! remove tail from the body
    int tail_x = snake.back().first;
    int tail_y = snake.back().second;
    //element for the body
    string tail = to_string(tail_x) + "&" + to_string(tail_y);
   // cout<<"string value : "<<tail<<endl;
 
    body.erase(tail);
    //3. get current head position
    int head_x = snake.front().first;
    int head_y = snake.front().second;
    snake.pop_back(); //only one element, the front will be zero
    //4. move to the direction: check boundaries; check whether meet snake
    //4.1 get the new head postion
    switch (dir)
    {
    case 4:
        head_x += 1;
        break;
    case 1:
        head_x -= 1;
        break;
    case 2:
        head_y += 1;
        break;
    case 3:
        head_y -= 1;
        break;            
    default:
        break;
    }

    //4.2 get window size, check whether hit window
    sf::Vector2u windowSize = window.getSize();
    int height = windowSize.y;
    int width = windowSize.x;
    if(head_x < 0 ||head_x > width||head_y < 0 ||head_y > height){
        throw GameOverException("Game Over: Snake hit the boundary!");
    }
    //4.3 check hit snake
    string newHead = to_string(head_x) +"&"+ to_string(head_y);
    if(body.count(newHead)){
        throw GameOverException("Game Over: Snake hit the body!");
    }
    //cout<< "new head: " <<head_x<<" new y: "<< head_y<< endl;
    snake.push_front({head_x, head_y});
    body.insert(newHead);
   
    return 1;
}
void Snake::eat(int dir){
    //1. get current head position
    int head_x = snake.front().first;
    int head_y = snake.front().second;

    //2. move to the direction: check boundaries; check whether meet snake
    switch (dir)
    {
    case 4:
        head_x += 1;
        break;
    case 1:
        head_x -= 1;
        break;
    case 2:
        head_y += 1;
        break;
    case 3:
        head_y -= 1;
        break;            
    default:
        break;
    }

    //3 eat will not hit the window and the body, as the food should exist within the window and not overlap with the snake
    
    string newHead = to_string(head_x) +"&"+ to_string(head_y);
  

    snake.push_front({head_x, head_y});
    body.insert(newHead);
   
}