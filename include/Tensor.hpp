#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <limits>

struct TENSOR
{
    std::vector<double> data;
    std::vector<size_t> bentuk;
    std::vector<size_t> strides;

    TENSOR() = default;

    TENSOR(std::vector<double> d_data,
           std::vector<size_t> b_bentuk) : data(d_data), bentuk(b_bentuk)
    {
        perhitungan_bentuk();
    }

    TENSOR(std::initializer_list<double> indeks) : data(indeks), bentuk({data.size()})
    {
        perhitungan_bentuk();
    }

    size_t size()
    {
        return data.size();
    }

    size_t rank_tensor()
    {
        return bentuk.size();
    }

    double &operator[](int indeks)
    {
        return data.at(indeks);
    }

    const double &operator[](int indeks) const
    {
        return data.at(indeks);
    }

    double &akses(std::vector<size_t> indeks)
    {
        return data.at(perhitungan_indeks_linear(indeks));
    }

    const double &akses(std::vector<size_t> indeks) const
    {
        return data.at(perhitungan_indeks_linear(indeks));
    }

private:
    void perhitungan_bentuk();
    void perhitungan_strides();
    size_t perhitungan_indeks_linear(
        std::vector<size_t> &indeks) const;
};

#endif