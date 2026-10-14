#ifndef TENSOR_OPERASI_PERHITUNGAN_HPP
#define TENSOR_OPERASI_PERHITUNGAN_HPP

#include "Tensor.hpp"
#include "Broadcasting.hpp"
#include <stdexcept>

TENSOR operator+(TENSOR &A, TENSOR &B);

TENSOR operator-(TENSOR &A, TENSOR &B);

TENSOR operator*(TENSOR &A, TENSOR &B);

TENSOR operator/(TENSOR &A, TENSOR &B);

struct OPERASI_HITUNG
{
    TENSOR A;
    TENSOR B;
    TENSOR HASIL_PERHITUNGAN;
    BROADCASTING_TENSOR broadcast;
};

#endif