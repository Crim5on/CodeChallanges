#include <iostream>
#include <array>



enum Direction {
    left,
    up,
    right,
    down
};



class PlayGrid {

    private:

        static const unsigned short dimension = 4;
        static const unsigned short maxIndex = dimension - 1;

        std::array<std::array<unsigned int, dimension>, dimension> grid;

        void readLine(const unsigned short lineNr){
            std::cin >> grid[lineNr][0] >> grid[lineNr][1] >> grid[lineNr][2] >> grid[lineNr][3];
        }

        Direction readInput(){
            // std::cout << "Please enter " << dimension << " lines of " << dimension << " numbers:" << std::endl;
            for(int lineNr=0; lineNr<dimension; lineNr++){
                readLine(lineNr);
            }
            unsigned short newDirection;
            // std::cout << "Please enter sliding direction (left=0, up=1, right=2, down=3): ";
            std::cin >> newDirection;
            return (Direction)newDirection;
        }

        bool canBeMerged(const unsigned int thisElement, const unsigned int nextElement){
            return (thisElement == nextElement && thisElement != 0);
        }

        bool canBeSlided(const unsigned int thisElement, const unsigned int nextElement){
            return (nextElement != 0 && thisElement == 0);
        }


        void slideColumnUp(const int column){
            for (int i=0; i<dimension-1; i++){
                for (int j=i+1; j<dimension; j++){
                    if (canBeSlided(grid[i][column], grid[j][column])){    
                        grid[i][column] = grid[j][column];
                        grid[j][column] = 0;
                    }
                }
            }
        }

        void mergeColumnUp(const int column){
            for (int i=0; i<dimension-1; i++){
                if (canBeMerged(grid[i][column], grid[i+1][column])){
                    grid[i][column] = grid[i][column] + grid[i+1][column];
                    grid[i+1][column] = 0;
                }
            }
        }

        void moveGridUp(){
            for(int column=0; column<dimension; column++){
                slideColumnUp(column);
                mergeColumnUp(column);
                slideColumnUp(column);
            }
        }


        void slideColumnDown(const int column){
            for (int i=dimension-1; i>0; i--){
                for (int j=i-1; j>=0; j--){
                    if (canBeSlided(grid[i][column], grid[j][column])){    
                        grid[i][column] = grid[j][column];
                        grid[j][column] = 0;
                    }
                }
            }
        }

        void mergeColumnDown(const int column){
            for (int i=dimension-1; i>0; i--){
                if (canBeMerged(grid[i][column], grid[i-1][column])){
                    grid[i][column] = grid[i][column] + grid[i-1][column];
                    grid[i-1][column] = 0;
                }
            }
        }

        void moveGridDown(){
            for(int column=0; column<dimension; column++){
                slideColumnDown(column);
                mergeColumnDown(column);
                slideColumnDown(column);
            }
        }



        void slideLineRight(const int line){
            for (int i=dimension-1; i>0; i--){
                for (int j=i-1; j>=0; j--){
                    if (canBeSlided(grid[line][i], grid[line][j])){    
                        grid[line][i] = grid[line][j];
                        grid[line][j] = 0;
                    }
                }
            }
        }

        void mergeLineRight(const int line){
            for (int i=dimension-1; i>0; i--){
                if (canBeMerged(grid[line][i], grid[line][i-1])){
                    grid[line][i] = grid[line][i] + grid[line][i-1];
                    grid[line][i-1] = 0;
                }
            }
        }

        void moveGridRight(){
            for(int line=0; line<dimension; line++){
                slideLineRight(line);
                mergeLineRight(line);
                slideLineRight(line);                
            }
        }


        void slideLineLeft(const int line){
            for (int i=0; i<dimension-1; i++){
                for (int j=i+1; j<dimension; j++){
                    if (canBeSlided(grid[line][i], grid[line][j])){    
                        grid[line][i] = grid[line][j];
                        grid[line][j] = 0;
                    }
                }
            }
        }

        void mergeLineLeft(const int line){
            for (int i=0; i<dimension-1; i++){
                if (canBeMerged(grid[line][i], grid[line][i+1])){
                    grid[line][i] = grid[line][i] + grid[line][i+1];
                    grid[line][i+1] = 0;
                }
            }
        }

        void moveGridLeft(){
            for(int line=0; line<dimension; line++){
                slideLineLeft(line);
                mergeLineLeft(line);
                slideLineLeft(line);
            }
        }


    public:

        void startRound(){
            Direction newDirection = readInput();

            if (newDirection == Direction::left){
                moveGridLeft();
            }
            else if (newDirection == Direction::up){
                moveGridUp();
            }
            else if (newDirection == Direction::right){
                moveGridRight();
            }
            else if (newDirection == Direction::down){
                moveGridDown();
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

        PlayGrid(){
            grid =  {{  
                        {0, 0, 0, 0}, 
                        {0, 0, 0, 0}, 
                        {0, 0, 0, 0}    
                    }};
        }
};










int main(){

    PlayGrid myGrid = PlayGrid();
    myGrid.startRound();

    return EXIT_SUCCESS;
}