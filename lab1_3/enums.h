//
// Created by fedor on 28.09.2023.
//

#ifndef LABORATORY1_3_ENUMS_H
#define LABORATORY1_3_ENUMS_H
enum input_status_code{
    isc_need_help,
    isc_invalid_parametr,
    isc_q,
    isc_m,
    isc_t
};


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





enum m_status_code{
    m_yes,
    m_no
};

enum m_status_code is_divider(long long first_number, long long second_number){
    if(first_number % second_number == 0){
        return m_yes;
    }
    else return m_no;
}

enum t_status_code{
    tsc_normal,
    tsc_bad_input,
    tsc_soso
};

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

enum q_status_code {
    qsc_three_zero,
    qsc_full,
    qsc_half_full
};

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


#endif //LABORATORY1_3_ENUMS_H
