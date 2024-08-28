#include <stdlib.h>
#include <stdio.h>

#include "typedefs.h"
#include "constants.h"
#include "builtins.h"

Sample_t* sample_init(char* str){
    Sample_t* sample = (Sample_t*)malloc(sizeof(Sample_t));
    if(sample == NULL){
        return NULL;
    }
    sample->count_opers = b_count_opers(str);
    sample->count_numbers = sample->count_opers + 1;

    sample->numbers = (float*)malloc(sizeof(float) * sample->count_numbers);
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

    parse_numbers(str, sample->numbers);
    parse_opers(str, sample->opers);

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



int main() {
    printf("Hello");
    return 0;
}
