//
// Created by fedor on 24.09.2023.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "enums.h"





int main(int argc, char** argv){
    int length;
    unsigned long long factorial_result;
    switch(analysis(argc, argv)){
        case isc_invalid_parametr:
            printf("invalid");
            break;
        case isc_need_help:
            printf("-h output to the console natural numbers within 100 inclusive, multiples of the specified.\n-p determine whether the entered number is simple; is it composite.\n-s divide the number into separate digits and output each digit of the number separately,\n"
                   "separating them with a space, from the highest digits to the lowest, without leading zeros in the string representation\n"
                   "-e output a table of degrees (for all indicators in the range from 1 to a given number) of bases from 1 to 10; for this flag, the limit on the entered number works: it should be no more than 10;\n-a calculate the sum of all natural numbers from 1 to the specified number inclusive and output the resulting value to the console;\n-f calculate the factorial of the specified number and output the resulting value to the"
                   "console");
            break;
        case isc_therearent_number:
            printf("Where is the number?");
            break;
        case isc_too_many_parameters:
            printf("You input too many parameters, repeat please");
            break;
        case isc_h:
            dividers(argv[2]);
            //printf("!!! %c", argv[2][1]);
            break;
        case isc_p:
            switch (is_comlete(argv[2])) {
                case psc_negative:
                    printf("You've entered the negative number, please repeat.");
                    break;
                case psc_zero:
                    printf("You've entered 0, please repeat.");
                    break;
                case psc_complicated:
                    printf("You've entered the complicated number.");
                    break;
                case psc_simple:
                    printf("You've entered the simple number.");
                    break;
            }
            break;
        case isc_s:

            length = strlen(argv[2]);
            char* result = malloc(sizeof(char)*2*length);
            switch (divided_string(argv[2], result)) {
                case ssc_normal:
                    printf("the need string: %s", result);
                    break;
                case ssc_bad_input:
                    printf("Check your input ");
                    break;
            }
            free(result);
            break;
        case isc_e:
            switch(is_print_table(argv[2])){
                case esc_normal:
                    print_table(argv[2]);
                    break;
                case esc_inappropriate:
                    printf("invalid number, please repeat.");
            }
            break;
        case isc_a:
            switch(is_summ(argv[2])){
                case asc_normal:
                    summ_way(argv[2]);
                    break;
                case asc_negative:
                    printf("negative number, please repeat.");
            }
            break;
        case isc_f:

            switch (factorial(string_to_int(argv[2]), &factorial_result))
            {
                case fsc_ok:
                    printf("%u! = %llu\n", string_to_int(argv[2]), factorial_result);
                    break;

                case fsc_invalid_parameter:
                    printf("Invalid parameter detected!!1!1");
                    break;
            }

            break;

    }


}
