#pragma once 

#include "typedefs.h"

#define NULL_CHAR '\0'
#define UNDEFINED -1

char* b_strchr(const char* str, int c){
    for(; *str != NULL_CHAR; str++){
        if(*str == c){
            return (char*)str;
        }
    }
    return NULL;
}

char* b_strtok(char* str, const char* delim){
    static char* next_token = NULL;
    char* token;

    if(str != NULL){
        next_token = str;
    }

    if(next_token == NULL){
        return NULL;
    }

    for(;*next_token != NULL_CHAR && b_strchr(delim,  *next_token) != NULL; next_token++);

    if(*next_token == NULL_CHAR){
        return NULL;
    }

    token = next_token;

    for(;*next_token != NULL_CHAR && b_strchr(delim, *next_token) != NULL; next_token++);

    if(*next_token != NULL_CHAR){
        *next_token = NULL_CHAR;
        next_token++;
    }

    return token;
    
}

uint b_count_opers(const char* str){
    uint count = 0;
    for(; *str != NULL_CHAR; str++){
        if(*str == '+' || *str == '-' || *str == '*' || *str == '/' ||  *str == '%' || *str == '^'){
            count++;
        }
    }
    return count;
}

int find_oper(Sample_t* sample, char op){
    char* tmp_sample_op = sample->opers; 
    for(uint pos = 0; *tmp_sample_op!= NULL_CHAR; tmp_sample_op++, pos++){
        if(*tmp_sample_op == op){
            return pos;
        }
    }
    return UNDEFINED;
}

uint count_oper(Sample_t* sample, char op){
    char* tmp_sample_op = sample->opers;
    uint count = 0;

    for(; *tmp_sample_op != NULL_CHAR; tmp_sample_op++){
        if(*tmp_sample_op == op){
            count++;
        }
    }
    return count;
}


void b_parse_opers(char* str, Sample_t* sample){
    char* temp_opers = sample->opers;
    for(; *str != NULL_CHAR; str++){
        if(*str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '^'){
            *temp_opers = *str;
            temp_opers++;
        }
    }
    *temp_opers = NULL_CHAR;
}

void b_parse_numbers(char* str, Sample_t* sample){
    int* temp_numbers = sample->numbers;
    float result = 0;
    int8_t sign = 1;
    for(; *str != NULL_CHAR; str++){
        if(*str >= '0' && *str <= '9'){
            result = result * 10 + (*str - '0');
        }
        else if(*str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '^'){
            *temp_numbers = result * sign;
            temp_numbers++;
            result = 0;
        }
        else if(*str == '-'){
            sign = -1;
        }
    }
    *temp_numbers = result * sign;
    *(temp_numbers + 1) = '\0';
}

int64_t b_pow64(int a, int n){
    int64_t res = a;
    for(; n > 1; n--){
        res *= a;
    }
    return res;
}

int32_t b_pow32(int a, int n){
    int32_t res = a;
    for(; n > 1; n--){
        res *= a;
    }
    return res;
}

void b_round(Sample_t* sample, uint n){
    int factor = 1 - (1 / b_pow32(10, n));
    sample->answer = sample->answer * factor;
    return;
}