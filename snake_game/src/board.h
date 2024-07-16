#include <SFML/Graphics.hpp>


class Board{
    //public: access it outside of the class
public: 
    //construct
    Board(int height, int width, int count);
    //deconstruct
    ~Board();
    void setDirction(int dir);
    void draw(sf::RenderWindow& window, sf::RectangleShape& rectangle);
private:
    int height;
    int width;
    int food[10];
    int dir;
    int score;

};