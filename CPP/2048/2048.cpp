#include <iostream>
#include <string>
#include <vector>
#include <array>

enum Direction {
    left,
    up,
    right,
    down
};

class PlayGrid {

    private:

        const unsigned short dimension = 4;
        std::array<std::array<int, 4>, 4> grid = {{ {0, 0, 0, 0}, 
                                                    {0, 0, 0, 0}, 
                                                    {0, 0, 0, 0} }};

        void readLine(const unsigned short lineNr){
            std::cout << "Please enter line " << lineNr+1 << ':' << std::endl;
            std::cin >> grid[lineNr][0] >> grid[lineNr][1] >> grid[lineNr][2] >> grid[lineNr][3];
        }

        Direction readInput(){
            for(int lineNr=0; lineNr<dimension; lineNr++){
                readLine(lineNr);
            }
            unsigned short newDirection;
            std::cout << "Please enter direction to rotate: " << std::endl;
            std::cin >> newDirection;
            return (Direction)newDirection;
        }

        void moveUp(){
            ;
        }

        void moveDown(){
            ;
        }

        void moveRight(){
            ;
        }

        void moveLeft(){
            ;
        }


    public:

        void startRound(){
            Direction newDirection = readInput();

            if (newDirection == Direction::up){
                moveUp();
            }
            else if (newDirection == Direction::down){
                moveDown();
            }
            else if (newDirection == Direction::right){
                moveRight();
            }
            else if (newDirection == Direction::left){
                moveLeft();
            }
            else {
                std::cerr << "Direction not Valid!" << std::endl;
            }

            printGrid();
        }


        void printGrid(){
            for(auto line : grid){
                for(auto number : line){
                    std::cout << number << ' ';
                }
                std::cout << std::endl;
            }
        }

};





int main(){

    PlayGrid myGrid = PlayGrid();
    myGrid.startRound();



    return EXIT_SUCCESS;
}