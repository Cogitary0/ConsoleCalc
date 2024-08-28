#include <stdlib.h>
#include <stdio.h>

#include "typedefs.h"
#include "constants.h"
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

    for(; *temp_opers != '\0'; temp_opers++){
        if(*temp_opers == '+'){
            sample->answer = *temp_numbers + *(temp_numbers + 1);
            continue;
        }
        else if(*temp_opers == '-'){
            sample->answer = *temp_numbers - *(temp_numbers + 1);
            continue;
        }
        else if(*temp_opers == '*'){
            sample->answer = *temp_numbers  * *(temp_numbers + 1);
            continue;
        }
        else if(*temp_opers == '/'){
            if(*(temp_numbers + 1) != 0){
                sample->answer = *temp_numbers / *(temp_numbers + 1);
                continue;
            }
        }
    }
}

int main() {
    
    for(uint i = 0; i < 10;  i++){
        char* inp = (char*)malloc(sizeof(char) * 128);
        Sample_t* smpl = sample_init(inp);

        if(smpl != NULL){
            sample_solve(smpl);
            printf("%i\n", smpl->count_numbers);
            printf("%i\n", smpl->count_opers);
            printf("%f\n", smpl->answer);
            printf("g2\n");
            sample_free(smpl);
        }
    }

    return 0;
}
