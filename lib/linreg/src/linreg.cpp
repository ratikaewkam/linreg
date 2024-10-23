#include <iostream>
#include <vector>
#include <cmath>
#include <linreg.hpp>

namespace linreg
{
    void model::load(std::vector<double> x, std::vector<double> y)
    {
        model::data data;
        data.x = x;
        data.y = y;
    }

    void model::fit(double alpha, double epochs, unsigned char track)
    {

    }
}