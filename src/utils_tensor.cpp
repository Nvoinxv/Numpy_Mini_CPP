#include "utils_tensor.hpp"

utils::utils() : A({0.0}), B({0.0}) {

                 };

void utils::print_tensor(TENSOR &A)
{

    int n = A.size();

    for (int i = 0; i < n; ++i)
    {

        std::cout << A[i] << " ";
    }

    std::cout << "\n";
}

TENSOR utils::zeros_tensor(TENSOR &A)
{

    int n = A.size();

    for (int i = 0; i < n; ++i)
    {
        A[i] = 0;
    }

    return A;
}

TENSOR utils::ones_tensor(TENSOR &A)
{
    int n = A.size();

    for (int i = 0; i < n; ++i)
    {

        A[i] = 1;
    }

    return A;
}
