#pragma once 

#include "typedefs.h"


uint b_count_opers(const char* str){
    uint count = 0;
    for(; *str != '\0'; str++){
        if(*str == '+' || *str == '-' || *str == '*' || *str == '/'){
            count++;
        }
    }
    return count;
}


void b_parse_opers(char* str, Sample_t* sample){
    char* temp_opers = sample->opers;
    for(; *str != '\0'; str++){
        if(*str == '+' || *str == '-' || *str == '*' || *str == '/'){
            *temp_opers = *str;
            temp_opers++;
        }
    }
    *temp_opers = '\0';
}

void b_parse_numbers(char* str, Sample_t* sample){
    int* temp_numbers = sample->numbers;
    for(; *str != '\0'; str++){
        if(*str >= '0' && *str <= '9'){
            *temp_numbers = *str - '0'; // Преобразование символа в число
            temp_numbers++;
        }
    }
    *temp_numbers = '\0';
}