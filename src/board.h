#include <SFML/Graphics.hpp>
# include "snake.h"
#include <vector>


#define UP  3
#define DOWN 2
#define LEFT 1
#define RIGHT 4
#define IDLE 0

enum class Status : std::uint8_t { MOVE, EAT, DIE };


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
    int draw(sf::RenderWindow& window, bool& gameOver);
    void setDir(int dir);
    Status nextStep();
    void setHead(int head_x, int head_y);
private:
    int height;
    int width;
    vector<pair<int, int>> food;
    int score;
    int foodCount;
    int dir;
    Snake snake;
    int h_x;
    int h_y;

};