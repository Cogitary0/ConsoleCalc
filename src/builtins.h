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
    for(; *str != NULL_CHAR; str++){
        if(*str == '+' || *str == '-' || *str == '*' || *str == '/'){
            *sample->opers = *str;
            sample->opers++;
        }
    }
    *(sample->opers + 1) = '\0';
}
