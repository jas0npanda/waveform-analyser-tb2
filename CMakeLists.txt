cmake_minimum_required(VERSION 3.2)
project(waveform_analyser_tb2 C)

set(CMAKE_C_STANDARD 11)

add_executable(waveform_analyser_tb2 main.c waveform.h)
