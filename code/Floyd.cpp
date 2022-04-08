#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

void printArr(int arr[5][5]);

int INF = INT_MAX / 2;

int main(){
    int arr[5][5] ={
        {0,4,2,5,INF},
        {INF,0,1,INF,4},
        {1,3,0,1,2,},
        {-2,INF,INF,0,2},
        {INF,-3,3,1,0}
    };

    printArr(arr);
    printf("\n");

    int n = 5;

    for(int k=0;k<n;k++){
        printf("%d th iter\n",k+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
        printArr(arr);
    }
}

void printArr(int arr[5][5]){
    for(int i=0;i<5;i++){
        printf("\n");
        for(int j=0;j<5;j++){
            if(arr[i][j] >= INF/2){
                printf("¡Ú\t");
            }else{
                printf("%d\t", arr[i][j]);
            }
        }
    }
    printf("\n\n");
}