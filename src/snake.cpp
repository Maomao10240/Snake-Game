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
int Snake::move(int h_x, int h_y){ 
    
    //1.get tail position  2.remove tail; remove tail first! remove tail from the body
    int tail_x = snake.back().first;
    int tail_y = snake.back().second;
    string tail = to_string(tail_x) + "&" + to_string(tail_y);
    body.erase(tail);
    snake.pop_back(); //only one element, the front will be zero
    //4. move to the direction: check hit snake
    string newHead = to_string(h_x) +"&"+ to_string(h_y);
    if(body.count(newHead)){
        throw GameOverException("Game Over: Snake hit the body!");
    }
    //cout<< "new head: " <<head_x<<" new y: "<< head_y<< endl;
    snake.push_front({h_x, h_y});
    body.insert(newHead);
   
    return 1;
}
void Snake::eat(int h_x, int h_y){
    string newHead = to_string(h_x) +"&"+ to_string(h_y);
  

    snake.push_front({h_x, h_y});
    body.insert(newHead);
   
}