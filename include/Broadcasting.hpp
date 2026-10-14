#ifndef BROADCASTING_HPP
#define BROADCASTING_HPP

#include "Tensor.hpp"
#include <vector>
#include <functional>

class BROADCASTING_TENSOR
{
private:
    TENSOR A;
    TENSOR B;

public:
    BROADCASTING_TENSOR();

    TENSOR penyelerasan_tensor(
        TENSOR &A, TENSOR &B,
        std::function<double(double, double)> operasi =
            [](double a, double b)
        { return a + b; });
};

#endif