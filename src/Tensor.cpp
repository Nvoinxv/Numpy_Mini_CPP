#include "Tensor.hpp"

void TENSOR::perhitungan_bentuk()
{

    size_t total_element = 1;

    for (size_t dim : bentuk)
    {

        if (dim != 0 &&
            total_element > std::numeric_limits<size_t>::max() / dim)
        {

            throw std::overflow_error("BENTUK SUDAH MELEBIHI MAKSIMUM!");
        }

        total_element *= dim;
    }

    if (data.size() != total_element)
    {
        throw std::invalid_argument("INPUT HARUS SESUAI DENGAN UKURAN BENTUK!");
    }

    perhitungan_strides();
}

void TENSOR::perhitungan_strides()
{
    strides.resize(bentuk.size());

    size_t stride = 1;

    for (size_t i = bentuk.size(); i > 0; --i)
    {

        strides[i - 1] = stride;
        stride *= bentuk[i - 1];
    }
}

size_t TENSOR::perhitungan_indeks_linear(
    std::vector<size_t> &indeks) const
{

    size_t memulai_perhitungan = 0;

    for (size_t i = 0; i < indeks.size(); ++i)
    {

        if (indeks[i] > strides[i])
        {

            throw std::overflow_error("INDEKS SUDAH MELEBIHI BATAS STRIDES!");
        }

        memulai_perhitungan += indeks[i] * strides[i];
    }

    return memulai_perhitungan;
}
