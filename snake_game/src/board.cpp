# include "board.h"
using namespace std;
#include <iostream>


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
    int x = rand()%(width/20);
    int y = rand()%(height/20);
    food.push_back({x,y});
}
void Board::draw(sf::RenderWindow& window, Snake& snake, int dir){
    //1. place snake
    deque<pair<int, int>> curSnake = snake.snake;
    for(const auto&seg: curSnake){
        sf::RectangleShape rectangle(sf::Vector2f(20, 20));
        rectangle.setPosition(seg.first*20, seg.second*20);
        rectangle.setFillColor(sf::Color::Green);
       // cout<< "new x: " <<seg.first<<" new y: "<< seg.second<< endl;
        window.draw(rectangle);
    }
    //2. place food: time complex: O(1)
    int food_x = food.back().first;
    int food_y = food.back().second;
    sf::RectangleShape foodRect(sf::Vector2f(20, 20));
    foodRect.setPosition(food_x*20, food_y*20);
    foodRect.setFillColor(sf::Color::Red);
    window.draw(foodRect);
    if(dir == 0){
        return;
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
       

    if (head_x < 0 ||head_x * 20> width||head_y < 0 ||head_y *20 > height) {
            cout<< "Game over" << endl;
    }
    if(head_x == food_x && head_y == food_y){
        snake.eat(dir);
        food.pop_back();
        placeFood();
    } else {
        snake.move(window, dir);
       

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