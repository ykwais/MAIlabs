//
// Created by fedor on 30.09.2023.
//

#ifndef LABORATORY1_2_FUNCS_H
#define LABORATORY1_2_FUNCS_H

#define NUM  50000
#define NUM_2  5200

long double fast_pow (long double x, long long y) {
    long double result = 1.0L;
    while(y){
        if(y & 1){
            result *= x;
        }
        x *= x;
        y = y >> 1;
    }
    return result;
}

bool is_number(char* str){
    char* result ;
    long number = strtol(str, &result, 10);

    if(*result != '\0'){
        return false;
    }

    return true;
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%% EXP %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

long double limit_e(char* str) {
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long long n = 2;
    long double drob = 1.0L/n;
    while (drob > srav){ //достаточно сравнить лишь дробь с точностью - без возведения в степень, как в первой рализации. просран час.
        n++;
        drob = 1.0L/n;
    }
    long double answer = fast_pow((1.0L + 1.0L/n), n);
    return answer;
}

long double tailor_e(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long long n = 1;
    long long fact = 1;
    long double row_summ = 0L;
    while(1.0L/fact > srav){
        row_summ += 1.0L/fact;
        n++;
        fact *= n;
    }
    return 1.0L + row_summ;
}

long double func_e(long double x){
    return log(x) - 1.0L;
}

long double dich_e(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long double left = 2.0L, right = 3.0L;
    long double answer;
    long double middle;
    do{
        middle = (left + right) / 2;
        answer = func_e(middle);
        if(answer < 0L){ //это не сравнение! это проверка на отрицательность!!!!
            left = middle;
        }
        else{
            right = middle;
        }
    } while (fabsl(left - right) > srav);
//while (fabsl(func_e(middle)) > srav)
    return middle;

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% PI %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

long double limit_pi(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+9));//3,1415926535
    long long n = 1;
    long double pi = 1.0L;
    long double multiplayer = 4.0L;
    while(fabsl(pi - multiplayer) > srav){
        pi = multiplayer;

        multiplayer *= (4.0L*n*n + 4*n) / ((2.0L*n + 1)*(2.0L*n + 1));//32/9
        n++;

    }
    return pi;
}

long double tailor_pi(char* str){//0,693147180
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long double answer = -1.0L;
    long long n = 1;
    long double summ = -1.0L;
    long double chislitel = 1.0L;
    while(fabsl(summ) > srav){
        n++;
        summ = chislitel/(2.0L*n - 1);
        answer += summ;
        chislitel = -chislitel;
    }
    return -4.0L*answer;
}

long double func_pi(long double x){
    return cosl(x) + 1.0L;
}

long double d_func_pi(long double x){
    return -sinl(x);
}

long double cur_func(long double x){
    return func_pi(x)/ d_func_pi(x);
}

long double dich_pi(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));

    long double x_1 = 3.5L;
    long double x_2 = x_1 - cur_func(x_1);

    while(fabsl(x_2 - x_1) > srav){
        x_1 = x_2;
        x_2 = x_1 - cur_func(x_1);
    }

    return x_1;


}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%%%%%% LN2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

long double limit_ln_2(char* str){//0,69314718056
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+12));

    long long n = 1;
    long double ln_2 = 2.0L;
    long double multiplayer = 1.0L;
    while(fabsl(ln_2 - multiplayer) > srav){
        ln_2 = multiplayer;
        n++;
        multiplayer = n * (powl(2.0L, (1.0L/n)) - 1);

    }
    return ln_2;
}

long double tailor_ln(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));

    long double answer = 1.0L;
    long long n = 1;
    long double summ = 1.0L;
    long double chislitel = -1.0L;
    while(fabsl(summ) > srav){
        n++;
        summ = chislitel/n;
        answer += summ;
        chislitel = -chislitel;
    }
    return answer;
}

long double func_ln_2(long double x){
    return expl(x) - 2.0L;
}

long double dich_ln_2(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long double left = 0.5L, right = 1.0L;
    long double answer;
    long double middle;
    do{
        middle = (left + right) / 2;
        answer = func_ln_2(middle);
        if(answer < 0L){ //это не сравнение! это проверка на отрицательность!!!!
            left = middle;
        }
        else{
            right = middle;
        }
    } while (fabsl(left - right) > srav);
//while (fabsl(func_e(middle)) > srav)
    return middle;

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SQRT(2) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

long double limit_sqrt_2(char* str){//1,41421356237
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));

    long double x_1 = 0L;
    long double x_2 = -0.5L;

    while(fabsl(x_2 - x_1) > srav){
        x_1 = x_2;
        x_2 = x_1 - (x_1*x_1/2) +1;
    }

    return x_1;

}

long double prouzvedenie_sqrt_2(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+2));
    long double answer = powl(2, 1/4);

    long double degree = 1.0L/(4.0L);
    while(degree > srav){
        answer *= powl(2, degree);
        degree *= 0.5L ;
    }

    return answer;


}

long double func_sqrt_2(long double x){
    return x*x - 2.0L;
}

long double dich_sqrt_2(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long double left = 1.0L, right = 2.0L;
    long double answer;
    long double middle;
    do{
        middle = (left + right) / 2;
        answer = func_sqrt_2(middle);
        if(answer < 0L){ //это не сравнение! это проверка на отрицательность!!!!
            left = middle;
        }
        else{
            right = middle;
        }
    } while (fabsl(left - right) > srav);
//while (fabsl(func_e(middle)) > srav)
    return middle;

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% GAMMA %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

long double limit_g(char* str){//0,57721566490153286060
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long double answer = 0L;
    long long n = 1;
    long double drob = 1.0L;
    while(drob > srav){
        n++;
        answer += drob;
        drob = 1.0L/n;
    }
    return answer - logl(n);
}

long double tailor_g(char* str){
    long long koefs[8000];
    for(int i = 0; i < 8000; i++){
        koefs[i] = i*i;
    }

    long double pi = acos(-1);
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+105));
    long long k = 2;
    int n = 2;
    long double first_drob = 1.0L;
    long double second_drob = 0.5L;
    long double answer = 0.0L;

    while(fabsl(first_drob - second_drob) > srav){
        if(k==koefs[n]){
            k++;
            n++;
        }
        first_drob = powl(floorl(sqrtl(k)),-2);
        second_drob = 1.0L/k;
        answer += first_drob;
        answer -=  second_drob;
        k++;
    }
    return answer - ((pi*pi)/6.0L) ;
}

long long numbers[NUM];
long double simple[NUM_2];

void erato(long long* mass){
    for(long long i = 2; i <= NUM; i++){
        if(mass[i] > 0){
            continue;
        }
        for(long long j = 2; i*j <= NUM; j++){
            mass[i*j] = 1;
        }
    }
}

void work_with_mass(){
    for(int i = 0; i < NUM; i++){
        numbers[i] = 0;
    }
    for(int i = 0; i < NUM_2; i++){
        simple[i] = 0.0L;
    }
    erato(numbers);
    int n = 0;
    for(int i = 0; i < NUM; i++){
        if(numbers[i] == 0){
            simple[n] = i;
            n++;
        }
    }

//    for(int i = 0; i < NUM_2; i++){
//        printf("%Lf  ", simple[i]);
//    }
}

long double limit;

void limit_last(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+1));
    long long t = 2;

    long double answer = 1.0L;
    long double first_drob = 0.0L;
    long double second_drob = 1.0L;
    while(fabsl(first_drob - second_drob) > srav){
        second_drob = first_drob;
        first_drob =  (simple[t] - 1.0L)/(simple[t]);
        answer *= first_drob;
        t++;
    }
    limit = answer*logl(simple[t]);
//    return answer*logl(simple[t]);


}



long double func_last(long double x){
    return expl(-x) - limit;
}

long double d_func_last(long double x){
    return -expl(-x);
}

long double cur_func_last(long double x){
    return func_last(x)/ d_func_last(x);
}

long double dich_last(char* str){
    char *result;
    long long number = strtol(str, &result, 10);
    long double srav = powl(10.0L, (-1)*(number+100));

    long double x_1 = 0.5L;
    long double x_2 = x_1 - cur_func_last(x_1);

    while(fabsl(x_2 - x_1) > srav){
        x_1 = x_2;
        x_2 = x_1 - cur_func_last(x_1);
    }

    return x_1;


}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




#endif //LABORATORY1_2_FUNCS_H
