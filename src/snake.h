using namespace std;
#include <deque>
#include <set>
#include <SFML/Graphics.hpp>


class Snake{
public:
    Snake();
    ~Snake();
    int move(int h_x, int h_y);
    void eat(int h_x, int h_y);
    deque<pair<int, int>> snake;
    set<string> body;

};