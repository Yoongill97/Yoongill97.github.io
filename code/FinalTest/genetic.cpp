#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 100
#define INF 100000
#define mutation 10       //돌연변이 확률은 1/mutation

typedef struct value
{
    int x;
    int y;
}value;

value* function(value* arr);

int main(){
    srand(time(NULL));

    value* arr = (value*)malloc(sizeof(value) * POPULATION_SIZE);
    value* result = (value*)malloc(sizeof(value) * POPULATION_SIZE);
    

    for(int i=0; i<POPULATION_SIZE; i++){
        arr[i].x = rand() % 10000;
        arr[i].y = rand() % 10000;
    }
    for(int i=0; i<POPULATION_SIZE; i++){
        printf("X : %4d\t Y : %4d\n", arr[i].x, arr[i].y);
    }printf("\n\n");

    result = function(arr);

    for(int k=0; k<3; k++){
        for(int i=0; i<100; i++){
            value * temp = (value*)malloc(sizeof(value) * POPULATION_SIZE);
            temp = result;
            result = function(temp);
            free(temp);
        }
        printf("*******************************\n");
        for(int i=0; i<POPULATION_SIZE; i++){
            printf("X : %4d\tY : %4d\n", result[i].x, result[i].y);
        }printf("\n\n");
    }
    return 0;
}

value* function(value arr[POPULATION_SIZE]){
    value* result = (value*)malloc(sizeof(value) * POPULATION_SIZE);
    double fit[POPULATION_SIZE];   //(C_worst - C_i) + (C_worst - C_Best) / (k - 1)
    int worst = 0, best = INF;
    double sum = 0;
    int num;
    double point;

    /***적합도 판별***/
    
    for(int i=0; i<POPULATION_SIZE; i++){
        if(abs(2 * arr[i].x + 1 - arr[i].y) > worst) worst = abs(2 * arr[i].x + 1 - arr[i].y);
        if(abs(2 * arr[i].x + 1 - arr[i].y) < best) best = abs(2 * arr[i].x + 1 - arr[i].y);
        //printf("arr[%d].x : %d\tarr[%d].y : %d\n", i, arr[i].x, i, arr[i].y);
        //printf("abs() : %d\n", abs(2 * arr[i].x + 1 - arr[i].y));
    }
    for(int i=0; i<POPULATION_SIZE; i++){
        fit[i] = (worst - abs(2 * arr[i].x + 1 - arr[i].y) + (worst - best) / 2);
        sum += fit[i];
    }

    for(int k=0; k<POPULATION_SIZE; k++){
        /***첫번째 고르기***/
        double per = 0;
        value first, second;
        int sumoffit = sum;

        point = (double)rand()/RAND_MAX;
        for(int i=0; i<POPULATION_SIZE; i++){
            per += (double)fit[i]/sumoffit;
            if(point < per){
                first = arr[i];
                sumoffit -= fit[i];
                num = i;
                break;
            }
        }
        /***두번째 고르기***/
        per = 0;
        point = (double)rand()/RAND_MAX;
        for(int i=0; i<POPULATION_SIZE; i++){
            if(i == num) continue;
            per += (double)fit[i]/sumoffit;
            if(point < per){
                second = arr[i];
                break;
            }
        }

        /***교배***/
        value son;
        int type = rand() % 4;
        son.x = first.x;
        son.y = second.y;
        if(rand() % mutation == 0){
            if(type == 0) son.x *= 2;
            else if(type == 1) son.y *= 2;
            else if(type == 2) son.x /= 2;
            else son.y /= 2;
        }
        result[k] = son;
    }
    return result;
}