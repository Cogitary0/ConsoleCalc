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


int main() {
    Sample_t* smpl = sample_init("2+3");

    if(smpl != NULL){
        printf("%i\n", smpl->count_numbers);
        printf("%i\n", smpl->count_opers);
        printf("g1\n");
        printf("%c\n", *smpl->opers);
        printf("g2\n");
        sample_free(smpl);
    }

    return 0;
}
