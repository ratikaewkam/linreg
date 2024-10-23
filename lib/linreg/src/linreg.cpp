#include <iostream>
#include <vector>
#include <cmath>
#include <linreg.hpp>

namespace linreg
{
    parameter model::fit(std::vector<double> x, std::vector<double> y, parameter param, double alpha, double epochs, unsigned char track)
    {
        data data;
        data.x = x;
        data.y = y;

        optimizer optim;
        loss ls;

        unsigned int i;
        for (i = 0; i < epochs; i++)
        {
            param = optim.gradient_descent(data.x, data.y, param, alpha);
            param = ls.mse(data.x, data.y, param);
            if (track == 1)
            {
                std::cout << "epochs: " << i << "| " << "w: " << param.w << " " << "b: " << param.b << " " << "loss: " << param.mse << std::endl;
            }
            else if (track == 0)
            {
            }
            else
            {
                std::cout << "Invalid type..." << std::endl;
                std::cout << "Set type = 1 (track)" << std::endl;
                track = 1;
            }
        }

        return param;
    }
}