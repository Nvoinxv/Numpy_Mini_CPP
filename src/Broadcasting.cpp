#include "Broadcasting.hpp"

BROADCASTING_TENSOR::BROADCASTING_TENSOR() : A({0.0}), B({0.0})
{
}

TENSOR BROADCASTING_TENSOR::penyelerasan_tensor(TENSOR &A, TENSOR &B, std::function<double(double, double)> operasi)
{
    size_t rank_A = A.rank_tensor();
    size_t rank_B = B.rank_tensor();
    size_t hasil_rank = rank_A > rank_B ? rank_A : rank_B;

    std::vector<size_t> bentuk_hasil(hasil_rank, 1);

    for (size_t i = 0; i < hasil_rank; ++i)
    {
        const size_t indeks_A = i < hasil_rank - rank_A
                                    ? 1
                                    : A.bentuk[i - (hasil_rank - rank_A)];

        const size_t indeks_B = i < hasil_rank - rank_B
                                    ? 1
                                    : B.bentuk[i - (hasil_rank - rank_B)];

        if (indeks_A != indeks_B &&
            indeks_A != 1 && indeks_B != 1)
        {
            throw std::invalid_argument(
                "BENTUK TIDAK BISA DI BROADCASTING");
        }

        bentuk_hasil[i] =
            indeks_A > indeks_B ? indeks_A : indeks_B;
    }

    size_t total_element = 1;

    for (size_t dim : bentuk_hasil)
    {
        total_element *= dim;
    }

    std::vector<double> hasil_data(total_element);

    std::vector<size_t> strides_A(hasil_rank, 1);
    std::vector<size_t> strides_B(hasil_rank, 1);

    for (size_t i = 0; i < rank_A; ++i)
    {
        strides_A[hasil_rank - rank_A + i] = A.strides[i];
    }

    for (size_t i = 0; i < rank_B; ++i)
    {
        strides_B[hasil_rank - rank_B + i] = B.strides[i];
    }

    for (size_t i = 0; i < hasil_rank; ++i)
    {
        const size_t dim1 = i < hasil_rank - rank_A
                                ? 1
                                : A.bentuk[i - (hasil_rank - rank_A)];

        const size_t dim2 = i < hasil_rank - rank_B
                                ? 1
                                : B.bentuk[i - (hasil_rank - rank_B)];

        if (dim1 == 1)
        {
            strides_A[i] = 0;
        }

        if (dim2 == 1)
        {
            strides_B[i] = 0;
        }
    }

    std::vector<size_t> indeks(hasil_rank, 0);

    for (size_t linear = 0; linear < total_element; ++linear)
    {
        size_t offset_A = 0;
        size_t offset_B = 0;
        size_t sisa = linear;

        for (size_t i = hasil_rank; i > 0; --i)
        {
            size_t indeks_dimensi = i - 1;

            indeks[indeks_dimensi] =
                sisa % bentuk_hasil[indeks_dimensi];

            sisa /= bentuk_hasil[indeks_dimensi];

            offset_A += indeks[indeks_dimensi] * strides_A[indeks_dimensi];
            offset_B += indeks[indeks_dimensi] * strides_B[indeks_dimensi];
        }

        hasil_data[linear] =
            operasi(A.data[offset_A], B.data[offset_B]);
    }

    return TENSOR(hasil_data, bentuk_hasil);
}
