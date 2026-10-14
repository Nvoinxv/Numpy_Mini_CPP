#ifndef TENSOR_UTILS_HPP
#define TENSOR_UTILS_HPP

#include "Tensor.hpp"
#include <iostream>

class utils
{
private:
    TENSOR A;
    TENSOR B;

public:
    utils();

    void print_tensor(TENSOR &A);
    TENSOR zeros_tensor(TENSOR &A);
    TENSOR ones_tensor(TENSOR &A);
    void membersihkan_tensor(TENSOR &A);
};

#endif