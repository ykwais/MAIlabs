#include <stdio.h>
#include "enum.h"
#include "functions.c"



int main(int argc, char** argv) {
    switch (analysis(argc, argv)) {
        case isc_bad_input:
            printf("You've entered the wrong flag!");
            break;
        case isc_d:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    without_arabic_normal_mode(argv[2]);
                    printf("everything is done, master");
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_i:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    counter_latin_normal_mode(argv[2]);
                    printf("everything is done, master");
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_s:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    counter_not_latin_normal_mode(argv[2]);
                    printf("everything is done, master");
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_a:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    liters_to_16CC_normal_mode(argv[2]);
                    printf("everything is done, master");
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_nd:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    switch (enum_is_open_file_write(argv[3])) {
                        case iofw_yes:
                            without_arabic_n_mode(argv[2], argv[3]);
                            printf("everything is done, master");
                            break;
                        case iofw_not:
                            printf("problems opening the output file");
                            break;

                    }
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_ni:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    switch (enum_is_open_file_write(argv[3])) {
                        case iofw_yes:
                            counter_latin_n_mode(argv[2], argv[3]);
                            printf("everything is done, master");
                            break;
                        case iofw_not:
                            printf("problems opening the output file");
                            break;

                    }
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_ns:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    switch (enum_is_open_file_write(argv[3])) {
                        case iofw_yes:
                            counter_not_latin_n_mode(argv[2], argv[3]);
                            printf("everything is done, master");
                            break;
                        case iofw_not:
                            printf("problems opening the output file");
                            break;

                    }
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
        case isc_na:
            switch (enum_is_open_file_read(argv[2])) {
                case iofr_yes:
                    switch (enum_is_open_file_write(argv[3])) {
                        case iofw_yes:
                            liters_to_16CC_n_mode(argv[2], argv[3]);
                            printf("everything is done, master");
                            break;
                        case iofw_not:
                            printf("problems opening the output file");
                            break;

                    }
                    break;
                case iofr_not:
                    printf("problems opening the input file!");
                    break;
            }
            break;
    }


}
