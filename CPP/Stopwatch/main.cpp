// source: https://open.kattis.com/problems/stopwatch

#include <iostream>
#include <vector>


static inline unsigned long calculateTimeDifferencce(std::vector<unsigned long>& timeStamps)
{
    unsigned long timeDiff = 0;
    for(size_t i=0; i<=timeStamps.size()-2; i=i+2){
        timeDiff = timeDiff + (timeStamps[i+1] - timeStamps[i]);
    }
    return timeDiff;
}


int main(void)
{   
    size_t n;  // number of times the stopwatch was pressed
    std::vector<unsigned long> timeStampsTheWatchWasPressed;
    std::cin >> n;

    for(size_t i=0; i<n; i++){
        unsigned long buffer;
        std::cin >> buffer;
        timeStampsTheWatchWasPressed.push_back(buffer);
    }

    if(n % 2 == 0){
        unsigned long stopWatchTime = calculateTimeDifferencce(timeStampsTheWatchWasPressed);
        std::cout << stopWatchTime << std::endl;
    }
    else{
        std::cout << "still running" << std::endl;
    }

    return EXIT_SUCCESS;
}
