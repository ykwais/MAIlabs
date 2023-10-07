#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "enums.h"

#define MAX_LEN 65
#define SIZE 65

void skip_the_voids(FILE *file_name) {
    int ch;
    while ((ch = fgetc(file_name)) != EOF) {
        if (ch != 32 && ch != 9 && ch != 10) {
            ungetc(ch, file_name);
            break;
        }
    }
}

char *collect_a_lexemma(FILE *file_name) {
    char *lexemma = (char *) malloc(sizeof(char) * MAX_LEN);
    if (lexemma == NULL) {
        return NULL;
    }
    int ch;
    int length_lexemma = 0;
    while ((ch = fgetc(file_name)) != EOF) {
        if (ch == 10 || ch == 9 || ch == 32) {
            break;
        }
        if (length_lexemma < MAX_LEN) {
            lexemma[length_lexemma] = (char) ch;
            length_lexemma++;
        } else {

            return NULL;
        }
    }
    lexemma[length_lexemma] = '\0';
    return lexemma;
}

long long string_cc_to_10CC(int base, char *string) {
    char *ptr = string;
    long long result = 0;
    while (*ptr) {
        result = result * base + (isdigit(*ptr) ? *ptr - '0' : *ptr - 'A' + 10);
        ptr++;
    }


    return result;

}

void divided_string(char *arg, FILE *output) {
    char *tmp = (char *) malloc(sizeof(char) * strlen(arg));
    int length = strlen(arg);
    int counter = 0;
    int counter_2 = 0;
    int p = 0;
    int i = 0;
    if (arg[0] == '-') {
        tmp[0] = '-';
        i++;
        p++;
    }
    while (i < length) {
        if (arg[i] == '0' && !counter) {
            i++;
            counter_2++;
            continue;
        }
        if (arg[i] != '0') {
            counter++;
            tmp[p] = arg[i];
            p++;
        }
        if (arg[i] == '0' && counter != 0) {
            tmp[p] = arg[i];
            p++;
        }
        i++;
    }

    tmp[length - counter_2] = '\0';

    if (tmp[0] == '\0') {
        fprintf(output, "!0");
    } else {
        for (int i = 0; i < length - counter_2; i++) {
            fprintf(output, "%c", tmp[i]);
        }
    }


    fprintf(output, " ");
    free(tmp);
    tmp = NULL;
}

char *to_upper_text(char *string) {
    char *tmp = (char *) malloc(sizeof(char) * strlen(string));
    if (tmp == NULL) {
        return NULL;
    }
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        tmp[i] = toupper(string[i]);
    }
    tmp[length] = '\0';
    return tmp;
}

int min_cc(char *string) {
    int max = 1;
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (isdigit(string[i]) && string[i] - '0' >= max) {
            max = string[i] - '0';
        } else if (isupper(string[i]) && string[i] - 'A' + 10 >= max) {
            max = string[i] - 'A' + 10;
        } else {
            continue;
        }
    }

    return max + 1;

}


bool is_number(char *string) {

    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        int x = string[i];
        if (x < 48 || (x > 57 && x < 65) || (x > 90 && x < 97) || x > 122) {
            return false;
        }
    }
    return true;
}


void do_flag(FILE *input, FILE *output, enum flag_status_code *is_num) {
    skip_the_voids(input);
    while (!feof(input)) {
        char *lexemma = collect_a_lexemma(input);
        if (!is_number(lexemma)) {
            *is_num = not_a_number;
            break;
        }
        if (lexemma == NULL) {
            fprintf(output, "(too_long_string) ");
            free(lexemma);
            skip_the_voids(input);
            lexemma = NULL;
        } else {
            char *upper_lexemma = to_upper_text(lexemma);
            divided_string(upper_lexemma, output);
            //fprintf(output, "%s ", upper_lexemma);
            int minim_cc = min_cc(upper_lexemma);
            fprintf(output, "%d ", minim_cc);
            fprintf(output, "%lld\n", string_cc_to_10CC(minim_cc, upper_lexemma));

            free(lexemma);
            lexemma = NULL;
            free(upper_lexemma);
            upper_lexemma = NULL;
            skip_the_voids(input);
        }
    }
}

enum flag_status_code can_flag(char *input_file_name, char *output_file_name) {
    FILE *output_file = fopen(output_file_name, "w");
    FILE *input_file = fopen(input_file_name, "r");

    if (!output_file || !input_file) {
        return file_open_problem;
    } else {
        enum flag_status_code is_num;
        do_flag(input_file, output_file, &is_num);
        if (is_num == not_a_number) {
            return not_a_number;
        }
        fclose(input_file);

        fclose(output_file);
        output_file = NULL, input_file = NULL;
        return well;
    }
}

enum input_status_code analysis(int argc, char** argv){
    if(argc < 2 || argc > 4){
        return isc_little_argc;
    }

    else{
        return isc_well;
    }
}