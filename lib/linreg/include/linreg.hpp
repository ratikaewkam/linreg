#ifndef LINREG_HPP
#define LINREG_HPP
#include <iostream>
#include <vector>
#include <cmath>

namespace linreg
{
    class model
    {
    protected:
        struct data
        {
            std::vector<double> x;
            std::vector<double> y;
        };

        struct  parameter
        {
            double w, b, mse;
        };

        class loss
        {
            double gradient_descent(std::vector<double> x, std::vector<double> y, double w, double b, double alpha)
            {
                
            }
        };   

    public:
        void load(std::vector<double> x, std::vector<double> y);

        void fit(double alpha, double epochs, unsigned char track);

        void getparam();
    };
}

#endif