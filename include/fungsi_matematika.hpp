#ifndef FUNGSI_MATEMATIKA_HPP
#define FUNGSI_MATEMATIKA_HPP

#include "Tensor.hpp"
#include <cmath>

class MATEMATIKA_FUNGSI
{
private:
    TENSOR A;
    TENSOR hasil_perhitungan;
    size_t n;

public:
    MATEMATIKA_FUNGSI();

    TENSOR fungsi_sin(TENSOR &A);
    TENSOR fungsi_cos(TENSOR &A);
    TENSOR fungsi_tan(TENSOR &A);

    TENSOR fungsi_csc(TENSOR &A);
    TENSOR fungsi_sec(TENSOR &A);
    TENSOR fungsi_cot(TENSOR &A);

    TENSOR fungsi_logartima(TENSOR &A);
    TENSOR fungsi_sqrt(TENSOR &A);
    TENSOR fungsi_eksponensial(TENSOR &A);
};

#endif