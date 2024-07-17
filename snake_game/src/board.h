#include <SFML/Graphics.hpp>
# include "snake.h"
#include <vector>

class Board{
    //public: access it outside of the class
public: 
    //construct
    Board();
    //deconstruct
    ~Board();
    void setHeight(int height);
    void setWidth(int width);
    void placeFood();
    void draw(sf::RenderWindow& window, Snake& snake, int dir);
private:
    int height;
    int width;
    vector<pair<int, int>> food;
    int score;
    int foodCount;

};