#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include <linreg.hpp>

namespace linreg
{
    parameter model::fit(std::vector<double> x, std::vector<double> y, parameter param, double alpha, int epochs, int track)
    {
        if (alpha <= 0)
        {
            std::cout << "Error-> Invalid alpha value\n";
            std::cout << "Set alpha value -> 0.0001\n";
            std::cout << "****************************" << std::endl;
            alpha = 0.0001;
        }

        if (epochs <= 0)
        {
            std::cout << "Error-> Invalid epoch value\n";
            std::cout << "Set epoch value -> 1\n";
            std::cout << "****************************" << std::endl;
            epochs = 1;
        }

        if (track < 0)
        {
            std::cout << "Error-> Invalid track value\n";
            std::cout << "Set track value -> 0\n";
            std::cout << "****************************" << std::endl;
            track = 0;
        }

        try
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
                    std::cout << "|" << (i + 1) << "| " << "w: " << param.w << " " << "b: " << param.b << " " << "loss: " << param.mse << std::endl;
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
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        return param;
    }
}