# include "board.h"
using namespace std;
#include <iostream>
#include "Exception/GameOverException.h"
#include "Constant/constant.h"


Board::Board(){
}
Board::~Board(){

}
void Board::setHeight(int height){
    this->height = height;
}
void Board::setWidth(int width){
    this->width = width;
}    
void Board::setHead(int head_x, int head_y){
    this->h_x = head_x;
    this->h_y = head_y;
}
void Board::setDir(int dir = IDLE){
    this->dir = dir;
}
void Board::placeFood(){
    int x = rand()%(width/CELLSIZE);
    int y = rand()%(height/CELLSIZE);
    food.push_back({x,y});
}
//get next step of the direction. 
//If it is food, eat the food.  If it is boundary, Game over. Otherwise move
Status Board::nextStep(){
   
    //1.get the head of the snake
    deque<pair<int, int>> curSnake = snake.snake;
    int head_x = curSnake.front().first;
    int head_y = curSnake.front().second;
    //2. move to next step
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
    //3. check whether out of boundary
    if (head_x < 0 ||head_x * CELLSIZE> width||head_y < 0 ||head_y *CELLSIZE > height) {
       // throw GameOverException("Game Over: Snake hit the boundary!");
       //return out of boundary status
       return Status::DIE;
    }
    //4. check for food
    //4.1 get current food
    int food_x = food.back().first;
    int food_y = food.back().second;
    //4.2 check for food
    if (head_x == food_x && head_y == food_y){
       //return eat status
        return Status::EAT;
    } else {
        //return move status
         return Status::MOVE;
    }
}


int Board::draw(sf::RenderWindow& window, bool& gameOver){
    //1. place snake
    deque<pair<int, int>> curSnake = snake.snake;
    for(const auto&seg: curSnake){
        sf::RectangleShape rectangle(sf::Vector2f(CELLSIZE, CELLSIZE));
        rectangle.setPosition(seg.first*CELLSIZE, seg.second*CELLSIZE);
        rectangle.setFillColor(sf::Color::Green);
       // cout<< "new x: " <<seg.first<<" new y: "<< seg.second<< endl;
        window.draw(rectangle);
    }
    //2. place food: time complex: O(1)
    int food_x = food.back().first;
    int food_y = food.back().second;
    sf::RectangleShape foodRect(sf::Vector2f(CELLSIZE, CELLSIZE));
    foodRect.setPosition(food_x*CELLSIZE, food_y*CELLSIZE);
    foodRect.setFillColor(sf::Color::Red);
    window.draw(foodRect);
    //3. no move at all, stay still
    // if(dir == IDLE){
    //     return 0;
    // }
    cout<< "new x:  new y: "<< endl;
    //4. move to next step
    switch(nextStep()){
        case Status::DIE:
            throw GameOverException("Game Over: Snake hit the boundary!");
        case Status::EAT:
            snake.eat(h_x, h_y);
            food.pop_back();
            placeFood();
            return 1;
        case Status::MOVE:
           cout<< "move"<< endl;
            snake.move(h_x, h_y);
            return 0;
    }
}