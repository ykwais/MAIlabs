#include <stdio.h>

#include "enums.h"
#include "functions.c"




int main(int argc, char** argv){

    work_with_mass();


    switch (analysis(argc, argv)){
        case isc_need_help:
            printf("You must give this program a one number - accuracy of calculation of numbers.");
            break;
        case isc_normal:
            printf("Exp:\n");
            printf("exp by limit: %.10Lf\n", limit_e(argv[1]));
            printf("exp by Tailor: %.10Lf\n", tailor_e(argv[1]));
            printf("exp by equation: %.10Lf\n", dich_e(argv[1]));
            printf("\nPI:\n");
            printf("PI by limit: %.10Lf\n", limit_pi(argv[1]));
            printf("PI by Tailor: %.10Lf\n", tailor_pi(argv[1]));
            printf("PI by equation: %.10Lf\n", dich_pi(argv[1]));
            printf("\nln2:\n");
            printf("ln2 by limit: %.10Lf\n", limit_ln_2(argv[1]));
            printf("ln2 by Tailor: %.10Lf\n", tailor_ln(argv[1]));
            printf("ln2 by equation: %.10Lf\n", dich_ln_2(argv[1]));
            printf("\nsqrt2:\n");
            printf("sqrt2 by limit: %.10Lf\n", limit_sqrt_2(argv[1]));
            printf("sqrt2 by Tailor: %.10Lf\n", prouzvedenie_sqrt_2(argv[1]));
            printf("sqrt2 by equation: %.10Lf\n", dich_sqrt_2(argv[1]));
            printf("\ngamma:\n");
            printf("gamma by limit: %.10Lf\n", limit_g(argv[1]));
            printf("gamma by row: %.10Lf\n", tailor_g(argv[1]));
            limit_last(argv[1]);
            printf("gamma by equation: %.10Lf\n", dich_last(argv[1]));
            break;
        case isc_invalid_parametr:
            printf("You've input wrong number! Repeat please. number must be natural >= 0 and <8");
            break;
    }

}
