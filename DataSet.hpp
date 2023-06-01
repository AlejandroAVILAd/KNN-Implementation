#ifndef DATA_SET
#define DATA_SET
#include <vector>

class DataSet
{
private:

    std::vector<float> x;
    std::vector<float> y;
    std::vector<char> types;

public:
    DataSet();
    std::vector<float> getX();
    std::vector<float> getY();
    std::vector<char> getTypes();
};

DataSet::DataSet()
{
    x = {25, // Edades
         35,
         45,
         20,
         35,
         52,
         23,
         40,
         60,
         48,
         33,
         48};

    y = {
        40000,  // Prestamos
        60000,
        80000,
        20000,
        120000,
        18000,
        95000,
        62000,
        1000000,
        2200000,
        150000,
        142000,
    };

    types = {
        'N',
        'N',
        'N',
        'N',
        'N',
        'N',
        'Y',
        'Y',
        'Y',
        'Y',
        'Y',
        'Y',
    };
}

std::vector<float> DataSet::getX()
{
    return x;
}

std::vector<float> DataSet::getY()
{
    return y;
}

std::vector<char> DataSet::getTypes()
{
    return types;
}

#endif
