#include <exception>
using namespace std;
#include <string>

class GameOverException: public exception{
    
    public:
        GameOverException(char* message): message(message){}
        char* what(){
            return message;
        }
    private:
        char* message;
};