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
void Board::placeFood(){
    int x = rand()%(width/CELLSIZE);
    int y = rand()%(height/CELLSIZE);
    food.push_back({x,y});
}
int Board::draw(sf::RenderWindow& window, Snake& snake, int dir, bool& gameOver){
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
    if(dir == 0){
        return 0;
    }
    //3. move snake
   //3. get current head position
    int head_x = curSnake.front().first;
    int head_y = curSnake.front().second;

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
       

    if (head_x < 0 ||head_x * CELLSIZE> width||head_y < 0 ||head_y *CELLSIZE > height) {
        gameOver = true;
        throw GameOverException("Game Over: Snake hit the boundary!");
    }
    if (head_x == food_x && head_y == food_y){
        snake.eat(dir);
        food.pop_back();
        placeFood();
        return 1;
    } else {

        if(snake.move(window, dir)== -1){
            gameOver = true;
            throw GameOverException("Game Over: Snake hit the boundary!");
        }else{
            return 0;
        }
       

    }
    //dir = 0;
    

    //3.1 just move snake
    //3.2 food is there, snake eats food; ---> add new food










   // sf::Vector2f position = rectangle.getPosition();


    //rectangle.setFillColor(sf::Color::Green);
    //window.clear();
    //window.draw(rectangle);
    //window.display();
}