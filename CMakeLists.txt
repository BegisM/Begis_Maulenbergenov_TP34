cmake_minimum_required(VERSION 3.29)
project(Begis_Maulenbergenov_TP34)

set(CMAKE_CXX_STANDARD 20)

add_executable(Begis_Maulenbergenov_TP34 main.cpp
        Pinning_Name/ubuntu_pinning_name.cpp
        Pinning_Name/windows_pinning_name.cpp
)
