#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "enums.h"
#include "funcs.c"


int main(int argc, char** argv) {
    switch (analysis(argc, argv)) {
        case isc_well:
            switch(can_flag(argv[2], argv[3])){
                case well:
                    printf("done, master");
                    break;
                case file_open_problem:
                    printf("error: problem file opening");
                    break;
                case not_a_number:
                    printf("wrong numbers!");
                    break;
            }
            break;
        case isc_little_argc:
            printf("Little/many arguments");
            break;

    }


}
