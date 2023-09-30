//
// Created by fedor on 24.09.2023.
//

#ifndef LABORATORY1_1_FUNCTIONS_H
#define LABORATORY1_1_FUNCTIONS_H
long long string_to_int(char* argv){ //передаю указатель на первый эл-нт массива
    long long result = 0;
    int length_string = strlen(argv);
    if(argv[0] == '-'){
        for(int i = 1; i<length_string; i++){//собираю число
            result *= 10;
            result += argv[i] - 48;
        }
        result *= -1;
    }
    else{
        for(int i = 0; i<length_string; i++){//собираю число
            result *= 10;
            result += argv[i] - 48;
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
        printf("There are not dividers.");
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
    printf("summ: %lld", answ);
}


#endif //LABORATORY1_1_FUNCTIONS_H
