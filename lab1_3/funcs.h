//
// Created by fedor on 28.09.2023.
//

#ifndef LABORATORY1_3_FUNCS_H
#define LABORATORY1_3_FUNCS_H
bool is_number(char* str){
    char* result ;
    long double number = strtold(str, &result);
    if(*result != '\0'){
        return false;
    }
    return true;
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

#endif //LABORATORY1_3_FUNCS_H
