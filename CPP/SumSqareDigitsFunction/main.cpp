// source: https://open.kattis.com/problems/sumSquareDigits

#include <iostream>
#include <vector>


struct DataSet{
    int k;          // data set running number
    int b;          // numeric base
    uint32_t n;     // number to be computed
    uint32_t ssd_result;
};


static inline uint32_t sumSquareDigits(int base, int32_t number)
{
    uint32_t ssd = 0;
    while(number > 0)
    {
        int digit = number % base;
        number = number / base;        
        ssd = ssd + digit * digit;
    }

    return ssd;
}


int main(void)
{   
    // INPUT:
    size_t numberOfDataSetsExpected;
    std::vector<DataSet> dataSets;
    std::cin >> numberOfDataSetsExpected;

    for(size_t i=0; i<numberOfDataSetsExpected; i++){
        DataSet buffer;
        std::cin >> buffer.k >> buffer.b >> buffer.n;
        dataSets.push_back(buffer);
    }


    // PROCESSING:
    for(DataSet& dataSet : dataSets){
        dataSet.ssd_result = sumSquareDigits(dataSet.b, dataSet.n);
    }


    // OUTPUT:
    for(DataSet& dataSet : dataSets){
        std::cout << dataSet.k << " " << dataSet.ssd_result << std::endl;
    }

    
    return EXIT_SUCCESS;
}
