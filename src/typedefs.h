#pragma once

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef unsigned int uint;

typedef struct Sample{
    float* numbers;
    char* opers;
    float answer;
    uint count_opers;
    uint count_numbers;
} Sample_t;