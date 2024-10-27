# linreg
Building my own C++ library for the Linear Regression

![GitHub Release](https://img.shields.io/github/v/release/ratikaewkam/linreg)
![GitHub contributors](https://img.shields.io/github/contributors/ratikaewkam/linreg)
![GitHub repo size](https://img.shields.io/github/repo-size/ratikaewkam/linreg)
![GitHub forks](https://img.shields.io/github/forks/ratikaewkam/linreg)


## Latest Feature
- Find a linear regression equation
- Fix invalid track value
- Update error handling (data size, invalid value)

## Example
```c++
// main.cpp
#include <iostream>
#include <vector>
#include <linreg.hpp>

int main()
{
    linreg::model model;
    linreg::parameter param;

    std::vector<double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<double> y = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    double alpha = 0.01; // Learning rate
    int epochs = 3333;
    int track = 1; // Type 1 : track value

    param = model.fit(x, y, param, alpha, epochs, track);

    std::cout << "y = " << param.w << "x + " << param.b << std::endl;
    std::cout << "loss: " << param.mse << std::endl;

    return 0;
}
```

## Run
Run the following command in the Developer CMD for VS
```cmd
cd build
```
```cmd
cmake ..
```
```cmd
cmake --build .
```
```cmd
cd Debug
```
```cmd
main
```
or
```cmd
g++ -I lib/include -c lib/src/mse.cpp -o build/obj/mse.o

g++ -I lib/include -c lib/src/gradient_descent.cpp -o build/obj/gradient_descent.o

g++ -I lib/include -c lib/src/linreg.cpp -o build/obj/linreg.o

g++ -I lib/include -o build/program/program main.cpp build/obj/mse.o build/obj/gradient_descent.o build/obj/linreg.o
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Please make sure to update tests as appropriate.

## References
[Gradient Descent](https://github.com/ratikaewkam/GradientDescent) | 
[Linear Regression](https://github.com/ratikaewkam/LinearRegression)

## License
[MIT](https://choosealicense.com/licenses/mit/)

---
Developed by [Rati Kaewkam](https://github.com/ratikaewkam)