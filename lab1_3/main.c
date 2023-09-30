//
// Created by fedor on 26.09.2023.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "funcs.h"
#include "enums.h"


int main(int argc, char** argv){
    char* end;
    long double koefs[3];
    switch(analysis(argc, argv)){
        case isc_invalid_parametr:
            printf("You've inputed wrong parameters, please repeat or input -help");
            break;
        case isc_need_help:
            printf("-q the first parameter (real number) sets the accuracy of comparing real numbers (epsilon), the remaining three (real numbers) are the coefficients of the quadratic equation; it is necessary to output the solutions of this equation to the console with all possible unique permutations of the coefficient values for the degrees of the variable;\n"
                   "-m it is necessary to specify two non-zero integers, then determine whether the first number is a multiple of the second;\n"
                   "-t the first parameter (real number) sets the accuracy of comparing real numbers (epsilon); it is necessary to check whether the remaining three (real the numbers) of the parameter are the lengths of the sides of a right triangle.");
            break;
        case isc_q:
            //solution(0.000001, 4, 5, 0);
            switch (is_triple(argv)) {
                case qsc_three_zero:
                    printf("x - any");
                    break;
                case qsc_half_full:
                    koefs[0] = strtold(argv[3], &end);
                    koefs[1] = strtold(argv[4], &end);
                    koefs[2] = strtold(argv[5], &end);
                    not_full_cicle(strtold(argv[2], &end), koefs);
                    break;
                case qsc_full:
                    koefs[0] = strtold(argv[3], &end);
                    koefs[1] = strtold(argv[4], &end);
                    koefs[2] = strtold(argv[5], &end);
                    cicle_full(strtold(argv[2], &end), koefs);
                    reverse_massive_of_three(strtold(argv[2], &end), koefs);

                    break;
            }

            break;
        case isc_m:
            switch(is_divider(atol(argv[2]),atol( argv[3]))){
                case m_no:
                    printf("the first number is NOT a multiple of the second");
                    break;
                case m_yes:
                    printf("the first number is a multiple of the second");
                    break;
            }

            break;
        case isc_t:
            switch(is_triangle(argv)){
                case tsc_bad_input:
                    printf("bad input, too little parameters, please repeat");
                    break;
                case tsc_normal:
                    printf("well");
                    break;
                case tsc_soso:
                    printf("ne zataschil");
                    break;

            }

            break;
    }

}
