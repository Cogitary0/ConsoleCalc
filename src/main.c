#include <stdlib.h>
#include <stdio.h>

#include "typedefs.h"
#include "builtins.h"

#define DEBUG print("DEBUG LINE >> %i\n", __LINE__);

Sample_t* sample_init(char* str){
    Sample_t* sample = (Sample_t*)malloc(sizeof(Sample_t));
    if(sample == NULL){
        return NULL;
    }
    sample->count_opers = b_count_opers(str);
    sample->count_numbers = sample->count_opers + 1;
    sample->answer = 0.0f;

    sample->numbers = (int*)malloc(sizeof(int) * sample->count_numbers);
    if(sample->numbers == NULL){
        free(sample);
        return NULL;
    }

    sample->opers = (char*)malloc(sizeof(char) * sample->count_opers);
    if(sample->opers == NULL){
        free(sample->numbers);
        free(sample);
        return NULL;
    }

    b_parse_numbers(str, sample);
    b_parse_opers(str, sample);

    return sample;
}

void sample_free(Sample_t* sample){
    if(sample != NULL){
        if(sample->opers != NULL){
            free(sample->opers);
        }
        if(sample->numbers != NULL){
            free(sample->numbers);
        }
        free(sample);
        return;
    }
    return;
}


void sample_solve(Sample_t* sample){
    const int* temp_numbers = sample->numbers;
    const char* temp_opers = sample->opers;
    int result = temp_numbers[0];

    for(uint i = 0; i < sample->count_opers; ++i){

        if(*temp_opers == '+'){
            result += temp_numbers[i + 1];
        }
        else if(*temp_opers == '-'){    
            result -= temp_numbers[i + 1];
        }
        else if(*temp_opers == '*'){
            result *= temp_numbers[i + 1];
        }
        else if(*temp_opers == '^'){
            result = (float)b_pow32(result, temp_numbers[i + 1]);
        }
        else if(*temp_opers == '/'){
            if(temp_numbers[i + 1] != 0){
                result /=  temp_numbers[i + 1];

            }
        }

    }
    sample->answer = result;
}


void sample_println(Sample_t* sample){
    
}

int main(int argc, char** argv) {
    
    for(;;){
        char* input = (char*)malloc(sizeof(char) * 128);

        if(input == NULL){
            continue;
        }

        printf("\n> ");
        scanf("%s", input);

        if(*input == 'c'){
            printf("!> Programm off\n");
            free(input);
            return 0;
        }

        Sample_t* smpl = sample_init(input);

        if(smpl != NULL){
            sample_solve(smpl);
            // printf("C_num:\t%i\n", smpl->count_numbers);
            // printf("C_op:\t%i\n", smpl->count_opers);
            printf("= %f\n", smpl->answer);
            // b_round(smpl, 3);
            // printf("A_r:\t%f\n", smpl->answer);
            sample_free(smpl);
        }
        free(input);
    }

    return 0;
}
