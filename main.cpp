#include "include/Tensor.hpp"
#include "include/utils_tensor.hpp"
#include "include/Broadcasting.hpp"
#include "include/Dasar_Operasi.hpp"
#include "include/fungsi_matematika.hpp"

int main()
{
    std::cout << "MELAKUKAN TEST TENSOR\n";

    TENSOR A = {
        {2, 3, 5, 7, 11, 13},
        {2, 1, 3}};

    TENSOR B = {
        {1, 3, 5, 3, 5, 1},
        {2, 1, 3}};

    TENSOR A_DIM_1 = {
        {2, 3, 5, 1, 6},
        {5}};

    TENSOR B_DIM_1 = {
        {1, 3, 5, 1, 3},
        {5}};

    TENSOR A_DIM_2 = {
        {2, 5},
        {2, 1}};

    TENSOR B_DIM_2 = {{1, 5}, {2, 1}};

    TENSOR A_DIM_4 = {
        {1, 3, 5, 1, 6, 2,
         3, 5, 1, 6, 9, 10,
         11, 2, 15, 1},
        {2, 2, 2, 2}};

    TENSOR B_dim_2D = {
        {1, 5},
        {2, 1}};

    utils tensor_utils;

    std::cout << "INPUT PERTAMA: ";
    tensor_utils.print_tensor(A);

    std::cout << "INPUT KEDUA: ";
    tensor_utils.print_tensor(B);

    std::cout << "TEST TENSOR UTILS ZEROS DAN ONES\n";

    std::cout << "INPUT PERTAMA ZEROS: ";
    TENSOR A_zeros_tensor = tensor_utils.zeros_tensor(A);
    tensor_utils.print_tensor(A_zeros_tensor);

    std::cout << "INPUT KEDUA ZEROS: ";
    TENSOR B_zeros_tensor = tensor_utils.zeros_tensor(B);
    tensor_utils.print_tensor(B_zeros_tensor);

    std::cout << "INPUT PERTAMA ONES: ";
    TENSOR A_ones_tensor = tensor_utils.ones_tensor(A);
    tensor_utils.print_tensor(A_ones_tensor);

    std::cout << "INPUT KEDUA ONES: ";
    TENSOR B_ones_tensor = tensor_utils.ones_tensor(B);
    tensor_utils.print_tensor(B_ones_tensor);

    std::cout << "MEMULAI BROADCASTING TENSOR\n";

    BROADCASTING_TENSOR broadcasting;

    std::cout << "DIMENSI A 1D: ";
    tensor_utils.print_tensor(A_DIM_1);

    std::cout << "DIMENSI B 1D: ";
    tensor_utils.print_tensor(B_DIM_1);

    std::cout << "HASIL BROADCASTING TENSOR 1D: ";
    TENSOR perhitungan_penyelarasan_1d = broadcasting.penyelerasan_tensor(A_DIM_1, B_DIM_1);
    tensor_utils.print_tensor(perhitungan_penyelarasan_1d);

    std::cout << "DIMENSI A 2D: ";
    tensor_utils.print_tensor(A_DIM_2);

    std::cout << "DIMENSI B 2D: ";
    tensor_utils.print_tensor(B_DIM_2);

    std::cout << "HASIL BROADCASTING TENSOR 2D: ";
    TENSOR perhitungan_penyelarasan_2d = broadcasting.penyelerasan_tensor(A_DIM_2, B_DIM_2);
    tensor_utils.print_tensor(perhitungan_penyelarasan_2d);

    std::cout << "DIMENSI A 4D: ";
    tensor_utils.print_tensor(A_DIM_4);

    std::cout << "DIMENSI B 2D: ";
    tensor_utils.print_tensor(B_dim_2D);

    std::cout << "HASIL BROADCASTING TENSOR MULTI DIMENSI: ";
    TENSOR perhitungan_penyelarasan_multi_dimensi = broadcasting.penyelerasan_tensor(A_DIM_4, B_dim_2D);
    tensor_utils.print_tensor(perhitungan_penyelarasan_multi_dimensi);

    std::cout << "MEMULAI OPERASI PERHITUNGAN DASAR\n";
    std::cout << "VERSI 1 DIMENSI\n";

    std::cout << "1D TAMBAH: ";
    tensor_utils.print_tensor(perhitungan_penyelarasan_1d);

    std::cout << "1D KURANG: ";
    TENSOR operasi_kurang = A_DIM_1 - B_DIM_1;
    tensor_utils.print_tensor(operasi_kurang);

    std::cout << "1D PERKALIAN: ";
    TENSOR operasi_perkalian = A_DIM_1 * B_DIM_1;
    tensor_utils.print_tensor(operasi_perkalian);

    std::cout << "1D PEMBAGIAN: ";
    TENSOR operasi_pembagian = A_DIM_1 * B_DIM_1;
    tensor_utils.print_tensor(operasi_pembagian);

    std::cout << "VERSI 2 DIMENSI\n";

    std::cout << "2D TAMBAH: ";
    tensor_utils.print_tensor(perhitungan_penyelarasan_2d);

    std::cout << "2D KURANG: ";
    TENSOR operasi_kurang_2d = A_DIM_2 - B_DIM_2;
    tensor_utils.print_tensor(operasi_kurang_2d);

    std::cout << "2D PERKALIAN: ";
    TENSOR operasi_perkalian_2d = A_DIM_2 * A_DIM_2;
    tensor_utils.print_tensor(operasi_perkalian_2d);

    std::cout << "2D PEMBAGIAN: ";
    TENSOR operasi_pembagian_2d = A_DIM_2 * B_DIM_2;
    tensor_utils.print_tensor(operasi_pembagian_2d);

    std::cout << "VERSI MULTI DIMENSI\n";

    std::cout << "MULTI DIMENSI TAMBAH: ";
    tensor_utils.print_tensor(perhitungan_penyelarasan_multi_dimensi);

    std::cout << "MULTI DIMENSI KURANG: ";
    TENSOR operasi_kurang_multi_dimensi = broadcasting.penyelerasan_tensor(A_DIM_4, B_dim_2D,
                                                                           [](double a, double b)
                                                                           { return a - b; });
    tensor_utils.print_tensor(operasi_kurang_multi_dimensi);

    std::cout << "MULTI DIMENSI PERKALIAN: ";
    TENSOR operasi_perkalian_multi_dimensi = broadcasting.penyelerasan_tensor(A_DIM_4, B_dim_2D,
                                                                              [](double a, double b)
                                                                              { return a * b; });
    tensor_utils.print_tensor(operasi_perkalian_multi_dimensi);

    std::cout << "MULTI DIMENSI PEMBAGIAN: ";
    TENSOR operasi_pembagian_multi_dimensi = broadcasting.penyelerasan_tensor(A_DIM_4, B_dim_2D, [](double a, double b)
                                                                              {
        if (b == 0.0) {
            throw std::invalid_argument("TIDAK BISA DIBAGI DENGAN NOL!");
        }

        return a / b; });
    tensor_utils.print_tensor(operasi_pembagian_multi_dimensi);

    MATEMATIKA_FUNGSI fungsi_math;

    std::cout << "MEMULAI FUNGSI MATEMATIKA\n";

    std::cout << "FUNGSI SIN A: ";
    TENSOR fungsi_sin_A = fungsi_math.fungsi_sin(A);
    tensor_utils.print_tensor(fungsi_sin_A);

    std::cout << "FUNGSI COS A: ";
    TENSOR fungsi_cos_A = fungsi_math.fungsi_cos(A);
    tensor_utils.print_tensor(fungsi_cos_A);

    std::cout << "FUNGSI TAN A: ";
    TENSOR fungsi_tan_A = fungsi_math.fungsi_tan(A);
    tensor_utils.print_tensor(fungsi_tan_A);

    std::cout << "FUNGSI CSC A: ";
    TENSOR fungsi_csc_A = fungsi_math.fungsi_csc(A);
    tensor_utils.print_tensor(fungsi_csc_A);

    std::cout << "FUNGSI SEC A: ";
    TENSOR fungsi_sec_A = fungsi_math.fungsi_sec(A);
    tensor_utils.print_tensor(fungsi_sec_A);

    std::cout << "FUNGSI COT A: ";
    TENSOR fungsi_cot_A = fungsi_math.fungsi_cot(A);
    tensor_utils.print_tensor(fungsi_cot_A);

    std::cout << "FUNGSI LOGARITMA A: ";
    TENSOR fungsi_logaritma_A = fungsi_math.fungsi_logartima(A);
    tensor_utils.print_tensor(fungsi_logaritma_A);

    std::cout << "FUNGSI SQRT A: ";
    TENSOR fungsi_sqrt_A = fungsi_math.fungsi_sqrt(A);
    tensor_utils.print_tensor(fungsi_sqrt_A);

    std::cout << "FUNGSI EKSPONENSIAL A: ";
    TENSOR fungsi_ekseponensial_A = fungsi_math.fungsi_eksponensial(A);
    tensor_utils.print_tensor(fungsi_ekseponensial_A);

    return 0;
}