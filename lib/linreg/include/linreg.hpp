#ifndef LINREG_HPP
#define LINREG_HPP
#include <iostream>
#include <vector>
#include <cmath>

namespace linreg
{
    class parameter
    {
    public:
        double w = 0;
        double b = 0;
        double mse = 0;
    };

    class model
    {
    protected:
        class data
        {
        public:
            std::vector<double> x;
            std::vector<double> y;
        };

        class optimizer
        {
        public:
            parameter gradient_descent(std::vector<double> x, std::vector<double> y, parameter param, double alpha)
            {
                if (x.size() != y.size())
                {
                    throw "Error -> Invalid data size";
                }

                double dw = 0;
                double db = 0;
                unsigned int n = x.size();
                unsigned int i = 0;

                for (i = 0; i < n; i++)
                {
                    double pred = (param.w * x[i]) + param.b;
                    double e = y[i] - pred;
                    dw += (-2.0 / n) * e * x[i];
                    db += (-2.0 / n) * e;
                }

                param.w -= alpha * dw;
                param.b -= alpha * db;

                return param;
            }
        };

        class loss
        {
        public:
            parameter mse(std::vector<double> x, std::vector<double> y, parameter param)
            {
                if (x.size() != y.size())
                {
                    throw "Error -> Invalid data size";
                }

                double err = 0;
                double e = 0;
                double pred = 0;
                unsigned int n = x.size();
                unsigned int i = 0;

                for (i = 0; i < n; i++)
                {
                    pred = (param.w * x[i]) + param.b;
                    e = y[i] - pred;
                    err += std::pow(e, 2);
                }

                param.mse = err / n;

                return param;
            }
        };

    public:
        parameter fit(std::vector<double> x, std::vector<double> y, parameter param, double alpha, int epochs, int track);
    };
}

#endif