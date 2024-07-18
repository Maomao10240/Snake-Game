using namespace std;
#include <deque>
#include <set>
#include <SFML/Graphics.hpp>


class Snake{
public:
    Snake();
    ~Snake();
    int move(sf::RenderWindow& window, int dir);
    void eat(int dir);
    deque<pair<int, int>> snake;
    set<string> body;

};