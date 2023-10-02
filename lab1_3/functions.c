
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "enums.h"

bool is_number(char* str){
    char* result ;
    long double number = strtold(str, &result);
    if(*result != '\0'){
        return false;
    }
    return true;
}

enum input_status_code analysis(int argc, char** argv){
    if(argc == 2 && (!strcmp(argv[1], "-help") || !strcmp(argv[1],"/help") )){
        return isc_need_help;
    }
    else if(argc == 6 && (!strcmp(argv[1], "-q") || !strcmp(argv[1],"/q") ) && is_number(argv[2]) && is_number(argv[3]) && is_number(argv[4]) && is_number(argv[5])){
        return isc_q;
    }
    else if(argc == 4 && (!strcmp(argv[1], "-m") || !strcmp(argv[1],"/m") ) && is_number(argv[2]) && is_number(argv[3])){
        return isc_m;
    }
    else if(argc == 6 && (!strcmp(argv[1], "-t") || !strcmp(argv[1],"/t") ) && is_number(argv[2]) && is_number(argv[3]) && is_number(argv[4]) && is_number(argv[5]) ){
        return isc_t;
    }
    else{
        return isc_invalid_parametr;
    }
}

enum m_status_code is_divider(long long first_number, long long second_number){
    if(first_number % second_number == 0){
        return m_yes;
    }
    else return m_no;
}

enum t_status_code is_triangle(char** argv){
    char* end;
    long double eps = strtold(argv[2], &end);
    long double a = strtold(argv[3], &end);
    long double b = strtold(argv[4], &end);
    long double c = strtold(argv[5], &end);
    if( eps < 0 || a < 0 || b < 0 || c < 0 || fabsf(a) < eps || fabsl(b) < eps || fabsl(c) < eps){
        return tsc_bad_input;
    }
    else if( c-a-b <= 0 && b-c-a <= 0 && a-b-c <= 0 && (fabsl(c*c - a*a - b*b) <= eps || fabsl(a*a - b*b - c*c) <= eps || fabsl(b*b - a*a - c*c) <= eps) ){
        return tsc_normal;
    }
    else{
        return tsc_soso;
    }

}

enum q_status_code is_triple(char** argv){
    char* end;
    long double eps = strtold(argv[2], &end);
    long double a = strtold(argv[3], &end);
    long double b = strtold(argv[4], &end);
    long double c = strtold(argv[5], &end);
    if((fabsl(a) <= eps && fabsl(b) <= eps && fabsl(c) <= eps)){
        return qsc_three_zero;
    }
    else if(fabsl(a-b)<=eps || fabsl(a-c) <= eps || fabsl(b-c) <= eps){
        return qsc_half_full;
    }
    else{
        return qsc_full;
    }
}


void solution(long double eps, long double a, long double b, long double c){
    long double sol_1, sol_2;
    long double descrimenant = b*b - 4*a*c;
    if(descrimenant < eps){
        printf("if parametres are %Lf, %Lf, %Lf then there aren't solution\n");
    }
    else if(fabsl(a) <= eps && (fabsl(b) > eps) && (fabsl(c) > eps)){
        sol_1 = -c/b;
        printf("if parametres are %Lf, %Lf, %Lf then solution is x1 = %Lf \n", a,b,c,sol_1);
    }
    else if(fabsl(a) <= eps && fabsl(c) <= eps && fabsl(b) > eps){
        sol_1 = 0;
        sol_2 = 0;
        printf("if parametres are %Lf, %Lf, %Lf then solution is x1 = %Lf and x2 = %Lf\n", a,b,c,sol_1, sol_2);
    }
    else if(fabsl(b) <= eps && fabsl(c) > eps && fabsl(a) > eps){
        sol_1 = -(sqrtl(c/a));
        sol_2 = sqrtl(c/a);
        printf("if parametres are %Lf, %Lf, %Lf then solution is x1 = %Lf and x2 = %Lf\n", a,b,c,sol_1, sol_2);
    }
    else if(fabsl(c) <= eps && fabsl(a) > eps && fabsl(b) > eps){
        sol_1 = 0;
        sol_2 = -b/a;
        printf("if parametres are %Lf, %Lf, %Lf then solution is x1 = %Lf and x2 = %Lf\n", a,b,c,sol_1, sol_2);

    }
    else{
        sol_1 = ((-1)*b+sqrtl(descrimenant))/(2*a);
        sol_2 = ((-1)*b-sqrtl(descrimenant))/(2*a);
        printf("if parametres are %Lf, %Lf, %Lf then solution is x1 = %Lf and x2 = %Lf\n", a,b,c,sol_1, sol_2);
    }

}

void cicle_full(long double epsilon, long double* mass){
    long double stop = mass[0];
    long double tmp;
    do{
        tmp = mass[1];
        mass[1] = mass[0];
        mass[0] = mass[2];
        mass[2] = tmp;
        solution(epsilon, mass[0], mass[1], mass[2]);
    } while (fabsl(mass[0] - stop) > epsilon);
}

void reverse_massive_of_three(long double epsilon, long double* mass){
    long double tmp = mass[0];
    mass[0] = mass[2];
    mass[2] = tmp;
    cicle_full(epsilon, mass);
}

void not_full_cicle(long double epsilon, long double* mass){
    int counter = 0;
    for(int i = 1; i<3; i++){
        if(fabsl(mass[i]-mass[i-1]) <= epsilon){
            counter++;
        }
    }
    while(counter == 1){
        long double tmp = mass[2];
        mass[2] = mass[1];
        mass[1] = mass[0];
        mass[0] = tmp;
        counter = 0;
        for(int i = 1; i<3; i++){
            if(fabsl(mass[i]-mass[i-1]) <= epsilon){
                counter++;
            }
        }
    }

    if(counter == 0){
        long double stop = mass[1];
        long double tmp;
        do{
            tmp = mass[1];
            mass[1] = mass[0];
            mass[0] = mass[2];
            mass[2] = tmp;
            solution(epsilon, mass[0], mass[1], mass[2]);
        } while (fabsl(mass[1] - stop) > epsilon);

    }


}
