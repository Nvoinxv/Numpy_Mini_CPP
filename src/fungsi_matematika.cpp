#include "fungsi_matematika.hpp"

MATEMATIKA_FUNGSI::MATEMATIKA_FUNGSI() : A({0.0}), hasil_perhitungan({0.0}), n(0)
{
}

TENSOR MATEMATIKA_FUNGSI::fungsi_sin(TENSOR &A)
{
    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {
        hasil_perhitungan.data[i] = std::sin(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_cos(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = std::cos(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_tan(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = std::tan(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_csc(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = 1.0 / std::sin(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_sec(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = 1.0 / std::cos(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_cot(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = 1.0 / std::tan(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_logartima(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = std::log(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_sqrt(TENSOR &A)
{

    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = std::sqrt(A[i]);
    }

    return hasil_perhitungan;
}

TENSOR MATEMATIKA_FUNGSI::fungsi_eksponensial(TENSOR &A)
{
    n = A.size();

    hasil_perhitungan = A;

    for (int i = 0; i < n; ++i)
    {

        hasil_perhitungan.data[i] = std::exp(A[i]);
    }

    return hasil_perhitungan;
}