#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "enums.h"

input analysis(int argc, char **argv) {
    if (argc > 4 || argc < 3) {
        return isc_too_args;
    }
    if (!strcmp(argv[1], "xor8") && argc == 3) {
        return isc_xor8;
    }
    if (!strcmp(argv[1], "xor32") && argc == 3) {
        return isc_xor32;
    }
    if (!strcmp(argv[1], "mask") && argc == 4) {
        return isc_mask;
    }

    return isc_bad_input;
}

void xor_8(char *name_file, int *answer, file_troubles *status) {
    FILE *input_file = NULL;
    *status = ofp_well;

    if (!(input_file = fopen(name_file, "r"))) {
        *status = ofp_bad_open;
        return;
    }

    char one_byte = 0;

    while (fread(&one_byte, sizeof(char), sizeof(one_byte), input_file)) {
        *answer ^= one_byte;
    }

    fclose(input_file);


}


void xor_32(char *name_file, char *answer, file_troubles *status) {
    FILE *input_file = NULL;
    *status = ofp_well;

    if (!(input_file = fopen(name_file, "r"))) {
        *status = ofp_bad_open;
        return;
    }

    char buffer[4];
    size_t count_read = 0;

    while ((count_read = fread(buffer, sizeof(char), sizeof(buffer), input_file))) {
        if (4 != count_read) {
            for (size_t i = count_read; i < 4; ++i) {
                buffer[i] = 0;
            }
        }
        for (int i = 0; i < 4; ++i) {
            answer[i] ^= buffer[i];
        }
    }

    fclose(input_file);

}

void mask_func(char *file_name, int *counter, int *mask, file_troubles *status) {
    FILE *input_file = NULL;
    *status = ofp_well;
    if (!(input_file = fopen(file_name, "r"))) {
        *status = ofp_bad_open;
        return;
    }

    char buffer_4[4];
    int result = 0;

    size_t count_readed = 0;
    while ((count_readed = fread(buffer_4, sizeof(char), sizeof(buffer_4), input_file))) {
        if (count_readed < 4) {
            for (size_t i = count_readed; i < 4; ++i) {
                buffer_4[i] = 0;
            }
        }
        result += (int) buffer_4[0] * 16777216;//a_k_a 2**24 -> 0_byte
        result += (int) buffer_4[1] * 65536;//a_k_a 2**16 -> 1_byte
        result += (int) buffer_4[2] * 256;//a_k_a 2**8 -> 2_byte
        result += (int) buffer_4[3];//a_k_a 2**0 == 1 -> 3_byte
        if (result == *mask) {
            (*counter)++;
        }
        result = 0;

    }
}
