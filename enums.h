//
// Created by fedor on 30.09.2023.
//

#ifndef LABORATORY1_2_ENUMS_H
#define LABORATORY1_2_ENUMS_H
enum input_status_code{
    isc_need_help,
    isc_invalid_parametr,
    isc_normal
};


enum input_status_code analysis(int argc, char** argv){
    if(argc == 2 && (!strcmp(argv[1], "-help") || !strcmp(argv[1],"/help") )){
        return isc_need_help;
    }
    else if(argc == 2 && is_number(argv[1]) && argv[1][0] >= 48 && argv[1][0] < 56 && argv[1][1] == '\0' ){
        return isc_normal;
    }
    else{
        return isc_invalid_parametr;
    }
}
#endif //LABORATORY1_2_ENUMS_H
