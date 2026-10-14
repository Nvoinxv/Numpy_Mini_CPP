cmake_minimum_required(VERSION 3.23)

project(MINI_NUMPY_CPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    src/Dasar_Operasi.cpp
    src/Broadcasting.cpp
    src/Tensor.cpp
    src/fungsi_matematika.cpp
    src/utils_tensor.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
