#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "enums.h"
#include "funcs.c"


int main(int argc, char **argv) {
    int answer = 0;
    char result[4] = {0, 0, 0, 0};
    int counter = 0;
    int mask = 0;
    file_troubles stat;

    switch (analysis(argc, argv)) {
        case isc_too_args:
            printf("You've inputted too many/little arguments");
            break;
        case isc_bad_input:
            printf("Bad input, sorry.");
            break;
        case isc_xor8:
            xor_8(argv[2], &answer, &stat);
            printf("answer for xor_2 = %d\n", answer);
            break;
        case isc_xor32:
            xor_32(argv[2], result, &stat);
            printf("answer for xor_32 : \n");
            for (int i = 0; i < 4; ++i) {
                printf("%d ", result[i]);
            }
            break;
        case isc_mask:
            mask = strtol(argv[3], NULL, 16);
            if (errno == EINVAL) {
                printf("wrong <hex>");
                return 0;
            }
            mask_func(argv[2], &counter, &mask, &stat);
            printf("\nresult of mask : %d\n", counter);
            break;
    }


}
