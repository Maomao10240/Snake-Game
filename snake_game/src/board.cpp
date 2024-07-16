# include "board.h"
# include "snake.h"


Board::Board(int height, int width, int count){

}
Board::~Board(){

}
//direction of moving 
void Board::setDirction(int dir){
    this->dir = dir;
}
    

void Board::draw(sf::RenderWindow& window, sf::RectangleShape& rectangle){
    Snake snake;
    sf::Vector2f position = rectangle.getPosition();

    if(this->dir == 4){
        rectangle.setPosition(20+position.x, position.y);
    }else if(this->dir == 1){
        rectangle.setPosition(position.x-20, position.y);
    }else if(this->dir == 2){
        rectangle.setPosition(position.x, position.y+20);
    }else if(this->dir == 3){
        rectangle.setPosition(position.x, position.y-20);
    }
    dir = 0;
    rectangle.setFillColor(sf::Color::Green);
    //window.clear();
    window.draw(rectangle);
    //window.display();
}