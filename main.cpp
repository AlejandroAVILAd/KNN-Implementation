#include "DataSet.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

bool compare(const pair<float, char> &i, const pair<float, char> &j);
vector<pair<float, char>> mideDistancia(vector<float> x, vector<float> y, vector<char> types, int age, int loan, int size);
void muestraTipo(vector<pair<float, char>> distance, int k, int age, int loan);

int main()
{
    //Cuántos vecinos más cercanos
    const int K = 5;

    // Lista de medidas
    vector<pair<float, char>> medidas;

    // Nuevo dato : edad
    const int NEW_AGE = 48;

    const int LOAN = 142000; // Préstamo

    DataSet data;

    vector<float> x;
    vector<float> y;
    vector<char> tipos;

    x = data.getX();
    y = data.getY();
    tipos = data.getTypes();

    cout<<endl;

    medidas = mideDistancia(x, y, tipos, NEW_AGE, LOAN, x.size());
    muestraTipo(medidas, K, NEW_AGE, LOAN);

    return EXIT_SUCCESS;
}


bool compare(const pair<float, char> &i, const pair<float, char> &j)
{
    return i.first < j.first;
}

vector<pair<float, char>> mideDistancia(vector<float> x, vector<float> y, vector<char> types, int age, int loan, int size)
{
    vector<pair<float, char>> medidas;
    for (int c = 0; c < size; c++)
    {
        const float distance = sqrt(pow(x[c] - age, 2) + pow(y[c] - loan, 2));
        pair<float, char> data;
        data.second = types[c];
        data.first = distance;
        medidas.insert(medidas.end(), data);
    }

    std::sort(medidas.begin(), medidas.end(), compare);

    return medidas;
}

void muestraTipo(vector<pair<float, char>> distance, int k, int age, int loan)
{
    cout << endl;
    int defaultN = 0;
    int defaultY = 0;

    for (int c = 0; c < k; c++)
    {
        cout << " " << c + 1 << " Dis: " << distance[c].first << " Type: " << distance[c].second << endl;
        if (distance[c].second == 'N')
            defaultN++;
        else
            defaultY++;
    }

    if (defaultN < defaultY)
        cout << "Es un SI" << endl;
    else
        cout << "Es un NO" << endl;
}

