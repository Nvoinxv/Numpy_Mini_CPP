#include "Dasar_Operasi.hpp"

TENSOR operator+(TENSOR &A, TENSOR &B)
{
    BROADCASTING_TENSOR broadcast;

    return broadcast.penyelerasan_tensor(
        A, B, [](double a, double b)
        { return a + b; });
}

TENSOR operator-(TENSOR &A, TENSOR &B)
{
    TENSOR HASIL_PERHITUNGAN;
    BROADCASTING_TENSOR broadcast;

    return broadcast.penyelerasan_tensor(
        A, B, [](double a, double b)
        { return a - b; });
}

TENSOR operator*(TENSOR &A, TENSOR &B)
{
    TENSOR HASIL_PERHITUNGAN;
    BROADCASTING_TENSOR broadcast;

    return broadcast.penyelerasan_tensor(
        A, B, [](double a, double b)
        { return a * b; });
}

TENSOR operator/(TENSOR &A, TENSOR &B)
{
    TENSOR HASIL_PERHITUNGAN;
    BROADCASTING_TENSOR broadcast;

    return broadcast.penyelerasan_tensor(
        A, B, [](double a, double b)
        {
            if (b == 0.0) {
                throw std::invalid_argument("TIDAK BISA DI BAGI DENGAN NOL!");
            }

            return a / b; });
}