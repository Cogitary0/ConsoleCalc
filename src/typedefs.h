#pragma once

typedef signed   char       int8_t;
typedef unsigned char       uint8_t;
typedef unsigned int        uint;
typedef signed   int        int16_t;
typedef signed   long       int32_t;
typedef unsigned long       uint32_t;
typedef signed   long long  int64_t;
typedef unsigned long long  uint64_t;
typedef enum {false, true} bool;


typedef struct Sample{
    int* numbers;
    char* opers;
    double answer;
    uint count_opers;
    uint count_numbers;
} Sample_t;
