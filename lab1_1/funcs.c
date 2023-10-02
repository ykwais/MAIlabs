#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "enums.h"

bool is_number(char* str){
    char* result ;
    long number = strtol(str, &result, 10);

    if(*result != '\0'){
        return false;
    }

    return true;
}

long long string_to_int(char* argv){ //передаю указатель на первый эл-нт массива
    long long result = 0;
    int length_string = strlen(argv);
    if(argv[0] == '-'){
        for(int i = 1; i<length_string; i++){//собираю число
            result *= 10;
            result += argv[i] - '0';
        }
        result *= -1;
    }
    else{
        for(int i = 0; i<length_string; i++){//собираю число
            result *= 10;
            result += argv[i] - '0';
        }
    }

    return result;
}


void dividers(char* argv){
    int counter = 0;
    int divider = string_to_int(argv);
    printf("the numbers are multiples of this:\n");
    for(int i = divider; i < 101; i += divider){
        counter++;
        printf("%d ", i);
    }
    if(counter == 0){
        printf("There are no dividers.");
    }
}



void print_table(char* argv){
    int number = string_to_int(argv);
    for(int i = 0; i < 106; i++){
        printf("-");
    }
    printf("\n");
    while(number){
        long long tmp = number;
        for(int i = 1; i < 11; i++){
            if(i<5){
                printf("|%6llu ", tmp);
            }
            else{
                printf("| %10llu", tmp);
            }
            tmp *= number;
        }
        printf("|\n");
        for(int i = 0; i < 106; i++){
            printf("-");
        }
        printf("\n");
        number--;
    }
}



long long summ_way(char* arg){
    long long number = string_to_int(arg);
    long double answer = ((1+number)*0.5)*number;
    long long answ = answer;
    //printf("summ: %lld", answ);
    return answ;
}

enum input_status_code analysis(int argc, char** argv) {
    if(!is_number(argv[2])){
        return isc_invalid_parametr;
    }

    if (argc == 2 && (!strcmp(argv[1], "-help") || !strcmp(argv[1], "/help"))) {
        return isc_need_help;
    }
    if (argc > 3) {
        return isc_too_many_parameters;
    } else if (argc == 2) {
        return isc_therearent_number;
    } else if (atoi(argv[2]) == 0 && strlen(argv[2]) > 1) {
        return isc_invalid_parametr;
    } else if (argv[2][0] < 48 || argv[2][0] > 57) {
        return isc_invalid_parametr;
    } else if (argc == 3) {
        if ((!strcmp(argv[1], "-h") || !strcmp(argv[1], "/h")) && (strtol(argv[2], NULL, 10) != 0)) {
            return isc_h;
        } else if ((!strcmp(argv[1], "-p") || !strcmp(argv[1], "/p"))) {
            return isc_p;
        } else if ((!strcmp(argv[1], "-s") || !strcmp(argv[1], "/s"))) {
            return isc_s;
        } else if ((!strcmp(argv[1], "-e") || !strcmp(argv[1], "/e"))) {
            return isc_e;
        } else if ((!strcmp(argv[1], "-a") || !strcmp(argv[1], "/a"))) {
            return isc_a;
        } else if ((!strcmp(argv[1], "-f") || !strcmp(argv[1], "/f"))) {
            return isc_f;
        } else {
            return isc_invalid_parametr;
        }
    }
}


enum p_status_code is_comlete(char* argv){
    long long number = string_to_int(argv);
    if(number < 0){
        return psc_negative;
    }
    else if(number == 0){
        return psc_zero;
    }
    else if(number == 1){
        return psc_one;
    }

    else{
        int i = 2;
        int counter = 0;
        while(!counter && i <= sqrt(number)){
            if(number % i == 0){
                counter++;
            }
            if(i < 3){
                i++;
            }
            else{
                i += 2;
            }

        }
        if(counter != 0 ){
            return psc_complicated;
        }
    }
    return psc_simple;
}

enum s_status_code divided_string(char* arg, char* tmp){

    int length = strlen(arg);
    int counter = 0;
    int p = 0;
    int i = 0;
    if(arg[0] == '-'){
        tmp[0] = '-';
        tmp[1] = ' ';
        i++;
        p += 2;
    }
    while(i < length){
        if(!(arg[i] >= 48 && arg[i] <= 57 )){
            return ssc_bad_input;
        }
        if(arg[i] == '0' && !counter){
            i++;
            continue;
        }
        if(arg[i] != '0'){
            counter++;
            tmp[p] = arg[i];
            p++;
            tmp[p] = ' ';
            p++;
        }
        if(arg[i] == '0' && counter != 0){
            tmp[p] = arg[i];
            p++;
            tmp[p] = ' ';
            p++;
        }

        i++;
    }
    tmp[p] = '\0';
    return ssc_normal;


}

enum e_status_code is_print_table(char* argv){
    int number = string_to_int(argv);
    if(number > 10 || number < 1){
        return esc_inappropriate;
    }
    else{
        return esc_normal;
    }


}

enum a_status_code is_summ(char* arg){
    long long number = string_to_int(arg);
    if(number < 1){
        return asc_negative;
    }
    else{
        return asc_normal;
    }
}

enum factorial_status_codes factorial(unsigned int value, unsigned long long *result){

    enum factorial_status_codes recursive_status_code;

    if (value > 20)
    {
        return fsc_invalid_parameter;
    }

    if (value == 0 || value == 1)
    {
        *result = 1;
        return fsc_ok;
    }

    recursive_status_code = factorial(value - 1, result);
    if (recursive_status_code == fsc_ok)
    {
        *result *= value;
    }

    return recursive_status_code;
}
